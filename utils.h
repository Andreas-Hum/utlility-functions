#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_tree
{
        int data;
        struct int_tree *next;
} int_tree;



/* freeing memory */
void free_tree(int_tree* root);
void free_node(int_tree* root, int_tree* node);

/* Changing tree size */
void push(int_tree* root, int_tree* node);
int pop(int_tree* root);
int remove_index(int_tree* root, int index);
int shift(int_tree* root);

/* Utility functions */
void print_tree(int_tree* root);
int int_tree_length(int_tree* root);
int every(int_tree* root, int f());
int for_each(int_tree* root, int f());
int *int_tree_to_array(int_tree* root);
int find_index(int_tree* root, int f());
int no_change (int i);

/* Creating new trees */
int_tree *create_node(int data);
int_tree *create_tree_from_int_array(int array[],int size);
int_tree *concat_int_tree(int_tree* tree_one_root, int_tree* tree_two_root);
int_tree *filter(int_tree* root, int f());
int_tree *map(int_tree* root, int f());
int_tree *flip(int_tree* root);

int_tree *create_node(int data){
        int_tree* node = malloc(sizeof(int_tree));
        if(node != NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

int_tree *create_tree_from_int_array(int array[],int size){

        if(size == 0){
                printf("Error empty array\n");
                return create_node(0);
        }


        int_tree *root = create_node(array[0]);

       for(int i = 1; i < size;i++){
                push(root,create_node(array[i]));
       }

        return root;
}



int_tree *filter(int_tree* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_tree* filtered_array;
        int_tree* cur = root;

        for (int i = 0; i < int_tree_length(root); i++)
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

int_tree *map(int_tree* root, int f()){

        if(root == NULL){
                return root;
        }

        int once = 0;
        int_tree* filtered_array;
        int_tree* cur = root;

        for (int i = 0; i < int_tree_length(root); i++)
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

int_tree *concat_int_tree(int_tree* tree_one_root, int_tree* tree_two_root){

        if(tree_one_root == NULL){
                return tree_two_root;
        }

        if(tree_two_root == NULL){
                return tree_one_root;
        }

        int length = int_tree_length(tree_one_root)+int_tree_length(tree_two_root);


        // int *tree_one_arr = int_tree_to_array(tree_one_root);
        // int *tree_two_arr = int_tree_to_array(tree_two_root);
        int_tree* concatinated_tree = filter(tree_one_root,no_change);
        int_tree*cur = concatinated_tree;
        while(cur->next != NULL ){
                cur = cur->next;
        }

        cur->next = filter(tree_two_root,no_change);

        return concatinated_tree;

        // for(int i = 1; i < length-int_tree_length(tree_two_root);i++){
        //         push(concatinated_tree,create_node(tree_one_arr[i]));
        // }

        // for(int i = 0; i < length-int_tree_length(tree_one_root);i++){
        //         push(concatinated_tree,create_node(tree_two_arr[i]));
        // }

        // free(tree_one_arr);
        // free(tree_two_arr);

        

}


int_tree* flip(int_tree* root){
        if(root == NULL){
                return root;
        }


        int_tree* new;
        int once = 0;
        for(int i = int_tree_length(root); i > 0; i--){
                if(once == 0){
                        new = create_node(pop(root));
                        once = 1;
                } else {
                        push(new,create_node(pop(root)));
                }
        }

        // free_tree(root);

        return new;
}

int no_change (int i){
        return i >= 0;
}


int shift(int_tree* root){
        // if(root == NULL){
        //         return -1;
        // }
        // root = flip(root);
        // // print_tree(root);
        // int value = pop(root);
        // return value;

         /* Works */
        // test_array = flip(test_array);
        // int test = pop(test_array);
        // test_array = flip(test_array);
}


int find_index(int_tree* root, int f()){
        if(root== NULL){
                return -2;
        }

        int_tree* cur = root;

        for (int i = 0; i < int_tree_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int remove_index(int_tree* root, int index){
        if(root == NULL){
                return -1;
        }

        int_tree* cur = root;
        int value;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        free_node(root,cur);

        return (value);

}

int pop(int_tree* root){

        if(root == NULL){
                return -1;
        }

        int value;
        int_tree* cur = root;

        while (cur->next != NULL){
                cur = cur->next;
        }

        value = cur->data;
        free_node(root,cur);
        return value;

}

int *int_tree_to_array(int_tree* root){

        if(root == NULL){
                return (int*)-1;
        }

        int length = int_tree_length(root);
        int *arr = malloc(sizeof(int_tree));

        int_tree* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        };

        
        return arr;
}

int int_tree_length(int_tree* root){
        int length = 0;
        if(root == NULL){
                return length;
        }

        int_tree* cur = root;
        while (cur != NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;


}


int every(int_tree* root, int f()){

        if(root == NULL){
                return -1;
        }

        int_tree* cur = root;

        while (cur->next != NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

int for_each(int_tree* root, int f()){
        if (root == NULL){
                return -1;
        }

        int *arr = int_tree_to_array(root);
        int accumulator = 0;
        int once = 0;

        for(int i = 0; i < int_tree_length(root) + 1; i++){
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


int_tree *fill(int_tree* root, int length,int value,int new_tree){
        if(!new_tree){
                int_tree* cur = root;
                if(int_tree_length(root) < length){
                        for(int i = 0; i < int_tree_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = int_tree_length(root); i < length ; i++)
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

void free_node(int_tree* root, int_tree* node){


        if(root == node){
                free_tree;
                return;
        }

        int_tree* cur = root;
        int_tree* prev = root;

        for(int i = 0; i < abs(int_tree_length(root)-int_tree_length(node));i++)
        {
                prev = cur;
                cur = cur->next;
        }

        if(cur->next != NULL){
                prev->next = cur->next;
        }else {
                prev->next = NULL;
        }
        
        // free(cur);
        return;
}

void free_tree(int_tree* root){
        if(root->next == NULL){
                free(root);
        }

        int_tree* cur = root;
        int_tree* prev = root;

        while (cur != NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }
        
        return;

}

void push(int_tree* root, int_tree* node){

        if(root != NULL && node != NULL){
                if(root->next != NULL){
                        int_tree* cur = root;
                        while(cur->next != NULL){
                                cur = cur->next;
                        }
                        cur->next = node;
                } else {
                        root->next = node;
                }
        }
}


void print_tree(int_tree* root){

        if(root == NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %d\n", root->data);
        printf("Next node: \n");
        print_tree(root->next);
}