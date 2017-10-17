#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


// prints out the entire list (doesn't work on an empty list)
void print_list( struct node * current ){
    printf("[");
    while( current->next ){
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("%d]\n", current->data);
}


// inserts a node at the front of the list, returns the a pointer to
// the new front
struct node * insert_front( struct node * n, int i ){
    struct node * new = (struct node *)malloc( sizeof(struct node) );
    new->data = i;
    new->next = n;
    return new;
}



// goes through a list and frees all of the memory
struct node * free_list( struct node * current ){
    while( current ){
        struct node * temp = current;
        current = current->next;
        free(temp);
    }
    return NULL;
}



// inserts a new node after a specific node in the list, and returns a pointer
// to the new node.
struct node * insert_after( struct node * prev, int data ){
	struct node * new = (struct node *)malloc( sizeof(struct node) );
	new->data = data;
	new->next = prev->next;
	prev->next = new;
	return new;
}
