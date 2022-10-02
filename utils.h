/*
*
*
* Created by Andreas Svanberg Hummelmose, student at AAU
*
* Updated: 02-10-2022
*/

/* TODO optimiser alle methods og lav free methods for KVD */

// #pragma warn -rvl /* return value */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

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

typedef struct single_char_linked_list{
        char data;
        struct single_char_linked_list* next;
} single_char_linked_list;

typedef struct JSON_parse{
        char_linked_list* key;
        char_linked_list* value;
        struct JSON_parse* children;
        struct JSON_parse* next;
} JSON_parse;

/* All functions are in order of return type:*/


/*
*       type double linked list
*/


/* Creating new linked lists  */

double_linked_list *DLL_create_node(double data);
double_linked_list *DLL_array_to_list(double  array[],int size);
double_linked_list *DLL_concat(double_linked_list* list_one_root, double_linked_list* list_two_root);
double_linked_list *DLL_filter(double_linked_list* root, int f());
double_linked_list *DLL_fill(double_linked_list* root, int length,double value,double new_list);
double_linked_list *DLL_map(double_linked_list* root, double f());
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
int DLL_every(double_linked_list* root, int f());
int DLL_find_index(double_linked_list* root, int f());
int DLL_find_index_by_value(double_linked_list* root, int value);
int DLL_find_last_index(double_linked_list* root, int f());
int DLL_includes(double_linked_list* root, double value);
int DLL_some(double_linked_list* root, int f());
double DLL_foldr(double_linked_list* root, double f(), double  start_value);
double DLL_foldl(double_linked_list* root, double f(),double  start_value);
double DLL_find(double_linked_list* root, int f());
double DLL_find_last(double_linked_list* root, int f());
double DLL_at(double_linked_list* root, int index);
double DLL_for_each(double_linked_list* root, double f());
double *DLL_to_array(double_linked_list* root);
void DLL_print(double_linked_list* root);
void DLL_sort(double_linked_list** root);

/* All functions are in order of return type:*/


/*
*       type integer linked list
*/


/* Creating new linked lists  */

int_linked_list *ILL_create_node(int data);
int_linked_list *ILL_array_to_list(int array[],int size);
int_linked_list *ILL_concat(int_linked_list* list_one_root, int_linked_list* list_two_root);
int_linked_list *ILL_filter(int_linked_list* root, int f());
int_linked_list *ILL_fill(int_linked_list* root, int length,int value,int new_list);
int_linked_list *ILL_map(int_linked_list* root, int f());
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
int ILL_every(int_linked_list* root, int f());
int ILL_for_each(int_linked_list* root, int f());
int *ILL_to_array(int_linked_list* root);
int ILL_find_index(int_linked_list* root, int f());
int ILL_find_index_by_value(int_linked_list* root, int value);
int ILL_find(int_linked_list* root, int f());
int ILL_find_last(int_linked_list* root, int f());
int ILL_find_last_index(int_linked_list* root, int f());
int ILL_at(int_linked_list* root, int index);
int ILL_includes(int_linked_list* root, int value);
int ILL_foldr(int_linked_list* root, int f(), int start_value);
int ILL_foldl(int_linked_list* root, int f(),int start_value);
int ILL_some(int_linked_list* root, int f());
void ILL_print(int_linked_list* root);
void ILL_sort(int_linked_list** root);

/* All functions are in order of return type:*/


/*
*       type char linked list
*/


// /* Creating new linked lists  */

char_linked_list *CLL_create_node(char *data);
char_linked_list *CLL_array_to_list(char *array[],int size);
char_linked_list *CLL_concat(char_linked_list* list_one_root, char_linked_list* list_two_root);
char_linked_list *CLL_filter(char_linked_list* root, int  f());
char_linked_list *CLL_fill(char_linked_list* root, int length, char *value,int new_list);
// char_linked_list *CLL_map(char_linked_list* root, char f());
char_linked_list *CLL_cpy(char_linked_list* root);
char_linked_list *CLL_cpy_within(char_linked_list* root, int left, int right);
char_linked_list *CLL_slice(char_linked_list* root, int left, int right);
char_linked_list *CLL_splice(char_linked_list** root, int start, int delete_count, char_linked_list* add_remove,int remove);

// /* freeing memory */

void CLL_free(char_linked_list** root);
void CLL_free_node(char_linked_list** root, char_linked_list* node);

// /* Mutating list */

char *CLL_pop(char_linked_list** root);
char *CLL_shift(char_linked_list** root);
char *CLL_remove_index(char_linked_list** root, int index);
void CLL_change_element(char_linked_list** root, int index, char *new_data);
void CLL_flip(char_linked_list** root);
void CLL_push(char_linked_list** root, char* data);
void CLL_push_node(char_linked_list** root, char_linked_list* node);
void CLL_unshift(char_linked_list** root,char *data);
void CLL_unshift_node(char_linked_list** root,char_linked_list* node);
void CLL_insert_at(char_linked_list** root, char index, char *new_data);
void CLL_insert_node_at(char_linked_list** root, char index, char_linked_list *new_data);

// /* Utility functions */

char *CLL_to_array(char_linked_list* root);
char *CLL_at(char_linked_list* root, int index);
char *CLL_find(char_linked_list* root, int f());
char *CLL_find_last(char_linked_list* root, int f());
int CLL_length(char_linked_list* root);
int CLL_every(char_linked_list* root, int f());
// int CLL_for_each(char_linked_list* root, int f()); TODO
int CLL_find_index(char_linked_list* root, int f());
int CLL_find_index_by_value(char_linked_list* root, char* value);
int CLL_find_last_index(char_linked_list* root, int f());
int CLL_includes(char_linked_list* root, char *value);
// int ILL_foldr(int_linked_list* root, int f(), int start_value);
// int ILL_foldl(int_linked_list* root, int f(),int start_value);
int CLL_some(char_linked_list* root, int f());
void CLL_print(char_linked_list* root);
// void ILL_sort(int_linked_list** root);


// /*
// *       Single char linked list
// */

single_char_linked_list *SCLL_create_node(char data);
single_char_linked_list *SCLL_array_to_list(char array[],int size);
single_char_linked_list *SCLL_concat(single_char_linked_list* list_one_root, single_char_linked_list* list_two_root);
single_char_linked_list *SCLL_filter(single_char_linked_list* root, int  f());
single_char_linked_list *SCLL_fill(single_char_linked_list* root, int length, char value,int new_list);
// single_char_linked_list *SCLL_map(single_char_linked_list* root, char f());
single_char_linked_list *SCLL_cpy(single_char_linked_list* root);
single_char_linked_list *SCLL_cpy_within(single_char_linked_list* root, int left, int right);
single_char_linked_list *SCLL_slice(single_char_linked_list* root, int left, int right);
single_char_linked_list *SCLL_splice(single_char_linked_list** root, int start, int delete_count, single_char_linked_list* add_remove,int remove);

// /* freeing memory */

void SCLL_free(single_char_linked_list** root);
void SCLL_free_node(single_char_linked_list** root, single_char_linked_list* node);

// /* Mutating list */

char SCLL_pop(single_char_linked_list** root);
char SCLL_shift(single_char_linked_list** root);
char SCLL_remove_index(single_char_linked_list** root, int index);
void SCLL_change_element(single_char_linked_list** root, int index, char new_data);
void SCLL_flip(single_char_linked_list** root);
void SCLL_push(single_char_linked_list** root, char data);
void SCLL_push_node(single_char_linked_list** root, single_char_linked_list* node);
void SCLL_unshift(single_char_linked_list** root,char data);
void SCLL_unshift_node(single_char_linked_list** root,single_char_linked_list* node);
void SCLL_insert_at(single_char_linked_list** root, char index, char new_data);
void SCLL_insert_node_at(single_char_linked_list** root, char index, single_char_linked_list *new_data);

// /* Utility functions */

char *SCLL_to_array(single_char_linked_list* root);
char SCLL_at(single_char_linked_list* root, int index);
char SCLL_find(single_char_linked_list* root, int f());
char SCLL_find_last(single_char_linked_list* root, int f());
int SCLL_length(single_char_linked_list* root);
int SCLL_every(single_char_linked_list* root, int f());
// int SCLL_for_each(single_char_linked_list* root, int f()); TODO
int SCLL_find_index(single_char_linked_list* root, int f());
int SCLL_find_index_by_value(single_char_linked_list* root, char value);
int SCLL_find_last_index(single_char_linked_list* root, int f());
int SCLL_includes(single_char_linked_list* root, char value);
// int ILL_foldr(int_linked_list* root, int f(), int start_value);
// int ILL_foldl(int_linked_list* root, int f(),int start_value);
int SCLL_some(single_char_linked_list* root, int f());
void SCLL_print(single_char_linked_list* root);

// /*
// *       Ney value double pair
// */

key_value_double *KVD_create_pair(char* id, char_linked_list *new_keys, double_linked_list *new_values);
key_value_double *KVD_slice(key_value_double* root, int left, int right);
char_linked_list *KVD_keys_to_linked_list(key_value_double* root, char* id);
double_linked_list *KVD_values_to_linked_list(key_value_double* root, char* id);

void KVD_free(key_value_double** root);
void KVD_free_pair(key_value_double** root,key_value_double* node);

key_value_double* KVD_pop(key_value_double** root);
key_value_double* KVD_shift(key_value_double** root);
void KVD_flip(key_value_double** root);
void KVD_add(key_value_double** root,char* id, char_linked_list *new_keys, double_linked_list *new_values);
void KVD_add_pair(key_value_double** root, key_value_double* new_pair);
void KVD_unshift(key_value_double** root,char* id, char_linked_list *new_keys, double_linked_list *new_values);
void KVD_unshift_node(key_value_double** root,key_value_double* node);
void KVD_change_identifer(key_value_double** root, char* id, char* new_id);
void KVD_change_some_identifers(key_value_double** root, char* id, char* new_id);
void KVD_change_all_identifers(key_value_double** root, char* new_id);


key_value_double *KVD_at_identifer_index(key_value_double* root, int index);
key_value_double *KVD_at(key_value_double* root, int_linked_list* indexes);
key_value_double* KVD_cpy(key_value_double* root);
int_linked_list *KVD_index_of_pair(key_value_double* root, char* key, double value);
int KVD_index_of_identifier(key_value_double* root, char* id);
int KVD_length(key_value_double* root);
int KVD_length_of_keys_at(key_value_double* root,int index);
int KVD_length_of_values_at(key_value_double* root,int index);
void KVD_print(key_value_double* root);


char_linked_list* parse_SCLL(single_char_linked_list* container);

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


/* Creates a node */
double_linked_list *DLL_create_node(double data){

        double_linked_list* node = malloc(sizeof(double_linked_list));
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

double_linked_list *DLL_filter(double_linked_list* root, int  f()){

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

double_linked_list *DLL_map(double_linked_list* root, double f()){

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

int DLL_every(double_linked_list* root, int f()){

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

int DLL_find_index(double_linked_list* root, int f()){
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



int DLL_find_last_index(double_linked_list* root, int f()){

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

int DLL_some(double_linked_list* root, int f()){
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

double DLL_foldr(double_linked_list* root, double f(),double  start_value){
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

double DLL_foldl(double_linked_list* root, double f(),double start_value){
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

double DLL_find(double_linked_list* root, int f()){

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

double DLL_find_last(double_linked_list* root, int f()){
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

double DLL_for_each(double_linked_list* root, double f()){
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


int_linked_list *ILL_create_node(int data){

        int_linked_list* node = malloc(sizeof(int_linked_list));
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

int_linked_list *ILL_filter(int_linked_list* root, int f()){

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

int_linked_list *ILL_map(int_linked_list* root, int f()){

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

int ILL_every(int_linked_list* root, int f()){

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

int ILL_for_each(int_linked_list* root, int f()){
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

int ILL_find_index(int_linked_list* root, int f()){
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

int ILL_find(int_linked_list* root, int f()){
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

int ILL_find_last(int_linked_list* root, int f()){
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

int ILL_find_last_index(int_linked_list* root, int f()){
        
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

int ILL_foldr(int_linked_list* root, int f(),int start_value){
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

int ILL_foldl(int_linked_list* root, int f(),int start_value){
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

int ILL_some(int_linked_list* root, int f()){
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

void ILL_sort(int_linked_list** root){ /* BROKEn*/

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





char_linked_list *CLL_create_node(char *data){

        char_linked_list* node = malloc(sizeof(char_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

char *CLL_join(char_linked_list* root){
        if(root IS NULL){
                return "ERROR";
        }

        char_linked_list* cur = root;
        int length = CLL_length(root);

        char *arr = malloc(sizeof(char)*length+1);
        for (int i = 0; i < length;i++)
        {
                arr[i] = *cur->data;
                cur = cur->next;
        }

        arr[length+1] = '\0';

        return arr;
};

char_linked_list *CLL_array_to_list(char *array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return CLL_create_node("ERROR");
        }


        char_linked_list *root = CLL_create_node(array[0]);

       for(int i = 1; i < size;i++){
                CLL_push(&root,array[i]);
       }

        return root;
}

char_linked_list *CLL_concat(char_linked_list* list_one_root, char_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = CLL_length(list_one_root)+CLL_length(list_two_root);

        char_linked_list* concatinated_tree = CLL_cpy(list_one_root);
        char_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = CLL_cpy(list_two_root);

        return concatinated_tree;

}

char_linked_list *CLL_filter(char_linked_list* root, int  f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        char_linked_list* filtered_array;
        char_linked_list* cur = root;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = CLL_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        CLL_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

char_linked_list *CLL_fill(char_linked_list* root, int length, char *value,int new_list){
        if(!new_list){
                char_linked_list* cur = root;
                if(CLL_length(root) < length){
                        for(int i = 0; i < CLL_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = CLL_length(root); i < length ; i++)
                        {
                                CLL_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = CLL_create_node(value);
                for (int i = 1; i < length; i++){
                        CLL_push(&root,value);
                }
        }

        return root;
}

// char_linked_list *CLL_map(char_linked_list* root, char f()){

//         if(root IS NULL){
//                 return root;
//         }

//         int once = 0;
//         char_linked_list* filtered_array;
//         char_linked_list* cur = root;

//         for (int i = 0; i < CLL_length(root); i++)
//         {
//                 if(once IS 0){
//                         filtered_array = CLL_create_node(f(cur->data));
//                         once = 1;
//                 } else if(once IS 1){
//                         CLL_push(&filtered_array,CLL_create_node(f(cur->data)));
//                 }
//                 cur = cur->next;
//         }

//         return filtered_array;

// }

char_linked_list *CLL_cpy(char_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return CLL_filter(root,cpy_func);
}

char_linked_list *CLL_cpy_within(char_linked_list* root, int left, int right){
        if(root IS NULL){
                return CLL_create_node("ERROR");
        }


        if(left > right){
                return CLL_create_node("ERROR");
        } else if (right > CLL_length(root)){
                return CLL_create_node("ERROR");
        } else if(left < 0 OR right < 0){
                return CLL_create_node("ERROR");
        }

        char_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = CLL_create_node(CLL_at(root,i));
                        once = 1;
                } else {
                        CLL_push(&copied,CLL_at(root,i));
                }
        }

        return copied;
}

char_linked_list *CLL_slice(char_linked_list* root, int left, int right){
        
        if(root IS NULL){
                return CLL_create_node("ERROR");
        }


        if(left > right){
                return CLL_create_node("ERROR");
        } else if (right > CLL_length(root)){
                return CLL_create_node("ERROR");
        } else if(left < 0 OR right < 0){
                return CLL_create_node("ERROR");
        }

        char_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = CLL_create_node(CLL_at(root,i));
                        once = 1;
                } else {
                        CLL_push(&sliced,CLL_at(root,i));
                }
        }

        return sliced;
}

char_linked_list *CLL_splice(char_linked_list** root, int start, int delete_count, char_linked_list* add_remove,int remove){

        char_linked_list* cur = *root;
        char_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return CLL_create_node("ERROR");
        } else if(delete_count > CLL_length(*root)){
                return CLL_create_node("ERROR");
        }



        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                               
                                deleted = CLL_create_node(CLL_at(*root,start));
                                CLL_remove_index(root,start);
                                once = 1;
                        } else {
                                CLL_push(&deleted,CLL_at(*root,start));
                                CLL_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < CLL_length(add_remove); i++){
                                CLL_insert_at(root,start,CLL_at(add_remove,i));
                                start++;
                        }
                }
                
                return deleted;

        } else {
                for(int i = 0; i < CLL_length(add_remove); i++){
                        CLL_insert_at(root,start,CLL_at(add_remove,i));
                        start++;
                }
                return CLL_create_node(0);
        }


}


void CLL_free(char_linked_list** root){

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

void CLL_free_node(char_linked_list** root, char_linked_list* node){


        if(*root IS NULL){
                CLL_free(root);
                return;
        }

        char_linked_list* cur = *root;
        char_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(CLL_length(*root)-CLL_length(node));i++)
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


char *CLL_pop(char_linked_list** root){

        if(*root IS NULL){
                return "ERROR";
        }


        char *value;

        char_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        CLL_free_node(root,cur);

        return value;

}

char *CLL_shift(char_linked_list** root){

        CLL_flip(root);
        char *value = CLL_pop(root);
        CLL_flip(root);
        return value;
}

char *CLL_remove_index(char_linked_list** root, int index){
        if(root IS NULL){
                return "ERROR";
        }

        if(index IS 0 OR index > CLL_length(*root)){
                return "ERROR";
        }

        char_linked_list* cur = *root;
        *root = cur;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        char *value = cur->data;

        CLL_free_node(root,cur);

        return value;

}

void CLL_change_element(char_linked_list** root, int index, char *new_data){
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

void CLL_flip(char_linked_list** root){

        char_linked_list* flipped;
        int once = 0;

        for(int i = CLL_length(*root); i > 0; i--){
                if(once IS 0){
                        flipped = CLL_create_node( CLL_pop(root));
                        once = 1;
                } else {
                        CLL_push(&flipped,CLL_pop(root));
                }
        }

        *root = flipped;
        return;
}

void CLL_push(char_linked_list** root,char* data){

        if(root NOT_EQUAL NULL){
                char_linked_list* node = CLL_create_node(data);
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

void CLL_push_node(char_linked_list** root, char_linked_list* node){

        if(root NOT_EQUAL NULL){
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

void CLL_unshift(char_linked_list** root,char *data){

        if(*root IS NULL){
                return;
        }

        char_linked_list* new_root = CLL_create_node(data);
        new_root->next = *root;
        *root = new_root;
        return;
}

void CLL_unshift_node(char_linked_list** root,char_linked_list* node){

        if(*root IS NULL){
                return;
        }

        char_linked_list* new_root = node;
        new_root->next = *root;
        *root = new_root;
}

void CLL_insert_at(char_linked_list** root, char index, char *new_data){

        if(root IS NULL){
                return;
        }

        int length = CLL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                CLL_unshift(root,new_data);
        } else {
                char_linked_list* temp_first_part = CLL_slice(*root,0,index);
                char_linked_list* temp_last_part = CLL_slice(*root,index,length);
                CLL_push(&temp_first_part,new_data);
                *root = CLL_concat(temp_first_part,temp_last_part);
        }

        return;

}

void CLL_insert_node_at(char_linked_list** root, char index, char_linked_list* new_data){

        if(root IS NULL){
                return;
        }

        int length = CLL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                CLL_unshift_node(root,new_data);
        } else {
                char_linked_list* temp_first_part = CLL_slice(*root,0,index);
                char_linked_list* temp_last_part = CLL_slice(*root,index,length);
                CLL_push_node(&temp_first_part,new_data);
                *root = CLL_concat(temp_first_part,temp_last_part);
        }

        return;

}


// char *CLL_to_array(char_linked_list* root){ /*TODO*/

//         if(root IS NULL){
//                 return "ERROR";
//         }

//         int length = CLL_length(root);
//         char *arr = malloc(sizeof(char_linked_list));

//         char_linked_list* cur = root;
//         for(int i = 0; i < length; i++){
//                 arr[i] = cur->data;
//                 cur = cur->next;
//         };

//         return arr;
// }

char* CLL_at(char_linked_list* root, int index){
        if (root IS NULL){
                return "ERROR";
        }

        if(index IS 0){
                return root->data;
        }


        char_linked_list* cur = root;

        if(CLL_length(root) < index){
                return "ERROR";
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

char* CLL_find(char_linked_list* root, int f()){

        if(root IS NULL){
                return "ERROR";
        }

        char_linked_list* cur = root;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

        return "ERROR";
}

char *CLL_find_last(char_linked_list* root, int f()){
        if(root IS NULL){
                return "ERROR";
        }

        char_linked_list* cur = root;
        char *value = "ERROR";

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

int CLL_length(char_linked_list* root){
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

int CLL_every(char_linked_list* root, int f()){

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

// int CLL_for_each(char_linked_list* root, int f()){
//         if (root IS NULL){
//                 return -1;
//         }

//         char *arr = CLL_to_array(root);
//         int accumulator = 0;
//         int once = 0;

//         for(int i = 0; i < CLL_length(root) + 1; i++){
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

int CLL_find_index(char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int CLL_find_index_by_value(char_linked_list* root, char* value){
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;
}


int CLL_find_last_index(char_linked_list* root, int f()){
        
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int CLL_includes(char_linked_list* root, char* value){
        if(root IS NULL){
                return -1;
        }

        char_linked_list* cur = root;

        for (int i = 0; i < CLL_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }


        return 0;


}

// int ILL_foldr(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return ILL_at(root,0);
//         }

//         if(start_value < 0){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) < 2){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) IS 2){
//                 return f(ILL_at(root,0), ILL_at(root,1));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = 0; i < ILL_length(root); i++){
//                 accumulator = f(accumulator,ILL_at(root,i));
//         }

//         return accumulator;
// }

// int ILL_foldl(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return ILL_at(root,0);
//         }

//         if(start_value < 0){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) < 2){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) IS 2){
//                 return f(ILL_at(root,1), ILL_at(root,0));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = ILL_length(root)-1; i >= 0; i--){
//                 accumulator = f(accumulator,ILL_at(root,i));
//         }

//         return accumulator;
// }

int CLL_some(char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        char_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < CLL_length(root); i++)
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

void CLL_print(char_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %s\n", root->data);
        printf("Next node: \n");
        CLL_print(root->next);
}





single_char_linked_list *SCLL_create_node(char data){

        single_char_linked_list* node = malloc(sizeof(single_char_linked_list));
        if(node NOT_EQUAL NULL){
                node->data = data;
                node->next = NULL;
        }

        return node;
}

single_char_linked_list *SCLL_array_to_list(char array[],int size){


        if(size IS 0){
                printf("Error empty array\n");
                return SCLL_create_node('e');
        }


        single_char_linked_list *root = SCLL_create_node(array[0]);

       for(int i = 1; i < size;i++){
                SCLL_push(&root,array[i]);
       }

        return root;
}

single_char_linked_list *SCLL_concat(single_char_linked_list* list_one_root, single_char_linked_list* list_two_root){

        if(list_one_root IS NULL){
                return list_two_root;
        }

        if(list_two_root IS NULL){
                return list_one_root;
        }

        int length = SCLL_length(list_one_root)+SCLL_length(list_two_root);

        single_char_linked_list* concatinated_tree = SCLL_cpy(list_one_root);
        single_char_linked_list*cur = concatinated_tree;
        while(cur->next NOT_EQUAL NULL ){
                cur = cur->next;
        }

        cur->next = SCLL_cpy(list_two_root);

        return concatinated_tree;

}

single_char_linked_list *SCLL_filter(single_char_linked_list* root, int  f()){

        if(root IS NULL){
                return root;
        }

        int once = 0;
        single_char_linked_list* filtered_array;
        single_char_linked_list* cur = root;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(f(cur->data) AND once IS 0){
                        filtered_array = SCLL_create_node(cur->data);
                        once = 1;
                } else if(f(cur->data) AND once IS 1){
                        SCLL_push(&filtered_array,cur->data);
                }
                cur = cur->next;
        }

        return filtered_array;

}

single_char_linked_list *SCLL_fill(single_char_linked_list* root, int length, char value,int new_list){
        if(!new_list){
                single_char_linked_list* cur = root;
                if(SCLL_length(root) < length){
                        for(int i = 0; i < SCLL_length(root); i++){
                                cur->data = value;
                                cur = cur->next;
                        }
                        for (int i = SCLL_length(root); i < length ; i++)
                        {
                                SCLL_push(&root,value);
                        }
                } else{
                        for (int i = 0; i < length; i++)
                        {
                                cur->data = value;
                                cur = cur->next;
                        }
                }

        } else {
                root = SCLL_create_node(value);
                for (int i = 1; i < length; i++){
                        SCLL_push(&root,value);
                }
        }

        return root;
}

// single_char_linked_list *SCLL_map(single_char_linked_list* root, char f()){

//         if(root IS NULL){
//                 return root;
//         }

//         int once = 0;
//         single_char_linked_list* filtered_array;
//         single_char_linked_list* cur = root;

//         for (int i = 0; i < SCLL_length(root); i++)
//         {
//                 if(once IS 0){
//                         filtered_array = SCLL_create_node(f(cur->data));
//                         once = 1;
//                 } else if(once IS 1){
//                         SCLL_push(&filtered_array,SCLL_create_node(f(cur->data)));
//                 }
//                 cur = cur->next;
//         }

//         return filtered_array;

// }

single_char_linked_list *SCLL_cpy(single_char_linked_list* root){
        if(root IS NULL){
                return root;
        }

        return SCLL_filter(root,cpy_func);
}

single_char_linked_list *SCLL_cpy_within(single_char_linked_list* root, int left, int right){
        if(root IS NULL){
                return   SCLL_create_node('e');
        }


        if(left > right){
                return   SCLL_create_node('e');
        } else if (right > SCLL_length(root)){
                return   SCLL_create_node('e');
        } else if(left < 0 OR right < 0){
                return   SCLL_create_node('e');
        }

        single_char_linked_list* copied;
        int once = 0;

        for (int i = left; i < right + 1 ; i++)
        {
                if(once IS 0){
                        copied = SCLL_create_node(SCLL_at(root,i));
                        once = 1;
                } else {
                        SCLL_push(&copied,SCLL_at(root,i));
                }
        }

        return copied;
}

single_char_linked_list *SCLL_slice(single_char_linked_list* root, int left, int right){
        
        if(root IS NULL){
                return   SCLL_create_node('e');
        }


        if(left > right){
                return   SCLL_create_node('e');
        } else if (right > SCLL_length(root)){
                return   SCLL_create_node('e');
        } else if(left < 0 OR right < 0){
                return   SCLL_create_node('e');
        }

        single_char_linked_list* sliced;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                if(once IS 0){
                        sliced = SCLL_create_node(SCLL_at(root,i));
                        once = 1;
                } else {
                        SCLL_push(&sliced,SCLL_at(root,i));
                }
        }

        return sliced;
}

single_char_linked_list *SCLL_splice(single_char_linked_list** root, int start, int delete_count, single_char_linked_list* add_remove,int remove){

        single_char_linked_list* cur = *root;
        single_char_linked_list* deleted;

        if(*root IS NULL){
                return add_remove;
        } else if(add_remove IS NULL AND remove IS 0){
                return cur;
        }else if(*root IS NULL AND add_remove IS NULL){
                return   SCLL_create_node('e');
        } else if(delete_count > SCLL_length(*root)){
                return   SCLL_create_node('e');
        }



        if(delete_count > 0){
                int once = 0;
                for(int i = 0; i < delete_count; i++){
                        if (once IS 0){
                               
                                deleted = SCLL_create_node(SCLL_at(*root,start));
                                SCLL_remove_index(root,start);
                                once = 1;
                        } else {
                                SCLL_push(&deleted,SCLL_at(*root,start));
                                SCLL_remove_index(root,start);
                        }
                }

                if(remove IS 0){
                        for(int i = 0; i < SCLL_length(add_remove); i++){
                                SCLL_insert_at(root,start,SCLL_at(add_remove,i));
                                start++;
                        }
                }
                
                return deleted;

        } else {
                for(int i = 0; i < SCLL_length(add_remove); i++){
                        SCLL_insert_at(root,start,SCLL_at(add_remove,i));
                        start++;
                }
                return SCLL_create_node(0);
        }


}


void SCLL_free(single_char_linked_list** root){

        single_char_linked_list* cur = *root;

        if(cur->next IS NULL){
                free(root);
        }

        single_char_linked_list* prev = *root;

        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                free(prev);
                prev = cur;
        }

}

void SCLL_free_node(single_char_linked_list** root, single_char_linked_list* node){


        if(*root IS NULL){
                SCLL_free(root);
                return;
        }

        single_char_linked_list* cur = *root;
        single_char_linked_list* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                free(cur);
        
        } else {
                for(int i = 0; i < abs(SCLL_length(*root)-SCLL_length(node));i++)
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


char SCLL_pop(single_char_linked_list** root){

        if(*root IS NULL){
                return 'e';
        }


        char value;

        single_char_linked_list* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }

        value = cur->data;
        SCLL_free_node(root,cur);

        return value;

}

char SCLL_shift(single_char_linked_list** root){

        SCLL_flip(root);
        char value = SCLL_pop(root);
        SCLL_flip(root);
        return value;
}

char SCLL_remove_index(single_char_linked_list** root, int index){
        if(root IS NULL){
                return 'e';
        }

        if(index IS 0 OR index > SCLL_length(*root)){
                return 'e';
        }

        single_char_linked_list* cur = *root;
        *root = cur;
        
        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        char value = cur->data;

        SCLL_free_node(root,cur);

        return value;

}

void SCLL_change_element(single_char_linked_list** root, int index, char new_data){
        if(*root IS NULL){
                return;
        }

        single_char_linked_list* cur = *root;
        *root = cur;

        for(int i = 0; i < index; i++){
                cur = cur->next;
        }

        cur->data = new_data;
        return;
}

void SCLL_flip(single_char_linked_list** root){

        single_char_linked_list* flipped;
        int once = 0;

        for(int i = SCLL_length(*root); i > 0; i--){
                if(once IS 0){
                        flipped = SCLL_create_node( SCLL_pop(root));
                        once = 1;
                } else {
                        SCLL_push(&flipped,SCLL_pop(root));
                }
        }

        *root = flipped;
        return;
}

void SCLL_push(single_char_linked_list** root,char data){

        if(root NOT_EQUAL NULL){
                single_char_linked_list* node = SCLL_create_node(data);
                single_char_linked_list* cur = *root;
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

void SCLL_push_node(single_char_linked_list** root, single_char_linked_list* node){

        if(root NOT_EQUAL NULL){
                single_char_linked_list* cur = *root;
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

void SCLL_unshift(single_char_linked_list** root,char data){

        if(*root IS NULL){
                return;
        }

        single_char_linked_list* new_root = SCLL_create_node(data);
        new_root->next = *root;
        *root = new_root;
        return;
}

void SCLL_unshift_node(single_char_linked_list** root,single_char_linked_list* node){

        if(*root IS NULL){
                return;
        }

        single_char_linked_list* new_root = node;
        new_root->next = *root;
        *root = new_root;
}

void SCLL_insert_at(single_char_linked_list** root, char index, char new_data){

        if(root IS NULL){
                return;
        }

        int length = SCLL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                SCLL_unshift(root,new_data);
        } else {
                single_char_linked_list* temp_first_part = SCLL_slice(*root,0,index);
                single_char_linked_list* temp_last_part = SCLL_slice(*root,index,length);
                SCLL_push(&temp_first_part,new_data);
                *root = SCLL_concat(temp_first_part,temp_last_part);
        }

        return;

}

void SCLL_insert_node_at(single_char_linked_list** root, char index, single_char_linked_list* new_data){

        if(root IS NULL){
                return;
        }

        int length = SCLL_length(*root);

        if(index > length){
                return;
        }


        if(index IS 0){
                SCLL_unshift_node(root,new_data);
        } else {
                single_char_linked_list* temp_first_part = SCLL_slice(*root,0,index);
                single_char_linked_list* temp_last_part = SCLL_slice(*root,index,length);
                SCLL_push_node(&temp_first_part,new_data);
                *root = SCLL_concat(temp_first_part,temp_last_part);
        }

        return;

}


char *SCLL_to_array(single_char_linked_list* root){ 

        if(root IS NULL){
                return "ERROR";
        }

        int length = SCLL_length(root);
        char *arr = malloc(sizeof(root)*length);
        int j; 

        single_char_linked_list* cur = root;
        for(int i = 0; i < length; i++){
                arr[i] = cur->data;
                cur = cur->next;
                j++;
        };
        arr[length] = '\0';
        return arr;
}

char SCLL_at(single_char_linked_list* root, int index){
        if (root IS NULL){
                return 'e';
        }

        if(index IS 0){
                return root->data;
        }


        single_char_linked_list* cur = root;

        if(SCLL_length(root) < index){
                return 'e';
        }

        for(int i = 0; i < index ;i++){
                cur = cur->next;
        }

        return cur->data;

}

char SCLL_find(single_char_linked_list* root, int f()){

        if(root IS NULL){
                return 'e';
        }

        single_char_linked_list* cur = root;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(f(cur->data)){
                        return cur->data;
                }
                cur = cur->next;
        }

       return 'e';
}

char SCLL_find_last(single_char_linked_list* root, int f()){
        if(root IS NULL){
                return 'e' ;
        }

        single_char_linked_list* cur = root;
        char value = 'e';

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(f(cur->data)){
                        value = cur->data;
                }
                cur = cur->next;
        }

        return value;
}

int SCLL_length(single_char_linked_list* root){
        int length = 0;
        if(root IS NULL){
                return length;
        }

        single_char_linked_list* cur = root;
        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                length++;
        }

        return length;

}

int SCLL_every(single_char_linked_list* root, int f()){

        if(root IS NULL){
                return -1;
        }

        single_char_linked_list* cur = root;

        while (cur->next NOT_EQUAL NULL){
                if(!f(cur->data)){
                        return false;
                }
                cur = cur->next;
        }

        return true;

}

// int SCLL_for_each(single_char_linked_list* root, int f()){
//         if (root IS NULL){
//                 return -1;
//         }

//         char *arr = SCLL_to_array(root);
//         int accumulator = 0;
//         int once = 0;

//         for(int i = 0; i < SCLL_length(root) + 1; i++){
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

int SCLL_find_index(single_char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        single_char_linked_list* cur = root;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(f(cur->data)){
                        return i;
                }
                cur = cur->next;
        }

        return -1;

}

int SCLL_find_index_by_value(single_char_linked_list* root, char value){
        if(root IS NULL){
                return -2;
        }

        single_char_linked_list* cur = root;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(cur->data IS value){
                        return i;
                }
                cur = cur->next;
        }

        return -1;
}


int SCLL_find_last_index(single_char_linked_list* root, int f()){
        
        if(root IS NULL){
                return -2;
        }

        single_char_linked_list* cur = root;
        int index = -1;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(f(cur->data)){
                        index = i;
                }
                cur = cur->next;
        }

        return index;
}

int SCLL_includes(single_char_linked_list* root, char value){
        if(root IS NULL){
                return -1;
        }

        single_char_linked_list* cur = root;

        for (int i = 0; i < SCLL_length(root); i++)
        {
                if(cur->data IS value){
                        return 1;
                }
        }


        return 0;


}

// int ILL_foldr(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return ILL_at(root,0);
//         }

//         if(start_value < 0){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) < 2){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) IS 2){
//                 return f(ILL_at(root,0), ILL_at(root,1));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = 0; i < ILL_length(root); i++){
//                 accumulator = f(accumulator,ILL_at(root,i));
//         }

//         return accumulator;
// }

// int ILL_foldl(int_linked_list* root, int f(),int start_value){
//         if(root IS NULL){
//                 return ILL_at(root,0);
//         }

//         if(start_value < 0){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) < 2){
//                 return ILL_at(root,0);
//         }

//         if(ILL_length(root) IS 2){
//                 return f(ILL_at(root,1), ILL_at(root,0));
//         }

//         int accumulator = start_value;
//         int once = 0;

//         for (int i = ILL_length(root)-1; i >= 0; i--){
//                 accumulator = f(accumulator,ILL_at(root,i));
//         }

//         return accumulator;
// }

int SCLL_some(single_char_linked_list* root, int f()){
        if(root IS NULL){
                return -2;
        }

        single_char_linked_list* cur = root;
        int count = 0;

        for (int i = 0; i < SCLL_length(root); i++)
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

void SCLL_print(single_char_linked_list* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }
        printf("Data = %c\n", root->data);
        printf("Next node: \n");
        SCLL_print(root->next);
}



int_linked_list *cpy_double_list_to_int(double_linked_list* root) {
        if(root IS NULL){
                return ILL_create_node(0);
        }

        int_linked_list* cur = ILL_create_node(0);
        cur->data = (int)DLL_at(root, 0);

        for (int i = 1; i < DLL_length(root); i++)
        {
                ILL_push(&cur,(int)DLL_at(root,i));
        }

        return cur;
}

double_linked_list *cpy_int_list_to_double(int_linked_list* root) {

        if(root IS NULL){
                return DLL_create_node(0);
        }

        double_linked_list* cur = DLL_create_node(0);
        cur->data = (double)ILL_at(root, 0);

        for (int i = 1; i < ILL_length(root); i++)
        {
                DLL_push(&cur,(double)ILL_at(root,i));
        }

        return cur;
}

/* A warning will appear when this functions is used, you can ingore it */
void convert_double_list_to_int(double_linked_list** root){

        if(root IS NULL){
                return;
        }

        int_linked_list* cur = ILL_create_node(0);
        cur->data = (int)DLL_at(*root, 0);

        for (int i = 1; i < DLL_length(*root); i++)
        {
                ILL_push(&cur,(int)DLL_at(*root,i));
        }

        *root = cur;
        return;
}

/* A warning will appear when this functions is used, you can ingore it */
void convert_int_list_to_double(int_linked_list** root){

        if(root IS NULL){
                return;
        }

        double_linked_list* cur = DLL_create_node(0);
        cur->data = (double)ILL_at(*root, 0);

        for (int i = 1; i < ILL_length(*root); i++)
        {
                DLL_push(&cur,(double)ILL_at(*root,i));
        }

        *root = cur;
        return;
}




key_value_double *KVD_create_pair(char* id, char_linked_list *new_keys, double_linked_list *new_values){

        key_value_double* pair = malloc(sizeof(key_value_double));

        if(CLL_length(new_keys) NOT_EQUAL DLL_length(new_values)){
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

key_value_double *KVD_slice(key_value_double* root, int left, int right){

        if(root IS NULL){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        }


        if(left > right){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        } else if (right > KVD_length(root)){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        } else if(left < 0 OR right < 0){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        }

        key_value_double* sliced;
        key_value_double* temp;
        int once = 0;

        for (int i = left; i < right ; i++)
        {
                temp = KVD_at_identifer_index(root,i);
                if(once IS 0){
                        sliced = KVD_create_pair(temp->identifier,temp->keys,temp->values);
                        once = 1;
                } else {
                        KVD_add_pair(&sliced,temp);
                }
        }

        return sliced;
}

key_value_double *KVD_concat(key_value_double* pair_one_root, key_value_double* pair_two_root){

        if(pair_one_root IS NULL){
                return pair_two_root;
        }

        if(pair_two_root IS NULL){
                return pair_one_root;
        }


        key_value_double* cur = KVD_cpy(pair_one_root);
        key_value_double* cur_2 = KVD_cpy(pair_two_root);
        key_value_double* cpy;
        int once = 0;

        for (int i = 0; i < KVD_length(pair_one_root); i++)
        {
                if(once IS 0){
                        cpy = KVD_create_pair(cur->identifier,cur->keys,cur->values);
                        once = 1;
                } else {
                        KVD_add_pair(&cpy,cur);
                }
                cur=cur->next;
        }

        for (int i = 0; i < 2; i++)
        {

                KVD_add(&cpy,cur_2->identifier,cur_2->keys,cur_2->values);
                cur_2=cur_2->next;
        }

        return cpy;

}

char_linked_list *KVD_keys_to_linked_list(key_value_double* root, char* id){
        if(root IS NULL){
                return CLL_create_node("ERROR");
        }

        int index = KVD_index_of_identifier(root, id);

        if(index < 0){
                return CLL_create_node("ERROR");
        }

        return KVD_at_identifer_index(root,index)->keys;
}

double_linked_list *KVD_values_to_linked_list(key_value_double* root, char* id){
        if(root IS NULL){
                return DLL_create_node(-1);
        }

        int index = KVD_index_of_identifier(root, id);

        if(index < 0){
                return DLL_create_node(-1);
        }

        return KVD_at_identifer_index(root,index)->values;
}


void KVD_free(key_value_double** root){

        key_value_double* cur = *root;

        if(cur->next IS NULL){
                free(root);
        }

        key_value_double* prev = *root;

        while (cur NOT_EQUAL NULL)
        {
                cur = cur->next;
                DLL_free(&prev->values);
                CLL_free(&prev->keys);
                free(prev);
                prev = cur;
        }

}

void KVD_free_pair(key_value_double** root, key_value_double* node){


        if(*root IS NULL){
                KVD_free(root);
                return;
        }

        key_value_double* cur = *root;
        key_value_double* prev = *root;

        if(*root IS node){
                *root = cur->next;
                prev->next = NULL;
                DLL_free(&cur->values);
                CLL_free(&cur->keys);
                free(cur);
        
        } else {
                for(int i = 0; i < abs(KVD_length(*root)-KVD_length(node));i++)
                {
                        prev = cur;
                        cur = cur->next;
                }
                if(cur->next NOT_EQUAL NULL){
                        prev->next = cur->next;
                }else {
                        prev->next = NULL;
                }
                DLL_free(&cur->values);
                CLL_free(&cur->keys);
                free(cur);
        }

}


key_value_double* KVD_pop(key_value_double** root){

        if(*root IS NULL){
                return NULL;
        }

        key_value_double* value;
        key_value_double* cur = *root;

        while (cur->next NOT_EQUAL NULL){
                cur = cur->next;
        }


        value = KVD_create_pair(cur->identifier,CLL_cpy(cur->keys),DLL_cpy(cur->values));
        KVD_free_pair(root,cur);

        return value;

}

key_value_double* KVD_shift(key_value_double** root){

        KVD_flip(root);
        key_value_double *value = KVD_pop(root);
        KVD_flip(root);
        return value;
}

void KVD_flip(key_value_double** root){

        key_value_double* new;
        int once = 0;
        for(int i = KVD_length(*root); i > 0; i--){
                if(once IS 0){
                        new = KVD_pop(root);
                        once = 1;
                } else {
                        KVD_add_pair(&new,KVD_pop(root));
                }
        }

        *root = new;
}

void KVD_add(key_value_double** root, char* id, char_linked_list *new_keys, double_linked_list *new_values){

       if(root NOT_EQUAL NULL){
                key_value_double* new_pair = KVD_create_pair(id, new_keys,new_values);
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

void KVD_add_pair(key_value_double** root, key_value_double* new_pair){

       if(root NOT_EQUAL NULL){
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

void KVD_unshift(key_value_double** root,char* id, char_linked_list *new_keys, double_linked_list *new_values){


        if(*root IS NULL){
                return;
        }

        key_value_double* new_root = KVD_create_pair(id,new_keys,new_values);
        new_root->next = *root;
        *root = new_root;
}

void KVD_unshift_node(key_value_double** root,key_value_double* node){


        if(*root IS NULL){
                return;
        }

        key_value_double* new_root = node;
        new_root->next = *root;
        *root = new_root;
}



void KVD_change_identifer(key_value_double** root, char* id, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < KVD_index_of_identifier(*root,id); i++)
        {
                cur = cur->next;
        }

        cur->identifier = new_id;

        return;
}

void KVD_change_some_identifers(key_value_double** root, char* id, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < KVD_length(*root); i++)
        {
                if(cur->identifier IS id){
                        cur->identifier = new_id;
                }
                cur = cur->next;
        }

        return;
}

void KVD_change_all_identifers(key_value_double** root, char* new_id){
        if(*root IS NULL){
                return;
        }

        key_value_double* cur = *root;
        *root = cur;

        for (int i = 0; i < KVD_length(*root); i++)
        {
                cur->identifier = new_id;
                cur = cur->next;
        }

        return;
}




key_value_double *KVD_at_identifer_index(key_value_double* root, int index){

        if(root IS NULL){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        }

        key_value_double* cur = root;

        if(index == 0){
                return KVD_create_pair(cur->identifier,cur->keys,cur->values);
        } else if (index > KVD_length(root)){
                return KVD_create_pair(cur->identifier,cur->keys,cur->values);
        }


        for (int i = 0; i < index; i++)
        {
                cur = cur->next;
        }

        return KVD_create_pair(cur->identifier,cur->keys,cur->values);

}

key_value_double *KVD_at(key_value_double* root, int_linked_list* indexes){

        if(root IS NULL){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-2));
        }

        if(ILL_length(indexes) > 2){
                return KVD_create_pair("ERROR",CLL_create_node("ERROR"),DLL_create_node(-1));
        }

        key_value_double* cur = root;

        if(ILL_at(indexes,0) IS 0){
                return KVD_create_pair("Pair at",CLL_create_node(CLL_at(root->keys,ILL_at(indexes,1))),DLL_create_node(DLL_at(root->values,ILL_at(indexes,1))));
        }


        for (int i = 0; i < ILL_at(indexes,0); i++)
        {
                cur = cur->next;
        }

        return KVD_create_pair("Pair at",CLL_create_node(CLL_at(cur->keys,ILL_at(indexes,1))),DLL_create_node(DLL_at(cur->values,ILL_at(indexes,1))));
}

key_value_double* KVD_cpy(key_value_double* root){
        if(root IS NULL){
                return root;
        }

        key_value_double* cpy;
        key_value_double* cur = root;
        int once = 0;

        for(int i = 0; i < KVD_length(root);i++){
                if(once IS 0){
                        cpy = KVD_create_pair(cur->identifier,cur->keys,cur->values);
                        once = 1;
                } else {
                        KVD_add_pair(&cpy,cur);
                }
                cur = cur->next;
        }

        return cpy;

}

/* Returns a linked list where the first element is the index of the identifier and the second the index of the pair, else -1 */
int_linked_list *KVD_index_of_pair(key_value_double* root, char* key, double value){
        if(root IS NULL){
                return ILL_create_node(-2);
        }

        key_value_double* cur = root;
        int_linked_list* indexes;


        int key_index;


        for (int i = 0; i < KVD_length(root); i++){
                key_index = CLL_find_index_by_value(cur->keys,key);

                if(key_index > 0 AND DLL_at(cur->values,key_index) IS value){
                        indexes = ILL_create_node(KVD_index_of_identifier(root, cur->identifier));
                        ILL_push(&indexes, key_index);
                        return indexes;
                }
                cur = cur->next;
                
        }


        return ILL_create_node(-1);

}

int KVD_index_of_identifier(key_value_double* root, char* id){

        if(root IS NULL){
                return -2;
        }

        key_value_double* cur = root;

        for (int i = 0; i < KVD_length(root); i++){
                if(cur->identifier == id){
                        return i;
                }
                cur = cur->next;
        }

        return -1;


}

int KVD_length(key_value_double* root){

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

int KVD_length_of_keys_at(key_value_double* root,int index){
        if(root IS NULL){
                return -1;
        }

        if (index > KVD_length(root)){
                return -1;
        }


        return CLL_length(KVD_at_identifer_index(root,index)->keys);

}

int KVD_length_of_values_at(key_value_double* root,int index){
        if(root IS NULL){
                return -1;
        }

        if (index > KVD_length(root)){
                return -1;
        }


        return CLL_length(KVD_at_identifer_index(root,index)->keys);
}

void KVD_print(key_value_double* root){

        if(root IS NULL){
                printf("Empty\n");
                return;
        }

        char_linked_list* cur_key = root->keys;
        double_linked_list* cur_values = root->values;
        printf("Identifer: %s \n", root->identifier);
        printf("---- Key value pairs: { ");

        for (int i = 0; i < DLL_length(cur_values); i++){
                printf("{Key: %s, Value: %f}, ",CLL_at(cur_key,i), DLL_at(cur_values,i));
        }
        printf("}\n");

        printf("Next pair: \n");
        KVD_print(root->next);
}



single_char_linked_list *file_to_char_list(char* name_of_file){
        
        FILE* ptr;
        ptr = fopen(name_of_file, "r+");

        if (NULL == ptr) {
                printf("file can't be opened \n");
        }
        char c;
        int once = 0;
        single_char_linked_list* input;

        while (1) {
                c = fgetc(ptr);
                if(c == EOF){
                        break;
                }

                if(once == 0){
                        input = SCLL_create_node((c));
                        once =  1;
                } else if(once == 1){
                        SCLL_push(&input,c);
                }
        }


        return input;

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

// char_linked_list* parse_SCLL(single_char_linked_list* container){

//         char *buffer[50];
//         char cur_token;
//         int cut = 0;
//         int j;

//         char_linked_list* strings;

//         single_char_linked_list* cpy = SCLL_cpy(container);
//         int once = 0;
//         for (int i = 0; i < SCLL_length(container);i++)
//         {       
//                 cur_token = SCLL_shift(&container);
//                 if(cur_token == '"' AND cut IS 1){
//                         if(once IS 0){
//                                 strings = CLL_create_node(SCLL_to_array(SCLL_slice(cpy,j-1,i)));
//                                 once = 1;
//                         } else if(once IS 1) {
//                                 CLL_push_node(&strings,CLL_create_node(SCLL_to_array(SCLL_slice(cpy,j-1,i))));
//                         }

//                         cut = 0;

//                 }
//                 if(cur_token == '"' AND cut IS 0){
//                         cut = 1;
//                         j = i;
//                 }

                
//         }

//         return strings;

// };