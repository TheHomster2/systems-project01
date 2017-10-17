#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void print_list( struct node * current ){
    printf("[");
    while( current->next ){
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("%d]\n", current->data);
}


struct node * insert_front( struct node * n, int i ){
    struct node * new = (struct node *)malloc( sizeof(struct node) );
    new->data = i;
    new->next = n;
    return new;
}


struct node * free_list( struct node * current ){
    while( current ){
        struct node * temp = current;
        current = current->next;
        free(temp);
    }
    return NULL;
}

struct node * insert_after( struct node * prev, int data ){
	struct node * new = (struct node *)malloc( sizeof(struct node) );
	new->data = data;
	new->next = prev->next;
	prev->next = new;
	return new;
}


