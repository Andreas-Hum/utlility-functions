#include "utils.h"
#include <stdio.h>


int main(void){

        int arr[10] = {1,2,3,4,5,6,7,8,9,10};
        int_linked_list* tester = create_list_from_int_array(arr,10);
        sort_int_linked_list(&tester);
        print_linked_list(tester);
        
        return 0;
}



