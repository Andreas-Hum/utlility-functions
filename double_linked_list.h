/*
*
* Created by Andreas Svanberg Hummelmose, student at AAU
*
* Updated: 11-10-2022
*/

/* TODO optimiser alle methods og lav free methods for KVD */

#pragma warn -rvl /* return value */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
/* Redefining some logical operators for better readability*/

#define OR ||
#define AND &&
#define NOT !
#define NOT_EQUAL !=
#define IS ==

typedef struct double_linked_list{
        double data;
        struct double_linked_list *next;
} double_linked_list;


/* Creating new linked lists  */

double_linked_list *DLL_create_node(double data);
double_linked_list *DLL_array_to_list(double  array[],int size);
double_linked_list *DLL_concat(double_linked_list* list_one_root, double_linked_list* list_two_root);
double_linked_list *DLL_filter(double_linked_list* root, int (*f)(double x));
double_linked_list *DLL_fill(double_linked_list* root, int length,double value,double new_list);
double_linked_list *DLL_map(double_linked_list* root, double (*f)(double x));
double_linked_list *DLL_cpy(double_linked_list* root);
double_linked_list *DLL_cpy_within(double_linked_list* root, int left, int right);
double_linked_list *DLL_slice(double_linked_list* root, int left, int right);
double_linked_list *DLL_splice(double_linked_list** root, int start, int delete_count, double_linked_list* add_remove,int remove);

/* freeing memory */

void DLL_free(double_linked_list** root);
void DLL_free_node(double_linked_list** root, double_linked_list* node);

/* Mutating list */

double DLL_pop(double_linked_list** root);
double DLL_remove_index(double_linked_list** root, int index);
double DLL_shift(double_linked_list** root);
void DLL_change_element(double_linked_list** root, int index, double  new_data);
void DLL_flip(double_linked_list** root);
void DLL_push(double_linked_list** root, double data);
void DLL_push_node(double_linked_list** root, double_linked_list* node);
void DLL_unshift(double_linked_list** root,double  data);
void DLL_unshift_node(double_linked_list** root, double_linked_list* node);
void DLL_insert_at(double_linked_list** root, int index, double  new_data);
void DLL_insert_node_at(double_linked_list** root, int index, double_linked_list* new_data);
// void *DLL_remove_duplicates(double_linked_list** root);

/* Utility functions */

int DLL_length(double_linked_list* root);
int DLL_every(double_linked_list* root, int (*f)(double x));
int DLL_find_index(double_linked_list* root, int (*f)(double x));
int DLL_find_index_by_value(double_linked_list* root, int value);
int DLL_find_last_index(double_linked_list* root, int (*f)(double x));
int DLL_includes(double_linked_list* root, double value);
int DLL_some(double_linked_list* root, int (*f)(double x));
double DLL_foldr(double_linked_list* root,  double (*f)(double x, double y), double  start_value);
double DLL_foldl(double_linked_list* root,  double (*f)(double x, double y),double start_value);
double DLL_find(double_linked_list* root, int (*f)(double x));
double DLL_find_last(double_linked_list* root, int (*f)(double x));
double DLL_at(double_linked_list* root, int index);
double DLL_for_each(double_linked_list* root, double (*f)(double x, double y));
double *DLL_to_array(double_linked_list* root);
void DLL_print(double_linked_list* root);
void DLL_sort(double_linked_list** root);

int cpy_func (double i);
void double_mergeSort(double arr[], int l, int r);
void double_merge(double arr[], int l, int m, int r);



/* Creates a node */
double_linked_list *DLL_create_node(double data){

        double_linked_list* node = (double_linked_list*)malloc(sizeof(double_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

/* Type double array to type double linked list */
double_linked_list *DLL_array_to_list(double  array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return DLL_create_node(0);
        }


        double_linked_list *root = DLL_create_node(array[0]);

       for(int i = 1; i < size;i++){
                DLL_push(&root,array[i]);
       }

        return root;
}
/* Concats two type double linked lists */
double_linked_list *DLL_concat(double_linked_list* list_one_root, double_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = DLL_length(list_one_root)+DLL_length(list_two_root);

        double_linked_list* concatinated_tree = DLL_cpy(list_one_root);
        double_linked_list* cur = concatinated_tree;

        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = DLL_cpy(list_two_root);

        return concatinated_tree;

}

double_linked_list *DLL_filter(double_linked_list* root, int (*f)(double x)){

        if(root IS NULL){
                return root;
        }

        int once = 0;

        double_linked_list* filtered_array;
        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = DLL_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        DLL_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

double_linked_list *DLL_fill(double_linked_list* root, int length,double value,double new_list){
        if(!new_list){
                int dll_length = DLL_length(root);
                double_linked_list* cur = root;
                if(dll_length < length){
                        for(int i = 0; i < dll_length; i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = dll_length; i < length ; i++)
                        {
                                DLL_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = DLL_create_node(value);
                for (int i = 1; i < length; i++){
                        DLL_push(&root,value);
                }
        }

        return root;
}

double_linked_list *DLL_map(double_linked_list* root, double (*f)(double x)){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        double_linked_list* filtered_array;
        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(once IS 0){
                        filtered_array = DLL_create_node(f(cur->data));
                        once = 1;
                } else if(once IS 1){
                        DLL_push(&filtered_array,f(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

double_linked_list *DLL_cpy(double_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return DLL_filter(root,cpy_func);
}

double_linked_list *DLL_cpy_within(double_linked_list* root, int left, int right){
        if(root IS NULL){
                return DLL_create_node(-1);
        }

        if(left > right){
                return DLL_create_node(-1);
        } else if (right > DLL_length(root)){
                return DLL_create_node(-1);
        } else if(left < 0 OR right < 0){
                return DLL_create_node(-1);
        }

        double_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = DLL_create_node(DLL_at(root,i));
                        once = 1;
                } else {
                        DLL_push(&copied,DLL_at(root,i));
                }
        }

        return copied;
}

double_linked_list *DLL_slice(double_linked_list* root, int left, int right){

        if(root IS NULL){
                return DLL_create_node(-2);
        }


        if(left > right){
                return DLL_create_node(-1);
        } else if (right > DLL_length(root)){
                return DLL_create_node(-1);
        } else if(left < 0 OR right < 0){
                return DLL_create_node(-1);
        }

        double_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = DLL_create_node(DLL_at(root,i));
                        once = 1;
                } else {
                        DLL_push(&sliced,DLL_at(root,i));
                }
        }

        return sliced;
}

double_linked_list *DLL_splice(double_linked_list** root, int start, int delete_count, double_linked_list* add_remove,int remove){

        double_linked_list* cur = *root;
        double_linked_list* deleted;
        int length = DLL_length(*root);

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return DLL_create_node(-1);
        } else if(delete_count > length){
                return DLL_create_node(-1);
        }



        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                                deleted = DLL_create_node(DLL_at(*root,start));
                                DLL_remove_index(root,start);
                                once = 1;
                        } else {
                                DLL_push(&deleted,DLL_at(*root,start));
                                DLL_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < length; i++){
                                DLL_insert_at(root,start,DLL_at(add_remove,i));
                                start++;
                        }
                }

                return deleted;

        } else {
                for(int i = 0; i < length; i++){
                        DLL_insert_at(root,start,DLL_at(add_remove,i));
                        start++;
                }
                return DLL_create_node(0);
        }


}



double DLL_pop(double_linked_list** root){

        if(*root IS NULL){
                return -2;
        }

        double  value;
        double_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        DLL_free_node(root,cur);

        return value;

}

double DLL_remove_index(double_linked_list** root, int index){
        if(root IS NULL){
                return -2;
        }

        if(index IS 0 OR index > DLL_length(*root)){
                return -1;
        }

        double_linked_list* cur = *root;
        *root = cur;

        int value;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        DLL_free_node(root,cur);

        return (value);

}

double DLL_shift(double_linked_list** root){

        DLL_flip(root);
        double  value = DLL_pop(root);
        DLL_flip(root);
        return value;
}

void DLL_change_element(double_linked_list** root, int index, double  new_data){
        if(*root IS NULL){
                return;
        }

        double_linked_list* cur = *root;
        *root = cur;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        cur->data = new_data;

}

void DLL_flip(double_linked_list** root){


        double_linked_list* new;
        int once = 0;
        for(int i = DLL_length(*root); i > 0; i--){
                if(once IS 0){
                        new = DLL_create_node(DLL_pop(root));
                        once = 1;
                } else {
                        DLL_push(&new,DLL_pop(root));
                }
        }

        *root = new;
}

void DLL_push(double_linked_list** root, double data){


        if(root NOT_EQUAL NULL){
                double_linked_list* node = DLL_create_node(data);
                double_linked_list* cur = *root;
                *root = cur;

                if(cur->next NOT_EQUAL NULL){
                        while(cur->next NOT_EQUAL NULL){
                                cur = cur->next;
                        }
                        cur->next = node;
                } else {
                        cur->next = node;
                }
        }
}

void DLL_push_node(double_linked_list** root, double_linked_list* node){


        if(root NOT_EQUAL NULL){
                double_linked_list* cur = *root;
                *root = cur;

                if(cur->next NOT_EQUAL NULL){
                        while(cur->next NOT_EQUAL NULL){
                                cur = cur->next;
                        }
                        cur->next = node;
                } else {
                        cur->next = node;
                }
        }
}

void DLL_unshift(double_linked_list** root,double  data){


        if(*root IS NULL){
                return;
        }

        double_linked_list* new_root = DLL_create_node(data);
        new_root->next = *root;
        *root = new_root;
}

void DLL_unshift_node(double_linked_list** root,double_linked_list* node){


        if(*root IS NULL){
                return;
        }

        double_linked_list* new_root = node;
        new_root->next = *root;
        *root = new_root;
}

void DLL_insert_at(double_linked_list** root, int index, double  new_data){

        if(root IS NULL){
                return;
        }

        int length = DLL_length(*root);
        if(index > length){
                return;
        }


        if(index IS 0){
                DLL_unshift(root,new_data);
        } else {
                double_linked_list* temp_first_part = DLL_slice(*root,0,index);
                double_linked_list* temp_last_part = DLL_slice(*root,index,length);
                DLL_push(&temp_first_part,new_data);
                *root = DLL_concat(temp_first_part,temp_last_part);
        }

        return;

}

void DLL_insert_node_at(double_linked_list** root, int index, double_linked_list* new_data){

        if(root IS NULL){
                return;
        }

        int length = DLL_length(*root);
        if(index > length){
                return;
        }


        if(index IS 0){
                DLL_unshift_node(root,new_data);
        } else {
                double_linked_list* temp_first_part = DLL_slice(*root,0,index);
                double_linked_list* temp_last_part = DLL_slice(*root,index,length);
                DLL_push_node(&temp_first_part,new_data);
                *root = DLL_concat(temp_first_part,temp_last_part);
        }

        return;

}

// void *DLL_remove_duplicates(double_linked_list** root){
//         if(root == NULL){
//                 return root;
//         }


//         double_linked_list* dupes = DLL_cpy(*root);
//         double_linked_list* not_dupes;
//         int length = DLL_length(*root);
//         int once = 0;
//         int index;
//         double temp;


//         for (int i = 0; i < length; i++)
//         {

//                 temp = DLL_shift(&dupes);
//                 if(once IS 0 ){
//                         not_dupes = DLL_create_node(temp);
//                         once = 1;
//                 } else if (once IS 1)
//                 {
//                         DLL_push(&not_dupes,temp);
//                 }

//                 for (int j = 0; i < length; j++){
//                         index = DLL_find_index_by_value(dupes,temp);
//                         if(index >= 0){
//                                 DLL_remove_index(&dupes,index);
//                         } else {
//                                 break;
//                         }
//                 }


//         }


//         *root = not_dupes;

// }




void DLL_free(double_linked_list** root){

        double_linked_list* cur = *root;

        if(cur->next IS NULL){
                free(root);
        }

        double_linked_list* prev = *root;

        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }

}

void DLL_free_node(double_linked_list** root, double_linked_list* node){


        if(*root IS NULL){
                DLL_free(root);
                return;
        }

        double_linked_list* cur = *root;
        double_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);

        } else {
                for(int i = 0; i < abs(DLL_length(*root)-DLL_length(node));i++)
                {
                        prev = cur;
                        cur = cur->next;
                }
                if(cur->next NOT_EQUAL NULL){
                        prev->next = cur->next;
                }else {
                        prev->next = NULL;
                }

                free(cur);
        }

}


int DLL_length(double_linked_list* root){
        int length = 0;
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;


}

int DLL_every(double_linked_list* root, int (*f)(double x)){

        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        while (cur->next NOT_EQUAL NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

int DLL_find_index(double_linked_list* root, int (*f)(double x)){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int DLL_find_index_by_value(double_linked_list* root, int value){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}



int DLL_find_last_index(double_linked_list* root, int (*f)(double x)){

        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int DLL_includes(double_linked_list* root, double value){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }

        return 0;


}

int DLL_some(double_linked_list* root, int (*f)(double x)){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data)){
                        count++;
                }
                cur = cur->next;
        }

        if(count IS 0){
                return -1;
        } else {
                return count;
        }

}

double DLL_foldr(double_linked_list* root, double (*f)(double x,double y),double  start_value){
        if(root IS NULL){
                return -2;
        }

        if(start_value < 0){
                return DLL_at(root,0);
        }

        int length = DLL_length(root);

        if(length < 2){
                return DLL_at(root,0);
        }

        if(length IS 2){
                return f(DLL_at(root,0), DLL_at(root,1));
        }

        double  accumulator = start_value;

        for (int i = 0; i < length; i++){
                accumulator = f(accumulator,DLL_at(root,i));
        }

        return accumulator;
}

double DLL_foldl(double_linked_list* root, double (*f)(double x,double y),double start_value){
        if(root IS NULL){
                return -2;
        }

        if(start_value < 0){
                return DLL_at(root,0);
        }

        int length = DLL_length(root);

        if(length < 2){
                return DLL_at(root,0);
        }

        if(length IS 2){
                return f(DLL_at(root,1), DLL_at(root,0));
        }

        double  accumulator = start_value;

        for (int i = length-1; i >= 0; i--){
                accumulator = f(accumulator,DLL_at(root,i));
        }

        return accumulator;
}

double DLL_find(double_linked_list* root, int (*f)(double x)){

        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return -1;
}

double DLL_find_last(double_linked_list* root, int (*f)(double x)){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        double value = -1;

        for (int i = 0; i < DLL_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

double DLL_at(double_linked_list* root, int index){
        if (root IS NULL){
                return -2;
        }

        if(index IS 0){
                return root->data;
        }


        double_linked_list* cur = root;

        if(DLL_length(root) < index){
                return -1;
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

double DLL_for_each(double_linked_list* root, double (*f)(double x,double y)){
        if (root IS NULL){
                return -2;
        }

        double *arr = DLL_to_array(root);
        double accumulator = 0;
        int once = 0;

        for(int i = 0; i < DLL_length(root) + 1; i++){
                if(i IS 2){
                        accumulator += f(arr[i-2],arr[i-1]);
                        once = 1;
                } else if(once IS 1){
                        accumulator = f(accumulator,arr[i-1]);
                }
        }

        free(arr);
        return accumulator;
}

double *DLL_to_array(double_linked_list* root){

        if(root IS NULL){
                return (double *)-1;
        }

        int length = DLL_length(root);
        double *arr = malloc(sizeof(root));

        double_linked_list* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        };

        return arr;
}

void DLL_print(double_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %f\n", root->data);
        printf("Next node: \n");
        DLL_print(root->next);
}

void DLL_sort(double_linked_list** root){ /* BROKEn*/

        if(*root IS NULL){
                return;
        }


        double_linked_list* cur = *root;

        double *arr = DLL_to_array(cur);
        int length = DLL_length(cur);

        double_mergeSort(arr,0,length-1);

        *root = cur;
        for(int i = 0; i < length;i++){
                cur->data = arr[i];
                cur = cur->next;
        }
        DLL_print(*root);
        return;
}


void double_merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;


    double L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 AND j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void double_mergeSort(double arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        double_mergeSort(arr, l, m);
        double_mergeSort(arr, m + 1, r);

        double_merge(arr, l, m, r);
    }
}

int cpy_func (double i){
        i;
        return true;
}