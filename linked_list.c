#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


// prints out the entire list (doesn't work on an empty list)
void print_list( struct node * current ){
    printf("[");
    while( current->next ){
        printf("%s, ", current->data);
        current = current->next;
    }
    printf("%s]\n", current->data);
}



// inserts a node at the front of the list, returns the a pointer to
// the new front
struct node * insert_front( struct node * front, char * str ){
    struct node * new_front = (struct node *)malloc( sizeof(struct node) );
    new_front->data = str;
    new_front->next = front;
    return new_front;
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
struct node * insert_after( struct node * prev, char * str ){
	struct node * new = (struct node *)malloc( sizeof(struct node) );
	new->data = str;
	new->next = prev->next;
	prev->next = new;
	return new;
}
