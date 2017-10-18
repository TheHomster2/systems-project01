#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(){
    struct node * test_list = (struct node *)malloc( sizeof(struct node) );
    test_list->next = NULL;
    test_list->data = NULL;
    printf("An empty list:\n");
    print_list(test_list);

    printf("Testing insert_front:\n");
    test_list = insert_front(test_list, "hello");
    test_list = insert_front(test_list, "cool");
    test_list = insert_front(test_list, "wassup");
    print_list(test_list);
    return 0;
}
