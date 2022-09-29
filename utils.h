/*
*
*
* Created by Andreas Svanberg Hummelmose, student at AAU
*
* Updated: 29-09-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_linked_list
{
        int data;
        struct int_linked_list *next;
} int_linked_list;


/* All functions are in order of return type:*/


/*
*       integer linked list
*/


/* Creating new linked lists  */

int_linked_list *int_linked_list_create_node(int data);
int_linked_list *int_linked_list_array_to_list(int array[],int size);
int_linked_list *int_linked_list_concat(int_linked_list* tree_one_root, int_linked_list* tree_two_root);
int_linked_list *int_linked_list_filter(int_linked_list* root, int f());
int_linked_list *int_linked_list_fill(int_linked_list* root, int length,int value,int new_tree);
int_linked_list *int_linked_list_map(int_linked_list* root, int f());
int_linked_list *int_linked_list_cpy(int_linked_list* root);
int_linked_list *int_linked_list_cpy_within(int_linked_list* root, int left, int right);

/* freeing memory */

void int_linked_list_free(int_linked_list** root);
void int_linked_list_free_node(int_linked_list** root, int_linked_list* node);

/* Changing list size */

int int_linked_list_pop(int_linked_list** root);
int int_linked_list_remove_index(int_linked_list** root, int index);
int int_linked_list_shift(int_linked_list** root);
void int_linked_list_change_element(int_linked_list** root, int index, int new_data);
void int_linked_list_flip(int_linked_list** root);
void int_linked_list_push(int_linked_list** root, int_linked_list* node);
void int_linked_list_unshift(int_linked_list** root,int data);

/* Utility functions */

int int_linked_list_length(int_linked_list* root);
int int_linked_list_every(int_linked_list* root, int f());
int int_linked_list_for_each(int_linked_list* root, int f());
int *int_linked_list_to_array(int_linked_list* root);
int int_linked_list_find_index(int_linked_list* root, int f());
int int_linked_list_find(int_linked_list* root, int f());
int int_linked_list_find_last(int_linked_list* root, int f());
int int_linked_list_find_last_index(int_linked_list* root, int f());
int int_linked_list_at(int_linked_list* root, int index);
int int_linked_list_includes(int_linked_list* root, int value);
void int_linked_list_print(int_linked_list* root);
void int_linked_list_sort(int_linked_list** root); /* BROKEN */

/* Non specific utility functions */

int cpy_func (int i);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void print_Array(int array[], int size);



int_linked_list *int_linked_list_create_node(int data){

        int_linked_list* node = malloc(sizeof(int_linked_list));
        if(node != NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

int_linked_list *int_linked_list_array_to_list(int array[],int size){


        if(size == 0){
                printf("Error empty array\n");
                return int_linked_list_create_node(0);
        }


        int_linked_list *root = int_linked_list_create_node(array[0]);

       for(int i = 1; i < size;i++){
                int_linked_list_push(&root,int_linked_list_create_node(array[i]));
       }

        return root;
}

int_linked_list *int_linked_list_concat(int_linked_list* tree_one_root, int_linked_list* tree_two_root){

        if(tree_one_root == NULL){
                return tree_two_root;
        }

        if(tree_two_root == NULL){
                return tree_one_root;
        }

        int length = int_linked_list_length(tree_one_root)+int_linked_list_length(tree_two_root);

        int_linked_list* concatinated_tree = int_linked_list_cpy(tree_one_root);
        int_linked_list*cur = concatinated_tree;
        while(cur->next != NULL ){
                cur = cur->next;
        }

        cur->next = int_linked_list_cpy(tree_two_root);

        return concatinated_tree;

}

int_linked_list *int_linked_list_filter(int_linked_list* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data) && once == 0){
                        filtered_array = int_linked_list_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) && once == 1){
                        int_linked_list_push(&filtered_array,int_linked_list_create_node(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *int_linked_list_fill(int_linked_list* root, int length,int value,int new_tree){
        if(!new_tree){
                int_linked_list* cur = root;
                if(int_linked_list_length(root) < length){
                        for(int i = 0; i < int_linked_list_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = int_linked_list_length(root); i < length ; i++)
                        {
                                int_linked_list_push(&root,int_linked_list_create_node(value));
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = int_linked_list_create_node(value);
                for (int i = 1; i < length; i++){
                        int_linked_list_push(&root,int_linked_list_create_node(value));
                }
        }

        return root;
}

int_linked_list *int_linked_list_map(int_linked_list* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(once == 0){
                        filtered_array = int_linked_list_create_node(f(cur->data));
                        once = 1;
                } else if(once == 1){
                        int_linked_list_push(&filtered_array,int_linked_list_create_node(f(cur->data)));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *int_linked_list_cpy(int_linked_list* root){
        if(root == NULL){
                return root;
        }

        return int_linked_list_filter(root,cpy_func);
}

int_linked_list *int_linked_list_cpy_within(int_linked_list* root, int left, int right){
        if(root == NULL){
                return int_linked_list_create_node(-1);
        }


        if(left > right){
                return int_linked_list_create_node(-1);
        } else if (right > int_linked_list_length(root)){
                return int_linked_list_create_node(-1);
        } else if(left < 0 || right < 0){
                return int_linked_list_create_node(-1);
        }

        int_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once == 0){
                        copied = int_linked_list_create_node(int_linked_list_at(root,i));
                        once = 1;
                } else {
                        int_linked_list_push(&copied,int_linked_list_create_node(int_linked_list_at(root,i)));
                }
        }

        return copied;
        


}



void int_linked_list_free(int_linked_list** root){

        int_linked_list* cur = *root;

        if(cur->next == NULL){
                free(root);
        }

        int_linked_list* prev = *root;

        while (cur != NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }

}

void int_linked_list_free_node(int_linked_list** root, int_linked_list* node){


        if(*root == NULL){
                int_linked_list_free(root);
                return;
        }

        int_linked_list* cur = *root;
        int_linked_list* prev = *root;

        if(*root==node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(int_linked_list_length(*root)-int_linked_list_length(node));i++)
                {
                        prev = cur;
                        cur = cur->next;
                }
                if(cur->next != NULL){
                        prev->next = cur->next;
                }else {
                        prev->next = NULL;
                }
        
                free(cur);
        }

}



int int_linked_list_pop(int_linked_list** root){

        if(*root == NULL){
                return -1;
        }

        int value;
        int_linked_list* cur = *root;

        while (cur->next != NULL){
                cur = cur->next;
        }

        value = cur->data;
        int_linked_list_free_node(root,cur);

        return value;

}

int int_linked_list_remove_index(int_linked_list** root, int index){
        if(root == NULL){
                return -1;
        }

        if(index == 0 || index > int_linked_list_length(*root)){
                return -1;
        }

        int_linked_list* cur = *root;
        *root = cur;

        int value;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        int_linked_list_free_node(root,cur);

        return (value);

}

int int_linked_list_shift(int_linked_list** root){
        
        int_linked_list_flip(root);
        int value = int_linked_list_pop(root);
        int_linked_list_flip(root);
        return value;
}

void int_linked_list_change_element(int_linked_list** root, int index, int new_data){
        if(*root== NULL){
                return;
        }

        int_linked_list* cur = *root;
        *root = cur;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        cur->data = new_data;

}

void int_linked_list_flip(int_linked_list** root){
        

        int_linked_list* new;
        int once = 0;
        for(int i = int_linked_list_length(*root); i > 0; i--){
                if(once == 0){
                        new = int_linked_list_create_node(int_linked_list_pop(root));
                        once = 1;
                } else {
                        int_linked_list_push(&new,int_linked_list_create_node(int_linked_list_pop(root)));
                }
        }

        *root = new;
}

void int_linked_list_push(int_linked_list** root, int_linked_list* node){

        
        if(root != NULL && node != NULL){
                int_linked_list* cur = *root;
                *root = cur;

                if(cur->next != NULL){
                        while(cur->next != NULL){
                                cur = cur->next;
                        }
                        cur->next = node;
                } else {
                        cur->next = node;
                }
        }
}

void int_linked_list_unshift(int_linked_list** root,int data){

        int_linked_list* new_root = int_linked_list_create_node(data);
        new_root->next = *root;
        *root = new_root;
}



int int_linked_list_length(int_linked_list* root){
        int length = 0;
        if(root == NULL){
                return length;
        }

        int_linked_list* cur = root;
        while (cur != NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;


}

int int_linked_list_every(int_linked_list* root, int f()){

        if(root == NULL){
                return -1;
        }

        int_linked_list* cur = root;

        while (cur->next != NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

int int_linked_list_for_each(int_linked_list* root, int f()){
        if (root == NULL){
                return -1;
        }

        int *arr = int_linked_list_to_array(root);
        int accumulator = 0;
        int once = 0;

        for(int i = 0; i < int_linked_list_length(root) + 1; i++){
                if(i == 2){
                        accumulator += f(arr[i-2],arr[i-1]);
                        once = 1;
                } else if(once == 1){
                        accumulator = f(accumulator,arr[i-1]);
                }
        }

        free(arr);
        return accumulator;
}

int *int_linked_list_to_array(int_linked_list* root){

        if(root == NULL){
                return (int*)-1;
        }

        int length = int_linked_list_length(root);
        int *arr = malloc(sizeof(int_linked_list));

        int_linked_list* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        };

        return arr;
}

int int_linked_list_find_index(int_linked_list* root, int f()){
        if(root== NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int int_linked_list_find(int_linked_list* root, int f()){
        if(root== NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return -1;
}

int int_linked_list_find_last(int_linked_list* root, int f()){
        if(root== NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int value = -1;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

int int_linked_list_find_last_index(int_linked_list* root, int f()){
        
        if(root== NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int int_linked_list_at(int_linked_list* root, int index){
        if (root == NULL){
                return -1;
        }

        if(index == 0){
                return root->data;
        }


        int_linked_list* cur = root;

        if(int_linked_list_length(root) < index){
                return -1;
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

int int_linked_list_includes(int_linked_list* root, int value){
        if(root == NULL){
                return -1;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(cur->data == value){
                        return 1;
                }
        }


        return 0;


}

void int_linked_list_print(int_linked_list* root){

        if(root == NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %d\n", root->data);
        printf("Next node: \n");
        int_linked_list_print(root->next);
}

void int_linked_list_sort(int_linked_list** root){ /* BROKEn*/

        // if(*root == NULL){
        //         return;
        // }

        // int *arr = int_linked_list_to_array(*root);

        // mergeSort(arr,0,int_linked_list_length(*root)-1);


        // int_linked_list* cur = *root;
        // *root = cur;
        
        // for(int i = 0; i < int_linked_list_length(*root);i++){
        //         cur->data = arr[i];
        //         cur = cur->next;
        // }
        // print_linked_list(*root);
        // return;
}

int cpy_func (int i){
        i;
        return true;
}


void merge(int arr[], int l, int m, int r)
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
    while (i < n1 && j < n2) {
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void print_Array(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}



