#include "utils.h"
#include <stdio.h>

int sum(int i){
        return i * 2;
}
int equals_5(int i){
        return i==5;
}

int main(void){

        int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
        int_tree* test_array = create_tree_from_int_array(arr,12);


        // int test = pop(test_array);
        print_tree(test_array);

        return 0;
}



