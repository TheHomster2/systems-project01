#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
};



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


int main(){
    struct node * list = (struct node *)malloc( sizeof(struct node) );
    list->data = 10;
    list->next = NULL;
    print_list( list );
    list = insert_front(list, 9);
    list = insert_front(list, 8);
    list = insert_front(list, 7);
    list = insert_front(list, 6);
    list = insert_front(list, 5);
    print_list( list );
    free_list( list );

    return 0;
}
