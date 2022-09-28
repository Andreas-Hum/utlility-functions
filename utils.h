#include <stdio.h>
#include <stdlib.h>

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

/* Utility functions */
void print_tree(int_tree* root);
int int_tree_length(int_tree* root);

/* Creating or chaning tree */
int_tree *create_node(int data);
int_tree *create_tree_from_int_array(int array[],int size);
int_tree *concat_int_tree(int_tree* tree_one_root, int_tree* tree_two_root);

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

//        print_tree(root);

        return root;
}

int *int_tree_to_array(int_tree* root){
        int length = int_tree_length(root);
        int *arr = malloc(length);
        if(!arr){
                return NULL;
        }

        int_tree* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        }

        return arr;
}

int_tree *concat_int_tree(int_tree* tree_one_root, int_tree* tree_two_root){

        if(tree_one_root == NULL){
                return tree_two_root;
        }

        if(tree_two_root == NULL){
                return tree_one_root;
        }

        int length = int_tree_length(tree_one_root)+int_tree_length(tree_two_root);

        
        int *tree_one_arr = int_tree_to_array(tree_one_root);
        int *tree_two_arr = int_tree_to_array(tree_two_root);
        int_tree* concatinated_tree = create_node(tree_one_arr[0]);

        for(int i = 1; i < length-int_tree_length(tree_two_root);i++){
                push(concatinated_tree,create_node(tree_one_arr[i]));
        }

        for(int i = 0; i < length-int_tree_length(tree_one_root);i++){
                push(concatinated_tree,create_node(tree_two_arr[i]));
        }

        free(tree_one_arr);
        free(tree_two_arr);
        return concatinated_tree;

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

void free_node(int_tree* root, int_tree* node){

        if(root == node){
                free(root);
        }

        int_tree* cur = root;
        int_tree* prev = root;

        while (cur->next != NULL)
        {
                prev = cur;
                cur = cur->next;
        }

        prev->next = NULL;
        free(cur);
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

