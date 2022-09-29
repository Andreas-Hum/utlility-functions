#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_linked_list
{
        int data;
        struct int_linked_list *next;
} int_linked_list;



/* freeing memory */
void free_tree(int_linked_list* root);
void free_node(int_linked_list* root, int_linked_list* node);

/* Changing tree size */
void push(int_linked_list* root, int_linked_list* node);
int pop(int_linked_list* root);
int remove_index(int_linked_list* root, int index);
void shift(int_linked_list* root);

/* Utility functions */
void print_linked_list(int_linked_list* root);
int int_linked_list_length(int_linked_list* root);
int every(int_linked_list* root, int f());
int for_each(int_linked_list* root, int f());
int *int_linked_list_to_array(int_linked_list* root);
int find_index(int_linked_list* root, int f());
int cpy_func (int i);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
// void sort_int_linked_list(int_linked_list* root);

/* Creating new trees */
int_linked_list *create_node(int data);
int_linked_list *create_tree_from_int_array(int array[],int size);
int_linked_list *concat_int_linked_list(int_linked_list* tree_one_root, int_linked_list* tree_two_root);
int_linked_list *filter(int_linked_list* root, int f());
int_linked_list *map(int_linked_list* root, int f());
int_linked_list *flip(int_linked_list* root);
int_linked_list *cpy_tree(int_linked_list* root);

int_linked_list *create_node(int data){
        int_linked_list* node = malloc(sizeof(int_linked_list));
        if(node != NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

int_linked_list *create_tree_from_int_array(int array[],int size){

        if(size == 0){
                printf("Error empty array\n");
                return create_node(0);
        }


        int_linked_list *root = create_node(array[0]);

       for(int i = 1; i < size;i++){
                push(root,create_node(array[i]));
       }

        return root;
}



int_linked_list *filter(int_linked_list* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data) && once == 0){
                        filtered_array = create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) && once == 1){
                        push(filtered_array,create_node(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *map(int_linked_list* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(once == 0){
                        filtered_array = create_node(f(cur->data));
                        once = 1;
                } else if(once == 1){
                        push(filtered_array,create_node(f(cur->data)));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *concat_int_linked_list(int_linked_list* tree_one_root, int_linked_list* tree_two_root){

        if(tree_one_root == NULL){
                return tree_two_root;
        }

        if(tree_two_root == NULL){
                return tree_one_root;
        }

        int length = int_linked_list_length(tree_one_root)+int_linked_list_length(tree_two_root);


        // int *tree_one_arr = int_linked_list_to_array(tree_one_root);
        // int *tree_two_arr = int_linked_list_to_array(tree_two_root);
        int_linked_list* concatinated_tree = cpy_tree(tree_one_root);
        int_linked_list*cur = concatinated_tree;
        while(cur->next != NULL ){
                cur = cur->next;
        }

        cur->next = cpy_tree(tree_two_root);

        return concatinated_tree;

        // for(int i = 1; i < length-int_linked_list_length(tree_two_root);i++){
        //         push(concatinated_tree,create_node(tree_one_arr[i]));
        // }

        // for(int i = 0; i < length-int_linked_list_length(tree_one_root);i++){
        //         push(concatinated_tree,create_node(tree_two_arr[i]));
        // }

        // free(tree_one_arr);
        // free(tree_two_arr);

        

}


int_linked_list* flip(int_linked_list* root){
        if(root == NULL){
                return root;
        }


        int_linked_list* new;
        int once = 0;
        for(int i = int_linked_list_length(root); i > 0; i--){
                if(once == 0){
                        new = create_node(pop(root));
                        once = 1;
                } else {
                        push(new,create_node(pop(root)));
                }
                printf("%d",int_linked_list_length(root));
                print_linked_list(new);
        }


        return new;
}

int_linked_list *cpy_tree(int_linked_list* root){
        if(root == NULL){
                return root;
        }

        return filter(root,cpy_func);
}


int_linked_list *fill(int_linked_list* root, int length,int value,int new_tree){
        if(!new_tree){
                int_linked_list* cur = root;
                if(int_linked_list_length(root) < length){
                        for(int i = 0; i < int_linked_list_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = int_linked_list_length(root); i < length ; i++)
                        {
                                push(root,create_node(value));
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = create_node(value);
                for (int i = 1; i < length; i++){
                        push(root,create_node(value));
                }
        }

        return root;
}


int cpy_func (int i){
        i;
        return true;
}


void shift(int_linked_list* root){
        
        //int_linked_list *new_array = flip(root);
        //int value = pop(new_array);
        // print_linked_list(new_array);
        
        // root = flip(new_array);
        // print_linked_list(root);
        // return value;
}


int find_index(int_linked_list* root, int f()){
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

int remove_index(int_linked_list* root, int index){
        if(root == NULL){
                return -1;
        }

        if(index == 0 || index > int_linked_list_length(root)){
                return 0;
        }

        int_linked_list* cur = root;
        int value;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        free_node(root,cur);

       

        return (value);

}

int pop(int_linked_list* root){

        if(root == NULL){
                return -1;
        }

        int value;
        int_linked_list* cur = root;

        while (cur->next != NULL){
                cur = cur->next;
        }

        value = cur->data;
        free_node(root,cur);
        return value;

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


int every(int_linked_list* root, int f()){

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

int for_each(int_linked_list* root, int f()){
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

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



// void sort_int_linked_list(int_linked_list* root){
//         int *arr = int_linked_list_to_array(root);
//         printf("%d",arr[0]);
//         mergeSort(arr,0,int_linked_list_length(root)-1);
//         printf("%d",arr[0]);
//         root = create_tree_from_int_array(arr,int_linked_list_length(root));
// }


void free_node(int_linked_list* root, int_linked_list* node){


        if(root == NULL){
                free_tree(root);
                return;
        }

        int_linked_list* cur = root;
        int_linked_list* prev = root;

        if(root==node){
                root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(int_linked_list_length(root)-int_linked_list_length(node));i++)
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

void free_tree(int_linked_list* root){
        if(root->next == NULL){
                free(root);
        }

        int_linked_list* cur = root;
        int_linked_list* prev = root;

        while (cur != NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }
        

}

void push(int_linked_list* root, int_linked_list* node){

        if(!root){
                printf("dasdadas");
        }

        if(root != NULL && node != NULL){
                if(root->next != NULL){
                        int_linked_list* cur = root;
                        while(cur->next != NULL){
                                cur = cur->next;
                        }
                        cur->next = node;
                } else {
                        root->next = node;
                }
        }
}


void print_linked_list(int_linked_list* root){

        if(root == NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %d\n", root->data);
        printf("Next node: \n");
        print_linked_list(root->next);
}