#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_TREE{
        int data;
        int next;
        int elements;
} int_TREE;



int length(int_TREE* tree);
int fold_r(int_TREE* tree, int f());
int fold_l(int_TREE* tree, int f());
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void print_tree(int_TREE* tree);
void push(int_TREE* tree, int_TREE* new);
int last_index_of(int_TREE* tree, int ele,int start_index);
int find_index(int_TREE* tree, int f());
int find(int_TREE* tree, int f());
int pop(int_TREE* tree);
int shift(int_TREE* tree);

void flip(int_TREE* tree);
int_TREE* sort(int_TREE* tree);
int_TREE* init_int_TREE (int data);
int_TREE* get_next(int_TREE* tree);
int_TREE* set_next(int_TREE* tree, int_TREE* new);
int_TREE* for_each(int_TREE* tree,int f());
int_TREE* filter_map(int_TREE* tree, int f());


int sum(int i,int b){
        return i-b;
}

int_TREE* init_int_TREE (int data){
        int_TREE *tree = calloc (1, sizeof (int_TREE));
        tree -> data = data;
        tree -> next = (int)NULL;
        tree -> elements = 0;
        pop(tree);
        return tree;
}

int_TREE* get_next(int_TREE* tree){
        return tree->next;
}

int_TREE* set_next(int_TREE* tree, int_TREE* new){

        if(tree->next != (int)NULL){
                int_TREE* temp = tree->next;
                new->next = temp;
                tree->next = new;
        } else {
                tree->next = new;
        }

        tree->elements++;
}

int find_index(int_TREE* tree, int f()){

        int_TREE* cur = tree;

        for(int i = 0; i <= length(tree);i++){
                if(f(cur->data)){
                        return i;
                }
                cur = get_next(cur);
        }

        return -1;
}

int find(int_TREE* tree, int f()){

        int_TREE* cur = tree;

        for(int i = 0; i <= tree->elements;i++){
                if(f(cur->data)){
                        return cur->data;
                }
                cur = get_next(cur);
        }

        return -1;
}



void push(int_TREE* tree, int_TREE* new){

        int_TREE* cur = tree;
        int_TREE* prev = cur;
        while(cur->next != (int)NULL){
                prev = cur;
                cur = get_next(cur);
        } 
        prev->next = cur;
        cur->next = new;
        tree->elements++;
}

int index_of(int_TREE* tree, int ele,int start_index){

        int_TREE* cur = tree;

        for(int i = start_index; i <= length(tree);i++){
                if(cur->data == ele){
                        return i;
                }
        }

        return -1;

}

int last_index_of(int_TREE* tree, int ele, int start_index){

        int_TREE* cur = tree;
        if (start_index == 0){
                start_index = length(tree);
        }
        for(int i = start_index; i >= 0  ;i--){
                if(cur->data == ele){
                        return i;
                }
        }

        return -1;

}


int_TREE* filter(int_TREE* tree, int f()){
        int_TREE* cur = tree;

        int arr[length(tree)];
        int found = 0;
        for(int i = 0; i <= length(tree); i++){
                if(f(cur -> data)){
                        arr[found] = cur->data;
                        found++;
                }
                cur = get_next(cur);
        }

        if(found == 0){
                return -1;
        }

        int_TREE* filtered = init_int_TREE(arr[0]);
        for (int i = 1; i < found; i++){
                push(filtered, init_int_TREE(arr[i]));
        }

        return filtered;
}


int fold_l(int_TREE* tree,int f()){
        flip(tree);
        int temp = fold_r(tree,sum);
        flip(tree);
        return temp;
}

void flip(int_TREE* tree){
        int_TREE * cur = tree;
        int_TREE * temp = cur;
        int arr[length(tree)+1];
        int sum = 0;
        for (int i = 0; i <= length(tree); i++){
                arr[i] = temp->data;
                temp = get_next(temp);
        }

        temp = cur;

        for(int i = length(tree);i>=0;i--){
                temp->data = arr[i];
                temp = get_next(temp);
        }

        if(tree->elements < 0){
                tree->elements = -tree->elements;
        }
       
        return temp;

}

int fold_r(int_TREE* tree,int f()){


        int_TREE * cur = tree;
        int arr[length(tree)];
        int sum = 0;
        for (int i = 0; i <= length(tree); i++){
                arr[i] = cur->data;
                cur = get_next(cur);
        }

        int once = 0;
        for(int i = 0; i <= length(tree)+1; i++){
                // printf("%d \n",sum);
                if(i == 2){
                        sum += f(arr[i-2],arr[i-1]);
                        printf("%d, %d %d\n",arr[i-2],arr[i-1], sum);
                        once = 1;
                } else if(once == 1){
                        printf("%d, %d\n",arr[i-1], sum);
                        sum = f(sum,arr[i-1]);
                }
        }

        return sum;
}



int_TREE * sort(int_TREE* tree){

        int arr[tree->elements];
        int_TREE* cur = tree;
        for(int i = 0; i <= length(tree); i++){
                arr[i] = cur->data;
                cur = get_next(cur);
        }


        mergeSort(arr, 0, tree->elements);

        int_TREE* sorted = init_int_TREE(arr[0]);

        for(int i = 1; i <= length(tree); i++){
                push(sorted, init_int_TREE(arr[i]));
        }

        return sorted;


}

int_TREE* for_each(int_TREE* tree,int f()){
        int_TREE* cur = tree;
        
        for (int i = 0; i <= length(tree); i++){
                cur-> data = f(cur->data);
                cur = get_next(cur);
        }

        return tree;
}

int includes(int_TREE* tree,int ele){
        int_TREE* cur = tree;
        
        for (int i = 0; i <= length(tree); i++){
                if(cur->data == ele){
                        return true;
                }
                cur = get_next(cur);
        }

        return false;
}


int length(int_TREE* tree){
        return tree->elements;
}


void print_tree(int_TREE* tree){

        int_TREE * cur = tree;
        for (int i = 0; i <= length(tree); i++)
        {
                printf("DATA: %d\n",cur-> data, i);
                cur = get_next(cur);
        }


}

int pop(int_TREE* tree){

        int_TREE* cur = tree;
        int_TREE* prev = cur;

        while(cur->next != (int)NULL){
                prev = cur;
                cur = get_next(cur);
        }

        prev->next = (int)NULL;
        tree->elements--;
        return cur->data;
}

int shift(int_TREE* tree){

        int_TREE* cur = tree;
        int_TREE* next = get_next(cur);
        int first_element = tree->data;
        while(next->next != (int)NULL){
                cur->data = next->data;
                cur = get_next(cur);
                next = get_next(cur);
        }
        
        cur->next = (int)NULL;

        tree->elements--;
        return first_element;
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




// int main (void){
//         int_TREE *tree = init_int_TREE(10);

//         for(int i = 9; i >= 6-1; i--){
//                 push(tree,init_int_TREE(i));
//         }

//         // shift(tree);
//         // print_tree(tree);
//         return 0;
// }


