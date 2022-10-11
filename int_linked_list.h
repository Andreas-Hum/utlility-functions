/*
*
* Created by Andreas Svanberg Hummelmose, student at AAU
*
* Updated: 11-10-2022
*/


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

typedef struct int_linked_list{
        int data;
        struct int_linked_list *next;
} int_linked_list;



/* Creating new linked lists  */

int_linked_list *ILL_create_node(int data);
int_linked_list *ILL_array_to_list(int array[],int size);
int_linked_list *ILL_concat(int_linked_list* list_one_root, int_linked_list* list_two_root);
int_linked_list *ILL_filter(int_linked_list* root, int (*f)(int x));
int_linked_list *ILL_fill(int_linked_list* root, int length,int value,int new_list);
int_linked_list *ILL_map(int_linked_list* root, int (*f)(int x));
int_linked_list *ILL_cpy(int_linked_list* root);
int_linked_list *ILL_cpy_within(int_linked_list* root, int left, int right);
int_linked_list *ILL_slice(int_linked_list* root, int left, int right);
int_linked_list *ILL_splice(int_linked_list** root, int start, int delete_count, int_linked_list* add_remove,int remove);


/* freeing memory */

void ILL_free(int_linked_list** root);
void ILL_free_node(int_linked_list** root, int_linked_list* node);

/* Mutating list */

int ILL_pop(int_linked_list** root);
int ILL_remove_index(int_linked_list** root, int index);
int ILL_shift(int_linked_list** root);
void ILL_change_element(int_linked_list** root, int index, int new_data);
void ILL_flip(int_linked_list** root);
void ILL_push(int_linked_list** root, int data);
void ILL_push_node(int_linked_list** root,int_linked_list* node);
void ILL_unshift(int_linked_list** root,int data);
void ILL_unshift_node(int_linked_list** root,int_linked_list* node);
void ILL_insert_at(int_linked_list** root, int index, int new_data);
void ILL_insert_node_at(int_linked_list** root, int index, int_linked_list* new_data);

/* Utility functions */

int ILL_length(int_linked_list* root);
int ILL_every(int_linked_list* root, int (*f)(int x));
int ILL_for_each(int_linked_list* root, int (*f)(int x,int y));
int *ILL_to_array(int_linked_list* root);
int ILL_find_index(int_linked_list* root, int (*f)(int x));
int ILL_find_index_by_value(int_linked_list* root, int value);
int ILL_find(int_linked_list* root, int f());
int ILL_find_last(int_linked_list* root, int (*f)(int x));
int ILL_find_last_index(int_linked_list* root, int (*f)(int x));
int ILL_at(int_linked_list* root, int index);
int ILL_includes(int_linked_list* root, int value);
int ILL_foldr(int_linked_list* root, int (*f)(int x,int y), int start_value);
int ILL_foldl(int_linked_list* root, int (*f)(int x,int y),int start_value);
int ILL_some(int_linked_list* root, int (*f)(int x));
void ILL_print(int_linked_list* root);
void ILL_sort(int_linked_list** root);


int cpy_func (int i);
void int_mergeSort(int arr[], int l, int r);
void int_merge(int arr[], int l, int m, int r);


int_linked_list *ILL_create_node(int data){

        int_linked_list* node = (int_linked_list*)malloc(sizeof(int_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

int_linked_list *ILL_array_to_list(int array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return ILL_create_node(0);
        }


        int_linked_list *root = ILL_create_node(array[0]);

       for(int i = 1; i < size;i++){
                ILL_push(&root,array[i]);
       }

        return root;
}

int_linked_list *ILL_concat(int_linked_list* list_one_root, int_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = ILL_length(list_one_root)+ILL_length(list_two_root);

        int_linked_list* concatinated_tree = ILL_cpy(list_one_root);
        int_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = ILL_cpy(list_two_root);

        return concatinated_tree;

}

int_linked_list *ILL_filter(int_linked_list* root, int (*f)(int x)){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = ILL_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        ILL_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *ILL_fill(int_linked_list* root, int length,int value,int new_list){
        if(!new_list){
                int_linked_list* cur = root;
                int length = ILL_length(root);
                if(length < length){
                        for(int i = 0; i < length; i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = length; i < length ; i++)
                        {
                                ILL_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = ILL_create_node(value);
                for (int i = 1; i < length; i++){
                        ILL_push(&root,value);
                }
        }

        return root;
}

int_linked_list *ILL_map(int_linked_list* root,int (*f)(int x)){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(once IS 0){
                        filtered_array = ILL_create_node(f(cur->data));
                        once = 1;
                } else if(once IS 1){
                        ILL_push(&filtered_array,f(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *ILL_cpy(int_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return ILL_filter(root,cpy_func);
}

int_linked_list *ILL_cpy_within(int_linked_list* root, int left, int right){
        if(root IS NULL){
                return ILL_create_node(-1);
        }


        if(left > right){
                return ILL_create_node(-1);
        } else if (right > ILL_length(root)){
                return ILL_create_node(-1);
        } else if(left < 0 OR right < 0){
                return ILL_create_node(-1);
        }

        int_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = ILL_create_node(ILL_at(root,i));
                        once = 1;
                } else {
                        ILL_push(&copied,ILL_at(root,i));
                }
        }

        return copied;
}

int_linked_list *ILL_slice(int_linked_list* root, int left, int right){

        if(root IS NULL){
                return ILL_create_node(-1);
        }


        if(left > right){
                return ILL_create_node(-1);
        } else if (right > ILL_length(root)){
                return ILL_create_node(-1);
        } else if(left < 0 OR right < 0){
                return ILL_create_node(-1);
        }

        int_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = ILL_create_node(ILL_at(root,i));
                        once = 1;
                } else {
                        ILL_push(&sliced,ILL_at(root,i));
                }
        }

        return sliced;
}

int_linked_list *ILL_splice(int_linked_list** root, int start, int delete_count, int_linked_list* add_remove,int remove){

        int_linked_list* cur = *root;
        int_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return ILL_create_node(-1);
        } else if(delete_count > ILL_length(*root)){
                return ILL_create_node(-1);
        }





        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                                deleted = ILL_create_node(ILL_at(*root,start));
                                ILL_remove_index(root,start);
                                once = 1;
                        } else {
                                ILL_push(&deleted,ILL_at(*root,start));
                                ILL_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < ILL_length(add_remove); i++){
                                ILL_insert_at(root,start,ILL_at(add_remove,i));
                                start++;
                        }
                }

                return deleted;

        } else {
                for(int i = 0; i < ILL_length(add_remove); i++){
                        ILL_insert_at(root,start,ILL_at(add_remove,i));
                        start++;
                }
                return ILL_create_node(0);
        }


}



void ILL_free(int_linked_list** root){

        int_linked_list* cur = *root;

        if(cur->next IS NULL){
                free(root);
        }

        int_linked_list* prev = *root;

        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }

}

void ILL_free_node(int_linked_list** root, int_linked_list* node){


        if(*root IS NULL){
                ILL_free(root);
                return;
        }

        int_linked_list* cur = *root;
        int_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);

        } else {
                for(int i = 0; i < abs(ILL_length(*root)-ILL_length(node));i++)
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


int ILL_pop(int_linked_list** root){

        if(*root IS NULL){
                return -1;
        }

        int value;
        int_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        ILL_free_node(root,cur);

        return value;

}

int ILL_remove_index(int_linked_list** root, int index){
        if(root IS NULL){
                return -1;
        }

        if(index IS 0 OR index > ILL_length(*root)){
                return -1;
        }

        int_linked_list* cur = *root;
        *root = cur;

        int value;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        ILL_free_node(root,cur);

        return (value);

}

int ILL_shift(int_linked_list** root){

        ILL_flip(root);
        int value = ILL_pop(root);
        ILL_flip(root);
        return value;
}

void ILL_change_element(int_linked_list** root, int index, int new_data){
        if(*root IS NULL){
                return;
        }

        int_linked_list* cur = *root;
        *root = cur;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        cur->data = new_data;

}

void ILL_flip(int_linked_list** root){


        int_linked_list* new;
        int once = 0;
        for(int i = ILL_length(*root); i > 0; i--){
                if(once IS 0){
                        new = ILL_create_node(ILL_pop(root));
                        once = 1;
                } else {
                        ILL_push(&new,ILL_pop(root));
                }
        }

        *root = new;
}

void ILL_push(int_linked_list** root, int data){


        if(root NOT_EQUAL NULL){
                int_linked_list* node = ILL_create_node(data);
                int_linked_list* cur = *root;
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

void ILL_push_node(int_linked_list** root, int_linked_list* node){


        if(root NOT_EQUAL NULL){
                int_linked_list* cur = *root;
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

void ILL_unshift(int_linked_list** root,int data){


        if(*root IS NULL){
                return;
        }

        int_linked_list* new_root = ILL_create_node(data);
        new_root->next = *root;
        *root = new_root;
}

void ILL_unshift_node(int_linked_list** root,int_linked_list* node){


        if(*root IS NULL){
                return;
        }

        int_linked_list* new_root = node;
        new_root->next = *root;
        *root = new_root;
}

void ILL_insert_at(int_linked_list** root, int index, int new_data){

        if(root IS NULL){
                return;
        }

        int length = ILL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                ILL_unshift(root,new_data);
        } else {
                int_linked_list* temp_first_part = ILL_slice(*root,0,index);
                int_linked_list* temp_last_part = ILL_slice(*root,index,length);
                ILL_push(&temp_first_part,new_data);
                *root = ILL_concat(temp_first_part,temp_last_part);
        }

        return;

}

void ILL_insert_node_at(int_linked_list** root, int index, int_linked_list* new_data){

        if(root IS NULL){
                return;
        }

        int length = ILL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                ILL_unshift_node(root,new_data);
        } else {
                int_linked_list* temp_first_part = ILL_slice(*root,0,index);
                int_linked_list* temp_last_part = ILL_slice(*root,index,length);
                ILL_push_node(&temp_first_part,new_data);
                *root = ILL_concat(temp_first_part,temp_last_part);
        }

        return;

}


int ILL_length(int_linked_list* root){
        int length = 0;
        if(root IS NULL){
                return length;
        }

        int_linked_list* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;


}

int ILL_every(int_linked_list* root, int (*f)(int x)){

        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;

        while (cur->next NOT_EQUAL NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

int ILL_for_each(int_linked_list* root, int (*f)(int x,int y)){
        if (root IS NULL){
                return -2;
        }

        int *arr = ILL_to_array(root);
        int accumulator = 0;
        int once = 0;

        for(int i = 0; i < ILL_length(root) + 1; i++){
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

int *ILL_to_array(int_linked_list* root){

        if(root IS NULL){
                return (int*)-2;
        }
        int length = ILL_length(root);
        int *arr = malloc(sizeof(root));

        int_linked_list* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        };

        return arr;
}

int ILL_find_index(int_linked_list* root,int (*f)(int x)){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int ILL_find_index_by_value(int_linked_list* root, int value){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int ILL_find(int_linked_list* root, int (*f)(int x)){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return -1;
}

int ILL_find_last(int_linked_list* root, int (*f)(int x)){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int value = -1;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

int ILL_find_last_index(int_linked_list* root, int (*f)(int x)){

        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int ILL_at(int_linked_list* root, int index){
        if (root IS NULL){
                return -2;
        }

        if(index IS 0){
                return root->data;
        }


        int_linked_list* cur = root;

        if(ILL_length(root) < index){
                return -1;
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

int ILL_includes(int_linked_list* root, int value){
        if(root IS NULL){
                return -1;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < ILL_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }


        return 0;


}

int ILL_foldr(int_linked_list* root, int (*f)(int x,int y),int start_value){
        if(root IS NULL){
                return ILL_at(root,0);
        }

        if(start_value < 0){
                return ILL_at(root,0);
        }

        int length = ILL_length(root);

        if(length < 2){
                return ILL_at(root,0);
        }

        if(length IS 2){
                return f(ILL_at(root,0), ILL_at(root,1));
        }

        int accumulator = start_value;
        int once = 0;

        for (int i = 0; i < length; i++){
                accumulator = f(accumulator,ILL_at(root,i));
        }

        return accumulator;
}

int ILL_foldl(int_linked_list* root, int (*f)(int x,int y),int start_value){
        if(root IS NULL){
                return ILL_at(root,0);
        }

        if(start_value < 0){
                return ILL_at(root,0);
        }

        int length = ILL_length(root);

        if( length < 2){
                return ILL_at(root,0);
        }

        if(length IS 2){
                return f(ILL_at(root,1), ILL_at(root,0));
        }

        int accumulator = start_value;
        int once = 0;

        for (int i = length-1; i >= 0; i--){
                accumulator = f(accumulator,ILL_at(root,i));
        }

        return accumulator;
}

int ILL_some(int_linked_list* root, int (*f)(int x)){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < ILL_length(root); i++)
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

void ILL_print(int_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %d\n", root->data);
        printf("Next node: \n");
        ILL_print(root->next);
}

void ILL_sort(int_linked_list** root){ /* BROKEN */

        if(*root IS NULL){
                return;
        }


        int_linked_list* cur = *root;

        int *arr = ILL_to_array(cur);

        int length = ILL_length(cur);

        int_mergeSort(arr,0,length-1);

        *root = cur;
        for(int i = 0; i < length;i++){
                cur->data = arr[i];
                cur = cur->next;
        }
        ILL_print(*root);
        return;
}


int cpy_func (int i){
        i;
        return true;
}


void int_merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
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

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void int_mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        int_mergeSort(arr, l, m);
        int_mergeSort(arr, m + 1, r);

        int_merge(arr, l, m, r);
    }
}