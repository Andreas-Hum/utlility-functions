/*
*
*
* Created by Andreas Svanberg Hummelmose, student at AAU
*
* Updated: 29-09-2022
*/

#pragma warn -rvl /* return value */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

/* Redefining some logical  for better readability*/

#define OR ||
#define AND &&
#define NOT !
#define NOT_EQUAL !=
#define IS ==

typedef struct int_linked_list{
        int data;
        struct int_linked_list *next;
} int_linked_list;

typedef struct double_linked_list{
        double data;
        struct double_linked_list *next;
} double_linked_list;

typedef struct char_linked_list{
        char* data;
        struct char_linked_list* next;
} char_linked_list;

typedef struct key_value_double{
        char *identifier;
        char_linked_list *keys;
        double_linked_list *values;
        struct key_value_double* next;
} key_value_double;

/* All functions are in order of return type:*/


/*
*       type double linked list
*/


/* Creating new linked lists  */

double_linked_list *double_linked_list_create_node(double data);
double_linked_list *double_linked_list_array_to_list(double  array[],int size);
double_linked_list *double_linked_list_concat(double_linked_list* list_one_root, double_linked_list* list_two_root);
double_linked_list *double_linked_list_filter(double_linked_list* root, int f());
double_linked_list *double_linked_list_fill(double_linked_list* root, int length,double value,double new_list);
double_linked_list *double_linked_list_map(double_linked_list* root, double f());
double_linked_list *double_linked_list_cpy(double_linked_list* root);
double_linked_list *double_linked_list_cpy_within(double_linked_list* root, int left, int right);
double_linked_list *double_linked_list_slice(double_linked_list* root, int left, int right);
double_linked_list *double_linked_list_splice(double_linked_list** root, int start, int delete_count, double_linked_list* add_remove,int remove);



/* freeing memory */

void double_linked_list_free(double_linked_list** root);
void double_linked_list_free_node(double_linked_list** root, double_linked_list* node);

/* Mutating list */

double double_linked_list_pop(double_linked_list** root);
double double_linked_list_remove_index(double_linked_list** root, int index);
double double_linked_list_shift(double_linked_list** root);
void double_linked_list_change_element(double_linked_list** root, int index, double  new_data);
void double_linked_list_flip(double_linked_list** root);
void double_linked_list_push(double_linked_list** root, double data);
void double_linked_list_unshift(double_linked_list** root,double  data);
void double_linked_list_insert_at(double_linked_list** root, int index, double  new_data);
// void *double_linked_list_remove_duplicates(double_linked_list** root);

/* Utility functions */

int double_linked_list_length(double_linked_list* root);
int double_linked_list_every(double_linked_list* root, int f());
int double_linked_list_find_index(double_linked_list* root, int f());
int double_linked_list_find_index_by_value(double_linked_list* root, int value);
int double_linked_list_find_last_index(double_linked_list* root, int f());
int double_linked_list_includes(double_linked_list* root, double value);
int double_linked_list_some(double_linked_list* root, int f());
double double_linked_list_foldr(double_linked_list* root, double f(), double  start_value);
double double_linked_list_foldl(double_linked_list* root, double f(),double  start_value);
double double_linked_list_find(double_linked_list* root, int f());
double double_linked_list_find_last(double_linked_list* root, int f());
double double_linked_list_at(double_linked_list* root, int index);
double double_linked_list_for_each(double_linked_list* root, double f());
double *double_linked_list_to_array(double_linked_list* root);
void double_linked_list_print(double_linked_list* root);
void double_linked_list_sort(double_linked_list** root);

/* All functions are in order of return type:*/


/*
*       type integer linked list
*/


/* Creating new linked lists  */

int_linked_list *int_linked_list_create_node(int data);
int_linked_list *int_linked_list_array_to_list(int array[],int size);
int_linked_list *int_linked_list_concat(int_linked_list* list_one_root, int_linked_list* list_two_root);
int_linked_list *int_linked_list_filter(int_linked_list* root, int f());
int_linked_list *int_linked_list_fill(int_linked_list* root, int length,int value,int new_list);
int_linked_list *int_linked_list_map(int_linked_list* root, int f());
int_linked_list *int_linked_list_cpy(int_linked_list* root);
int_linked_list *int_linked_list_cpy_within(int_linked_list* root, int left, int right);
int_linked_list *int_linked_list_slice(int_linked_list* root, int left, int right);
int_linked_list *int_linked_list_splice(int_linked_list** root, int start, int delete_count, int_linked_list* add_remove,int remove);


/* freeing memory */

void int_linked_list_free(int_linked_list** root);
void int_linked_list_free_node(int_linked_list** root, int_linked_list* node);

/* Mutating list */

int int_linked_list_pop(int_linked_list** root);
int int_linked_list_remove_index(int_linked_list** root, int index);
int int_linked_list_shift(int_linked_list** root);
void int_linked_list_change_element(int_linked_list** root, int index, int new_data);
void int_linked_list_flip(int_linked_list** root);
void int_linked_list_push(int_linked_list** root, int data);
void int_linked_list_unshift(int_linked_list** root,int data);
void int_linked_list_insert_at(int_linked_list** root, int index, int new_data);

/* Utility functions */

int int_linked_list_length(int_linked_list* root);
int int_linked_list_every(int_linked_list* root, int f());
int int_linked_list_for_each(int_linked_list* root, int f());
int *int_linked_list_to_array(int_linked_list* root);
int int_linked_list_find_index(int_linked_list* root, int f());
int int_linked_list_find_index_by_value(int_linked_list* root, int value);
int int_linked_list_find(int_linked_list* root, int f());
int int_linked_list_find_last(int_linked_list* root, int f());
int int_linked_list_find_last_index(int_linked_list* root, int f());
int int_linked_list_at(int_linked_list* root, int index);
int int_linked_list_includes(int_linked_list* root, int value);
int int_linked_list_foldr(int_linked_list* root, int f(), int start_value);
int int_linked_list_foldl(int_linked_list* root, int f(),int start_value);
int int_linked_list_some(int_linked_list* root, int f());
void int_linked_list_print(int_linked_list* root);
void int_linked_list_sort(int_linked_list** root);

/* All functions are in order of return type:*/


/*
*       type char linked list
*/


// /* Creating new linked lists  */

char_linked_list *char_linked_list_create_node(char *data);
char_linked_list *char_linked_list_array_to_list(char *array[],int size);
char_linked_list *char_linked_list_concat(char_linked_list* list_one_root, char_linked_list* list_two_root);
char_linked_list *char_linked_list_filter(char_linked_list* root, int  f());
char_linked_list *char_linked_list_fill(char_linked_list* root, int length, char *value,int new_list);
// char_linked_list *char_linked_list_map(char_linked_list* root, char f());
char_linked_list *char_linked_list_cpy(char_linked_list* root);
char_linked_list *char_linked_list_cpy_within(char_linked_list* root, int left, int right);
char_linked_list *char_linked_list_slice(char_linked_list* root, int left, int right);
char_linked_list *char_linked_list_splice(char_linked_list** root, int start, int delete_count, char_linked_list* add_remove,int remove);

// /* freeing memory */

void char_linked_list_free(char_linked_list** root);
void char_linked_list_free_node(char_linked_list** root, char_linked_list* node);

// /* Mutating list */

char *char_linked_list_pop(char_linked_list** root);
char *char_linked_list_shift(char_linked_list** root);
char *char_linked_list_remove_index(char_linked_list** root, int index);
void char_linked_list_change_element(char_linked_list** root, int index, char *new_data);
void char_linked_list_flip(char_linked_list** root);
void char_linked_list_push(char_linked_list** root, char* data);
void char_linked_list_unshift(char_linked_list** root,char *data);
void char_linked_list_insert_at(char_linked_list** root, char index, char *new_data);

// /* Utility functions */

char *char_linked_list_to_array(char_linked_list* root);
char *char_linked_list_at(char_linked_list* root, int index);
char *char_linked_list_find(char_linked_list* root, int f());
char *char_linked_list_find_last(char_linked_list* root, int f());
int char_linked_list_length(char_linked_list* root);
int char_linked_list_every(char_linked_list* root, int f());
// int char_linked_list_for_each(char_linked_list* root, int f()); TODO
int char_linked_list_find_index(char_linked_list* root, int f());
int char_linked_list_find_last_index(char_linked_list* root, int f());
int char_linked_list_includes(char_linked_list* root, char *value);
// int int_linked_list_foldr(int_linked_list* root, int f(), int start_value);
// int int_linked_list_foldl(int_linked_list* root, int f(),int start_value);
int char_linked_list_some(char_linked_list* root, int f());
void char_linked_list_print(char_linked_list* root);
// void int_linked_list_sort(int_linked_list** root);

// /*
// *       Non specific functions
// */

// int cpy_func (int i);
// void int_mergeSort(int arr[], int l, int r);
// void int_merge(int arr[], int l, int m, int r);
// void double_mergeSort(double arr[], int l, int r);
// void double_merge(double arr[], int l, int m, int r);
// void print_Array(int array[], int size);

/*
*       Non specific functions
*/

int cpy_func (int i);
void int_mergeSort(int arr[], int l, int r);
void int_merge(int arr[], int l, int m, int r);
void double_mergeSort(double arr[], int l, int r);
void double_merge(double arr[], int l, int m, int r);
void print_Array(int array[], int size);

/*
*       Conversions
*/

int_linked_list *cpy_double_list_to_int(double_linked_list* root);
double_linked_list *cpy_int_list_to_double(int_linked_list* root);
void convert_double_list_to_int(double_linked_list** root);
void convert_int_list_to_double(int_linked_list** root);



double_linked_list *double_linked_list_create_node(double data){

        double_linked_list* node = malloc(sizeof(double_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

double_linked_list *double_linked_list_array_to_list(double  array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return double_linked_list_create_node(0);
        }


        double_linked_list *root = double_linked_list_create_node(array[0]);

       for(int i = 1; i < size;i++){
                double_linked_list_push(&root,array[i]);
       }

        return root;
}

double_linked_list *double_linked_list_concat(double_linked_list* list_one_root, double_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = double_linked_list_length(list_one_root)+double_linked_list_length(list_two_root);

        double_linked_list* concatinated_tree = double_linked_list_cpy(list_one_root);
        double_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = double_linked_list_cpy(list_two_root);

        return concatinated_tree;

}

double_linked_list *double_linked_list_filter(double_linked_list* root, int  f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        double_linked_list* filtered_array;
        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = double_linked_list_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        double_linked_list_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

double_linked_list *double_linked_list_fill(double_linked_list* root, int length,double value,double new_list){
        if(!new_list){
                double_linked_list* cur = root;
                if(double_linked_list_length(root) < length){
                        for(int i = 0; i < double_linked_list_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = double_linked_list_length(root); i < length ; i++)
                        {
                                double_linked_list_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = double_linked_list_create_node(value);
                for (int i = 1; i < length; i++){
                        double_linked_list_push(&root,value);
                }
        }

        return root;
}

double_linked_list *double_linked_list_map(double_linked_list* root, double f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        double_linked_list* filtered_array;
        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(once IS 0){
                        filtered_array = double_linked_list_create_node(f(cur->data));
                        once = 1;
                } else if(once IS 1){
                        double_linked_list_push(&filtered_array,f(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

double_linked_list *double_linked_list_cpy(double_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return double_linked_list_filter(root,cpy_func);
}

double_linked_list *double_linked_list_cpy_within(double_linked_list* root, int left, int right){
        if(root IS NULL){
                return double_linked_list_create_node(-1);
        }

        if(left > right){
                return double_linked_list_create_node(-1);
        } else if (right > double_linked_list_length(root)){
                return double_linked_list_create_node(-1);
        } else if(left < 0 OR right < 0){
                return double_linked_list_create_node(-1);
        }

        double_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = double_linked_list_create_node(double_linked_list_at(root,i));
                        once = 1;
                } else {
                        double_linked_list_push(&copied,double_linked_list_at(root,i));
                }
        }

        return copied;
}

double_linked_list *double_linked_list_slice(double_linked_list* root, int left, int right){
        
        if(root IS NULL){
                return double_linked_list_create_node(-1);
        }


        if(left > right){
                return double_linked_list_create_node(-1);
        } else if (right > double_linked_list_length(root)){
                return double_linked_list_create_node(-1);
        } else if(left < 0 OR right < 0){
                return double_linked_list_create_node(-1);
        }

        double_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = double_linked_list_create_node(double_linked_list_at(root,i));
                        once = 1;
                } else {
                        double_linked_list_push(&sliced,double_linked_list_at(root,i));
                }
        }

        return sliced;
}

double_linked_list *double_linked_list_splice(double_linked_list** root, int start, int delete_count, double_linked_list* add_remove,int remove){

        double_linked_list* cur = *root;
        double_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return double_linked_list_create_node(-1);
        } else if(delete_count > double_linked_list_length(*root)){
                return double_linked_list_create_node(-1);
        }



        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                                deleted = double_linked_list_create_node(double_linked_list_at(*root,start));
                                double_linked_list_remove_index(root,start);
                                once = 1;
                        } else {
                                double_linked_list_push(&deleted,double_linked_list_at(*root,start));
                                double_linked_list_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < double_linked_list_length(add_remove); i++){
                                double_linked_list_insert_at(root,start,double_linked_list_at(add_remove,i));
                                start++;
                        }
                }
                
                return deleted;

        } else {
                for(int i = 0; i < double_linked_list_length(add_remove); i++){
                        double_linked_list_insert_at(root,start,double_linked_list_at(add_remove,i));
                        start++;
                }
                return double_linked_list_create_node(0);
        }


}



double double_linked_list_pop(double_linked_list** root){

        if(*root IS NULL){
                return -1;
        }

        double  value;
        double_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        double_linked_list_free_node(root,cur);

        return value;

}

double double_linked_list_remove_index(double_linked_list** root, int index){
        if(root IS NULL){
                return -1;
        }

        if(index IS 0 OR index > double_linked_list_length(*root)){
                return -1;
        }

        double_linked_list* cur = *root;
        *root = cur;

        int value;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        value = cur->data;

        double_linked_list_free_node(root,cur);

        return (value);

}

double double_linked_list_shift(double_linked_list** root){
        
        double_linked_list_flip(root);
        double  value = double_linked_list_pop(root);
        double_linked_list_flip(root);
        return value;
}

void double_linked_list_change_element(double_linked_list** root, int index, double  new_data){
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

void double_linked_list_flip(double_linked_list** root){
        

        double_linked_list* new;
        int once = 0;
        for(int i = double_linked_list_length(*root); i > 0; i--){
                if(once IS 0){
                        new = double_linked_list_create_node(double_linked_list_pop(root));
                        once = 1;
                } else {
                        double_linked_list_push(&new,double_linked_list_pop(root));
                }
        }

        *root = new;
}

void double_linked_list_push(double_linked_list** root, double data){

        
        if(root NOT_EQUAL NULL){
                double_linked_list* node = double_linked_list_create_node(data);
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

void double_linked_list_unshift(double_linked_list** root,double  data){


        if(*root IS NULL){
                return;
        }

        double_linked_list* new_root = double_linked_list_create_node(data);
        new_root->next = *root;
        *root = new_root;
}

void double_linked_list_insert_at(double_linked_list** root, int index, double  new_data){

        if(root IS NULL){
                return;
        }

        if(index > double_linked_list_length(*root)){
                return;
        }


        if(index IS 0){
                double_linked_list_unshift(root,new_data);
        } else {
                double_linked_list* temp_first_part = double_linked_list_slice(*root,0,index);
                double_linked_list* temp_last_part = double_linked_list_slice(*root,index,double_linked_list_length(*root));
                double_linked_list_push(&temp_first_part,new_data);
                *root = double_linked_list_concat(temp_first_part,temp_last_part);
        }

        return;

}

// void *double_linked_list_remove_duplicates(double_linked_list** root){
//         if(root == NULL){
//                 return root;
//         }


//         double_linked_list* dupes = double_linked_list_cpy(*root);
//         double_linked_list* not_dupes;
//         int length = double_linked_list_length(*root);
//         int once = 0;
//         int index;
//         double temp;


//         for (int i = 0; i < length; i++)
//         {

//                 temp = double_linked_list_shift(&dupes);
//                 if(once IS 0 ){
//                         not_dupes = double_linked_list_create_node(temp);
//                         once = 1;
//                 } else if (once IS 1)
//                 {
//                         double_linked_list_push(&not_dupes,temp);
//                 }

//                 for (int j = 0; i < length; j++){
//                         index = double_linked_list_find_index_by_value(dupes,temp);
//                         if(index >= 0){
//                                 double_linked_list_remove_index(&dupes,index);
//                         } else {
//                                 break;
//                         }
//                 }


//         }


//         *root = not_dupes;

// }




void double_linked_list_free(double_linked_list** root){

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

void double_linked_list_free_node(double_linked_list** root, double_linked_list* node){


        if(*root IS NULL){
                double_linked_list_free(root);
                return;
        }

        double_linked_list* cur = *root;
        double_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(double_linked_list_length(*root)-double_linked_list_length(node));i++)
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


int double_linked_list_length(double_linked_list* root){
        int length = 0;
        if(root IS NULL){
                return length;
        }

        double_linked_list* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;


}

int double_linked_list_every(double_linked_list* root, int f()){

        if(root IS NULL){
                return -1;
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

int double_linked_list_find_index(double_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int double_linked_list_find_index_by_value(double_linked_list* root, int value){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}



int double_linked_list_find_last_index(double_linked_list* root, int f()){

        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int double_linked_list_includes(double_linked_list* root, double value){
        if(root IS NULL){
                return -1;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }

        return 0;


}

int double_linked_list_some(double_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < double_linked_list_length(root); i++)
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

double double_linked_list_foldr(double_linked_list* root, double f(),double  start_value){
        if(root IS NULL){
                return double_linked_list_at(root,0);
        }

        if(start_value < 0){
                return double_linked_list_at(root,0);
        }

        if(double_linked_list_length(root) < 2){
                return double_linked_list_at(root,0);
        }

        if(double_linked_list_length(root) IS 2){
                return f(double_linked_list_at(root,0), double_linked_list_at(root,1));
        }

        double  accumulator = start_value;

        for (int i = 0; i < double_linked_list_length(root); i++){
                accumulator = f(accumulator,double_linked_list_at(root,i));
        }

        return accumulator;
}

double double_linked_list_foldl(double_linked_list* root, double f(),double start_value){
        if(root IS NULL){
                return double_linked_list_at(root,0);
        }

        if(start_value < 0){
                return double_linked_list_at(root,0);
        }

        if(double_linked_list_length(root) < 2){
                return double_linked_list_at(root,0);
        }

        if(double_linked_list_length(root) IS 2){
                return f(double_linked_list_at(root,1), double_linked_list_at(root,0));
        }

        double  accumulator = start_value;

        for (int i = double_linked_list_length(root)-1; i >= 0; i--){
                accumulator = f(accumulator,double_linked_list_at(root,i));
        }

        return accumulator;
}

double double_linked_list_find(double_linked_list* root, int f()){

        if(root IS NULL){
                return -1.0;
        }

        double_linked_list* cur = root;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return -1.0;
}

double double_linked_list_find_last(double_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        double_linked_list* cur = root;
        double value = -1;

        for (int i = 0; i < double_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

double double_linked_list_at(double_linked_list* root, int index){
        if (root IS NULL){
                return -1;
        }

        if(index IS 0){
                return root->data;
        }


        double_linked_list* cur = root;

        if(double_linked_list_length(root) < index){
                return -1;
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

double double_linked_list_for_each(double_linked_list* root, double f()){
        if (root IS NULL){
                return -1;
        }

        double  *arr = double_linked_list_to_array(root);
        double  accumulator = 0;
        int once = 0;

        for(int i = 0; i < double_linked_list_length(root) + 1; i++){
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

double *double_linked_list_to_array(double_linked_list* root){

        if(root IS NULL){
                return (double *)-1;
        }

        int length = double_linked_list_length(root);
        double  *arr = malloc(sizeof(double_linked_list));

        double_linked_list* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
        };

        return arr;
}

void double_linked_list_print(double_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %f\n", root->data);
        printf("Next node: \n");
        double_linked_list_print(root->next);
}

void double_linked_list_sort(double_linked_list** root){ /* BROKEn*/

        if(*root IS NULL){
                return;
        }


        double_linked_list* cur = *root;

        double *arr = double_linked_list_to_array(cur);

        double_mergeSort(arr,0,double_linked_list_length(cur)-1);

        *root = cur;
        for(int i = 0; i < double_linked_list_length(*root);i++){
                cur->data = arr[i];
                cur = cur->next;
        }
        double_linked_list_print(*root);
        return;
}


int_linked_list *int_linked_list_create_node(int data){

        int_linked_list* node = malloc(sizeof(int_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

int_linked_list *int_linked_list_array_to_list(int array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return int_linked_list_create_node(0);
        }


        int_linked_list *root = int_linked_list_create_node(array[0]);

       for(int i = 1; i < size;i++){
                int_linked_list_push(&root,array[i]);
       }

        return root;
}

int_linked_list *int_linked_list_concat(int_linked_list* list_one_root, int_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = int_linked_list_length(list_one_root)+int_linked_list_length(list_two_root);

        int_linked_list* concatinated_tree = int_linked_list_cpy(list_one_root);
        int_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = int_linked_list_cpy(list_two_root);

        return concatinated_tree;

}

int_linked_list *int_linked_list_filter(int_linked_list* root, int f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = int_linked_list_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        int_linked_list_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *int_linked_list_fill(int_linked_list* root, int length,int value,int new_list){
        if(!new_list){
                int_linked_list* cur = root;
                if(int_linked_list_length(root) < length){
                        for(int i = 0; i < int_linked_list_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = int_linked_list_length(root); i < length ; i++)
                        {
                                int_linked_list_push(&root,value);
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
                        int_linked_list_push(&root,value);
                }
        }

        return root;
}

int_linked_list *int_linked_list_map(int_linked_list* root, int f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        int_linked_list* filtered_array;
        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(once IS 0){
                        filtered_array = int_linked_list_create_node(f(cur->data));
                        once = 1;
                } else if(once IS 1){
                        int_linked_list_push(&filtered_array,f(cur->data));
                }
                cur = cur->next;
        }

        return filtered_array;

}

int_linked_list *int_linked_list_cpy(int_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return int_linked_list_filter(root,cpy_func);
}

int_linked_list *int_linked_list_cpy_within(int_linked_list* root, int left, int right){
        if(root IS NULL){
                return int_linked_list_create_node(-1);
        }


        if(left > right){
                return int_linked_list_create_node(-1);
        } else if (right > int_linked_list_length(root)){
                return int_linked_list_create_node(-1);
        } else if(left < 0 OR right < 0){
                return int_linked_list_create_node(-1);
        }

        int_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = int_linked_list_create_node(int_linked_list_at(root,i));
                        once = 1;
                } else {
                        int_linked_list_push(&copied,int_linked_list_at(root,i));
                }
        }

        return copied;
}

int_linked_list *int_linked_list_slice(int_linked_list* root, int left, int right){
        
        if(root IS NULL){
                return int_linked_list_create_node(-1);
        }


        if(left > right){
                return int_linked_list_create_node(-1);
        } else if (right > int_linked_list_length(root)){
                return int_linked_list_create_node(-1);
        } else if(left < 0 OR right < 0){
                return int_linked_list_create_node(-1);
        }

        int_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = int_linked_list_create_node(int_linked_list_at(root,i));
                        once = 1;
                } else {
                        int_linked_list_push(&sliced,int_linked_list_at(root,i));
                }
        }

        return sliced;
}

int_linked_list *int_linked_list_splice(int_linked_list** root, int start, int delete_count, int_linked_list* add_remove,int remove){
        
        int_linked_list* cur = *root;
        int_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return int_linked_list_create_node(-1);
        } else if(delete_count > int_linked_list_length(*root)){
                return int_linked_list_create_node(-1);
        }



        

        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                                deleted = int_linked_list_create_node(int_linked_list_at(*root,start));
                                int_linked_list_remove_index(root,start);
                                once = 1;
                        } else {
                                int_linked_list_push(&deleted,int_linked_list_at(*root,start));
                                int_linked_list_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < int_linked_list_length(add_remove); i++){
                                int_linked_list_insert_at(root,start,int_linked_list_at(add_remove,i));
                                start++;
                        }
                }
                
                return deleted;

        } else {
                for(int i = 0; i < int_linked_list_length(add_remove); i++){
                        int_linked_list_insert_at(root,start,int_linked_list_at(add_remove,i));
                        start++;
                }
                return int_linked_list_create_node(0);
        }


}



void int_linked_list_free(int_linked_list** root){

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

void int_linked_list_free_node(int_linked_list** root, int_linked_list* node){


        if(*root IS NULL){
                int_linked_list_free(root);
                return;
        }

        int_linked_list* cur = *root;
        int_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(int_linked_list_length(*root)-int_linked_list_length(node));i++)
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


int int_linked_list_pop(int_linked_list** root){

        if(*root IS NULL){
                return -1;
        }

        int value;
        int_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        int_linked_list_free_node(root,cur);

        return value;

}

int int_linked_list_remove_index(int_linked_list** root, int index){
        if(root IS NULL){
                return -1;
        }

        if(index IS 0 OR index > int_linked_list_length(*root)){
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

void int_linked_list_flip(int_linked_list** root){
        

        int_linked_list* new;
        int once = 0;
        for(int i = int_linked_list_length(*root); i > 0; i--){
                if(once IS 0){
                        new = int_linked_list_create_node(int_linked_list_pop(root));
                        once = 1;
                } else {
                        int_linked_list_push(&new,int_linked_list_pop(root));
                }
        }

        *root = new;
}

void int_linked_list_push(int_linked_list** root, int data){

        
        if(root NOT_EQUAL NULL){
                int_linked_list* node = int_linked_list_create_node(data);
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

void int_linked_list_unshift(int_linked_list** root,int data){


        if(*root IS NULL){
                return;
        }

        int_linked_list* new_root = int_linked_list_create_node(data);
        new_root->next = *root;
        *root = new_root;
}

void int_linked_list_insert_at(int_linked_list** root, int index, int new_data){

        if(root IS NULL){
                return;
        }

        if(index > int_linked_list_length(*root)){
                return;
        }


        if(index IS 0){
                int_linked_list_unshift(root,new_data);
        } else {
                int_linked_list* temp_first_part = int_linked_list_slice(*root,0,index);
                int_linked_list* temp_last_part = int_linked_list_slice(*root,index,int_linked_list_length(*root));
                int_linked_list_push(&temp_first_part,new_data);
                *root = int_linked_list_concat(temp_first_part,temp_last_part);
        }

        return;

}


int int_linked_list_length(int_linked_list* root){
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

int int_linked_list_every(int_linked_list* root, int f()){

        if(root IS NULL){
                return -1;
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

int int_linked_list_for_each(int_linked_list* root, int f()){
        if (root IS NULL){
                return -1;
        }

        int *arr = int_linked_list_to_array(root);
        int accumulator = 0;
        int once = 0;

        for(int i = 0; i < int_linked_list_length(root) + 1; i++){
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

int *int_linked_list_to_array(int_linked_list* root){

        if(root IS NULL){
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
        if(root IS NULL){
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

int int_linked_list_find_index_by_value(int_linked_list* root, int value){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int int_linked_list_find(int_linked_list* root, int f()){
        if(root IS NULL){
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
        if(root IS NULL){
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
        
        if(root IS NULL){
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
        if (root IS NULL){
                return -1;
        }

        if(index IS 0){
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
        if(root IS NULL){
                return -1;
        }

        int_linked_list* cur = root;

        for (int i = 0; i < int_linked_list_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }


        return 0;


}

int int_linked_list_foldr(int_linked_list* root, int f(),int start_value){
        if(root IS NULL){
                return int_linked_list_at(root,0);
        }

        if(start_value < 0){
                return int_linked_list_at(root,0);
        }

        if(int_linked_list_length(root) < 2){
                return int_linked_list_at(root,0);
        }

        if(int_linked_list_length(root) IS 2){
                return f(int_linked_list_at(root,0), int_linked_list_at(root,1));
        }

        int accumulator = start_value;
        int once = 0;

        for (int i = 0; i < int_linked_list_length(root); i++){
                accumulator = f(accumulator,int_linked_list_at(root,i));
        }

        return accumulator;
}

int int_linked_list_foldl(int_linked_list* root, int f(),int start_value){
        if(root IS NULL){
                return int_linked_list_at(root,0);
        }

        if(start_value < 0){
                return int_linked_list_at(root,0);
        }

        if(int_linked_list_length(root) < 2){
                return int_linked_list_at(root,0);
        }

        if(int_linked_list_length(root) IS 2){
                return f(int_linked_list_at(root,1), int_linked_list_at(root,0));
        }

        int accumulator = start_value;
        int once = 0;

        for (int i = int_linked_list_length(root)-1; i >= 0; i--){
                accumulator = f(accumulator,int_linked_list_at(root,i));
        }

        return accumulator;
}

int int_linked_list_some(int_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        int_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < int_linked_list_length(root); i++)
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

void int_linked_list_print(int_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %d\n", root->data);
        printf("Next node: \n");
        int_linked_list_print(root->next);
}

void int_linked_list_sort(int_linked_list** root){ /* BROKEn*/

        if(*root IS NULL){
                return;
        }


        int_linked_list* cur = *root;

        int *arr = int_linked_list_to_array(cur);

        int_mergeSort(arr,0,int_linked_list_length(cur)-1);

        *root = cur;
        for(int i = 0; i < int_linked_list_length(*root);i++){
                cur->data = arr[i];
                cur = cur->next;
        }
        int_linked_list_print(*root);
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

void print_Array(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int_linked_list *cpy_double_list_to_int(double_linked_list* root) {
        if(root IS NULL){
                return int_linked_list_create_node(0);
        }

        int_linked_list* cur = int_linked_list_create_node(0);
        cur->data = (int)double_linked_list_at(root, 0);

        for (int i = 1; i < double_linked_list_length(root); i++)
        {
                int_linked_list_push(&cur,(int)double_linked_list_at(root,i));
        }

        return cur;
}

double_linked_list *cpy_int_list_to_double(int_linked_list* root) {

        if(root IS NULL){
                return double_linked_list_create_node(0);
        }

        double_linked_list* cur = double_linked_list_create_node(0);
        cur->data = (double)int_linked_list_at(root, 0);

        for (int i = 1; i < int_linked_list_length(root); i++)
        {
                double_linked_list_push(&cur,(double)int_linked_list_at(root,i));
        }

        return cur;
}

/* A warning will appear when this functions is used, you can ingore it */
void convert_double_list_to_int(double_linked_list** root){

        if(root IS NULL){
                return;
        }

        int_linked_list* cur = int_linked_list_create_node(0);
        cur->data = (int)double_linked_list_at(*root, 0);

        for (int i = 1; i < double_linked_list_length(*root); i++)
        {
                int_linked_list_push(&cur,(int)double_linked_list_at(*root,i));
        }

        *root = cur;
        return;
}

/* A warning will appear when this functions is used, you can ingore it */
void convert_int_list_to_double(int_linked_list** root){

        if(root IS NULL){
                return;
        }

        double_linked_list* cur = double_linked_list_create_node(0);
        cur->data = (double)int_linked_list_at(*root, 0);

        for (int i = 1; i < int_linked_list_length(*root); i++)
        {
                double_linked_list_push(&cur,(double)int_linked_list_at(*root,i));
        }

        *root = cur;
        return;
}



char_linked_list *char_linked_list_create_node(char *data){

        char_linked_list* node = malloc(sizeof(char_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

char_linked_list *char_linked_list_array_to_list(char *array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return char_linked_list_create_node("ERROR");
        }


        char_linked_list *root = char_linked_list_create_node(array[0]);

       for(int i = 1; i < size;i++){
                char_linked_list_push(&root,array[i]);
       }

        return root;
}

char_linked_list *char_linked_list_concat(char_linked_list* list_one_root, char_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = char_linked_list_length(list_one_root)+char_linked_list_length(list_two_root);

        char_linked_list* concatinated_tree = char_linked_list_cpy(list_one_root);
        char_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = char_linked_list_cpy(list_two_root);

        return concatinated_tree;

}

char_linked_list *char_linked_list_filter(char_linked_list* root, int  f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        char_linked_list* filtered_array;
        char_linked_list* cur = root;

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = char_linked_list_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        char_linked_list_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

char_linked_list *char_linked_list_fill(char_linked_list* root, int length, char *value,int new_list){
        if(!new_list){
                char_linked_list* cur = root;
                if(char_linked_list_length(root) < length){
                        for(int i = 0; i < char_linked_list_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = char_linked_list_length(root); i < length ; i++)
                        {
                                char_linked_list_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = char_linked_list_create_node(value);
                for (int i = 1; i < length; i++){
                        char_linked_list_push(&root,value);
                }
        }

        return root;
}

// char_linked_list *char_linked_list_map(char_linked_list* root, char f()){

//         if(root IS NULL){
//                 return root;
//         }

//         int once = 0;
//         char_linked_list* filtered_array;
//         char_linked_list* cur = root;

//         for (int i = 0; i < char_linked_list_length(root); i++)
//         {
//                 if(once IS 0){
//                         filtered_array = char_linked_list_create_node(f(cur->data));
//                         once = 1;
//                 } else if(once IS 1){
//                         char_linked_list_push(&filtered_array,char_linked_list_create_node(f(cur->data)));
//                 }
//                 cur = cur->next;
//         }

//         return filtered_array;

// }

char_linked_list *char_linked_list_cpy(char_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return char_linked_list_filter(root,cpy_func);
}

char_linked_list *char_linked_list_cpy_within(char_linked_list* root, int left, int right){
        if(root IS NULL){
                return char_linked_list_create_node("ERROR");
        }


        if(left > right){
                return char_linked_list_create_node("ERROR");
        } else if (right > char_linked_list_length(root)){
                return char_linked_list_create_node("ERROR");
        } else if(left < 0 OR right < 0){
                return char_linked_list_create_node("ERROR");
        }

        char_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = char_linked_list_create_node(char_linked_list_at(root,i));
                        once = 1;
                } else {
                        char_linked_list_push(&copied,char_linked_list_at(root,i));
                }
        }

        return copied;
}

char_linked_list *char_linked_list_slice(char_linked_list* root, int left, int right){
        
        if(root IS NULL){
                return char_linked_list_create_node("ERROR");
        }


        if(left > right){
                return char_linked_list_create_node("ERROR");
        } else if (right > char_linked_list_length(root)){
                return char_linked_list_create_node("ERROR");
        } else if(left < 0 OR right < 0){
                return char_linked_list_create_node("ERROR");
        }

        char_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = char_linked_list_create_node(char_linked_list_at(root,i));
                        once = 1;
                } else {
                        char_linked_list_push(&sliced,char_linked_list_at(root,i));
                }
        }

        return sliced;
}

char_linked_list *char_linked_list_splice(char_linked_list** root, int start, int delete_count, char_linked_list* add_remove,int remove){

        char_linked_list* cur = *root;
        char_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return char_linked_list_create_node("ERROR");
        } else if(delete_count > char_linked_list_length(*root)){
                return char_linked_list_create_node("ERROR");
        }



        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                               
                                deleted = char_linked_list_create_node(char_linked_list_at(*root,start));
                                char_linked_list_remove_index(root,start);
                                once = 1;
                        } else {
                                char_linked_list_push(&deleted,char_linked_list_at(*root,start));
                                char_linked_list_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < char_linked_list_length(add_remove); i++){
                                char_linked_list_insert_at(root,start,char_linked_list_at(add_remove,i));
                                start++;
                        }
                }
                
                return deleted;

        } else {
                for(int i = 0; i < char_linked_list_length(add_remove); i++){
                        char_linked_list_insert_at(root,start,char_linked_list_at(add_remove,i));
                        start++;
                }
                return char_linked_list_create_node(0);
        }


}


void char_linked_list_free(char_linked_list** root){

        char_linked_list* cur = *root;

        if(cur->next IS NULL){
                free(root);
        }

        char_linked_list* prev = *root;

        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }

}

void char_linked_list_free_node(char_linked_list** root, char_linked_list* node){


        if(*root IS NULL){
                char_linked_list_free(root);
                return;
        }

        char_linked_list* cur = *root;
        char_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(char_linked_list_length(*root)-char_linked_list_length(node));i++)
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


char *char_linked_list_pop(char_linked_list** root){

        if(*root IS NULL){
                return "ERROR";
        }


        char *value;

        char_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        char_linked_list_free_node(root,cur);

        return value;

}

char *char_linked_list_shift(char_linked_list** root){

        char_linked_list_flip(root);
        char *value = char_linked_list_pop(root);
        char_linked_list_flip(root);
        return value;
}

char *char_linked_list_remove_index(char_linked_list** root, int index){
        if(root IS NULL){
                return "ERROR";
        }

        if(index IS 0 OR index > char_linked_list_length(*root)){
                return "ERROR";
        }

        char_linked_list* cur = *root;
        *root = cur;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        char *value = cur->data;

        char_linked_list_free_node(root,cur);

        return value;

}

void char_linked_list_change_element(char_linked_list** root, int index, char *new_data){
        if(*root IS NULL){
                return;
        }

        char_linked_list* cur = *root;
        *root = cur;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        cur->data = new_data;
        return;
}

void char_linked_list_flip(char_linked_list** root){

        char_linked_list* flipped;
        int once = 0;

        for(int i = char_linked_list_length(*root); i > 0; i--){
                if(once IS 0){
                        flipped = char_linked_list_create_node( char_linked_list_pop(root));
                        once = 1;
                } else {
                        char_linked_list_push(&flipped,char_linked_list_pop(root));
                }
        }

        *root = flipped;
        return;
}

void char_linked_list_push(char_linked_list** root,char* data){

        if(root NOT_EQUAL NULL){
                char_linked_list* node = char_linked_list_create_node(data);
                char_linked_list* cur = *root;
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

void char_linked_list_unshift(char_linked_list** root,char *data){

        if(*root IS NULL){
                return;
        }

        char_linked_list* new_root = char_linked_list_create_node(data);
        new_root->next = *root;
        *root = new_root;
        return;
}

void char_linked_list_insert_at(char_linked_list** root, char index, char *new_data){

        if(root IS NULL){
                return;
        }

        if(index > char_linked_list_length(*root)){
                return;
        }


        if(index IS 0){
                char_linked_list_unshift(root,new_data);
        } else {
                char_linked_list* temp_first_part = char_linked_list_slice(*root,0,index);
                char_linked_list* temp_last_part = char_linked_list_slice(*root,index,char_linked_list_length(*root));
                char_linked_list_push(&temp_first_part,new_data);
                *root = char_linked_list_concat(temp_first_part,temp_last_part);
        }

        return;

}


// char *char_linked_list_to_array(char_linked_list* root){ /*TODO*/

//         if(root IS NULL){
//                 return "ERROR";
//         }

//         int length = char_linked_list_length(root);
//         char *arr = malloc(sizeof(char_linked_list));

//         char_linked_list* cur = root;
//         for(int i = 0; i < length; i++){
//                 arr[i] = cur->data;
//                 cur = cur->next;
//         };

//         return arr;
// }

char* char_linked_list_at(char_linked_list* root, int index){
        if (root IS NULL){
                return "ERROR";
        }

        if(index IS 0){
                return root->data;
        }


        char_linked_list* cur = root;

        if(char_linked_list_length(root) < index){
                return "ERROR";
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

char* char_linked_list_find(char_linked_list* root, int f()){

        if(root IS NULL){
                return "ERROR";
        }

        char_linked_list* cur = root;

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return "ERROR";
}

char *char_linked_list_find_last(char_linked_list* root, int f()){
        if(root IS NULL){
                return "ERROR";
        }

        char_linked_list* cur = root;
        char *value = "ERROR";

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

int char_linked_list_length(char_linked_list* root){
        int length = 0;
        if(root IS NULL){
                return length;
        }

        char_linked_list* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;

}

int char_linked_list_every(char_linked_list* root, int f()){

        if(root IS NULL){
                return -1;
        }

        char_linked_list* cur = root;

        while (cur->next NOT_EQUAL NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

// int char_linked_list_for_each(char_linked_list* root, int f()){
//         if (root IS NULL){
//                 return -1;
//         }

//         char *arr = char_linked_list_to_array(root);
//         int accumulator = 0;
//         int once = 0;

//         for(int i = 0; i < char_linked_list_length(root) + 1; i++){
//                 if(i IS 2){
//                         accumulator += f(arr[i-2],arr[i-1]);
//                         once = 1;
//                 } else if(once IS 1){
//                         accumulator = f(accumulator,arr[i-1]);
//                 }
//         }

//         free(arr);
//         return accumulator;
// }

int char_linked_list_find_index(char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int char_linked_list_find_last_index(char_linked_list* root, int f()){
        
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int char_linked_list_includes(char_linked_list* root, char* value){
        if(root IS NULL){
                return -1;
        }

        char_linked_list* cur = root;

        for (int i = 0; i < char_linked_list_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }


        return 0;


}

// int int_linked_list_foldr(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return int_linked_list_at(root,0);
//         }

//         if(start_value < 0){
//                 return int_linked_list_at(root,0);
//         }

//         if(int_linked_list_length(root) < 2){
//                 return int_linked_list_at(root,0);
//         }

//         if(int_linked_list_length(root) IS 2){
//                 return f(int_linked_list_at(root,0), int_linked_list_at(root,1));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = 0; i < int_linked_list_length(root); i++){
//                 accumulator = f(accumulator,int_linked_list_at(root,i));
//         }

//         return accumulator;
// }

// int int_linked_list_foldl(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return int_linked_list_at(root,0);
//         }

//         if(start_value < 0){
//                 return int_linked_list_at(root,0);
//         }

//         if(int_linked_list_length(root) < 2){
//                 return int_linked_list_at(root,0);
//         }

//         if(int_linked_list_length(root) IS 2){
//                 return f(int_linked_list_at(root,1), int_linked_list_at(root,0));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = int_linked_list_length(root)-1; i >= 0; i--){
//                 accumulator = f(accumulator,int_linked_list_at(root,i));
//         }

//         return accumulator;
// }

int char_linked_list_some(char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < char_linked_list_length(root); i++)
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

void char_linked_list_print(char_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %s\n", root->data);
        printf("Next node: \n");
        char_linked_list_print(root->next);
}

// void int_linked_list_sort(int_linked_list** root){ /* BROKEn*/

//         if(*root IS NULL){
//                 return;
//         }


//         int_linked_list* cur = *root;

//         int *arr = int_linked_list_to_array(cur);

//         int_mergeSort(arr,0,int_linked_list_length(cur)-1);

//         *root = cur;
//         for(int i = 0; i < int_linked_list_length(*root);i++){
//                 cur->data = arr[i];
//                 cur = cur->next;
//         }
//         int_linked_list_print(*root);
//         return;
// }


key_value_double *kvd_create_pair(char* id, char_linked_list *new_keys, double_linked_list *new_values);
char_linked_list *kvd_keys_to_linked_list(key_value_double* root, char* id);
double_linked_list *kvd_values_to_linked_list(key_value_double* root, char* id);

void kvd_add(key_value_double** root,char* id, char_linked_list *new_keys, double_linked_list *new_values);
void kvd_change_identifer(key_value_double** root, char* id, char* new_id);
void kvd_change_some_identifers(key_value_double** root, char* id, char* new_id);
void kvd_change_all_identifers(key_value_double** root, char* new_id);


key_value_double *kvd_at(key_value_double* root, int index );
int kvd_index_of_identifier(key_value_double* root, char* id);
int kvd_length(key_value_double* root);
int kvd_length_of_keys_at(key_value_double* root,int index);
int kvd_length_of_values_at(key_value_double* root,int index);
void kvd_print(key_value_double* root);



key_value_double *kvd_create_pair(char* id, char_linked_list *new_keys, double_linked_list *new_values){

        key_value_double* pair = malloc(sizeof(key_value_double));

        if(char_linked_list_length(new_keys) NOT_EQUAL double_linked_list_length(new_values)){
                return NULL;
        }

        if(pair NOT_EQUAL NULL){
                pair->identifier = id;
                pair->keys = new_keys;
                pair->values = new_values;
                pair->next = NULL;
        }

        return pair;
}

char_linked_list *kvd_keys_to_linked_list(key_value_double* root, char* id){
        if(root IS NULL){
                return char_linked_list_create_node("ERROR");
        }

        int index = kvd_index_of_identifier(root, id);

        if(index < 0){
                return char_linked_list_create_node("ERROR");
        }

        return kvd_at(root,index)->keys;
}

double_linked_list *kvd_values_to_linked_list(key_value_double* root, char* id){
        if(root IS NULL){
                return char_linked_list_create_node("ERROR");
        }

        int index = kvd_index_of_identifier(root, id);

        if(index < 0){
                return char_linked_list_create_node("ERROR");
        }

        return kvd_at(root,index)->values;
}

void kvd_add(key_value_double** root, char* id, char_linked_list *new_keys, double_linked_list *new_values){

       if(root NOT_EQUAL NULL){
                key_value_double* new_pair = kvd_create_pair(id, new_keys,new_values);
                key_value_double* cur = *root;
                *root = cur;

                if(cur->next NOT_EQUAL NULL){
                        while(cur->next NOT_EQUAL NULL){
                                cur = cur->next;
                        }
                        cur->next = new_pair;
                } else {
                        cur->next = new_pair;
                }
        }


}

void kvd_change_identifer(key_value_double** root, char* id, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < kvd_index_of_identifier(*root,id); i++)
        {
                cur = cur->next;
        }

        cur->identifier = new_id;

        return;
}

void kvd_change_some_identifers(key_value_double** root, char* id, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < kvd_length(*root); i++)
        {
                if(cur->identifier IS id){
                        cur->identifier = new_id;
                }
                cur = cur->next;
        }

        return;
}

void kvd_change_all_identifers(key_value_double** root, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < kvd_length(*root); i++)
        {
                cur->identifier = new_id;
                cur = cur->next;
        }

        return;
}




key_value_double *kvd_at(key_value_double* root, int index){

        if(root IS NULL){
                return kvd_create_pair("ERROR",char_linked_list_create_node("ERROR"),double_linked_list_create_node(-1));
        }

        key_value_double* cur = root;

        if(index == 0){
                return kvd_create_pair(cur->identifier,cur->keys,cur->values);
        } else if (index > kvd_length(root)){
                return kvd_create_pair(cur->identifier,cur->keys,cur->values);
        }


        for (int i = 0; i < index; i++)
        {
                cur = cur->next;
        }

        return kvd_create_pair(cur->identifier,cur->keys,cur->values);

}

int kvd_index_of_identifier(key_value_double* root, char* id){

        if(root IS NULL){
                return -2;
        }

        key_value_double* cur = root;

        for (int i = 0; i < kvd_length(root); i++){
                if(cur->identifier == id){
                        return i;
                }
                cur = cur->next;
        }

        return -1;


}

int kvd_length(key_value_double* root){

        int length = 0;
        if(root IS NULL){
                return length;
        }

        key_value_double* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;

}

int kvd_length_of_keys_at(key_value_double* root,int index){
        if(root IS NULL){
                return -1;
        }

        if (index > kvd_length(root)){
                return -1;
        }


        return char_linked_list_length(kvd_at(root,index)->keys);

}

int kvd_length_of_values_at(key_value_double* root,int index){
        if(root IS NULL){
                return -1;
        }

        if (index > kvd_length(root)){
                return -1;
        }


        return char_linked_list_length(kvd_at(root,index)->keys);
}

void kvd_print(key_value_double* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }

        char_linked_list* cur_key = root->keys;
        double_linked_list* cur_values = root->values;
        printf("Identifer: %s \n", root->identifier);
        printf("---- Key value pairs: { ");

        for (int i = 0; i < double_linked_list_length(cur_values); i++){
                printf("{Key: %s, Value: %f}, ",char_linked_list_at(cur_key,i), double_linked_list_at(cur_values,i));
        }
        printf("}\n");

        printf("Next pair: \n");
        kvd_print(root->next);
}
