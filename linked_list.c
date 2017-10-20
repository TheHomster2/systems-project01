#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"


// prints out the entire list (doesn't work on an empty list)
void print_list( struct node * current ){
    printf("[");
    if( !current ){
        printf("]\n");
        return;
    }
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


// inserts a new node in alphabetical order and returns a pointer to the head
struct node * insert_ordered( struct node * n, char * song ){
    struct node * new = (struct node *)malloc( sizeof(struct node) );
    new->data = song;
    new->next = NULL;

    // handle first node case
    if( !n ){
        return new;
    }

    // if it's the new front;
    if( strcmp(song, n->data) < 0 ){
        new->next = n;
        return new;
    }

    struct node * head = n;
    struct node * temp = (struct node *)malloc( sizeof(struct node) );

    while( n && strcmp( song, n->data) > 0 ){
        temp = n;
        n = n->next;
    }

    temp->next = new;
    new->next = n;

    return head;
}




// inserts a new node at a specific index (must be a valid index) and returns a
// pointer to the new node.
struct node * insert_at( struct node * n, int index, char * str ){
    if( index == 0 ){ // special case
        return insert_front(n, str);
    }
    while( --index ){ // get the node in front of where you're inserting
        n = n->next;
    }
	struct node * new = (struct node *)malloc( sizeof(struct node) );
	new->data = str;
	new->next = n->next;
	n->next = new;
	return new;
}


/*
// inserts after a specific node
struct node * insert_after( struct node * prev, char * str ){
    struct node * new = (struct node *)malloc( sizeof(struct node) );
	new->data = str;
	new->next = n->next;
	n->next = new;
	return new;
}
*/


// removes the specified node from the list (must be a valid index) and returns
// a pointer to it
// IF INDEX != 0: RETURNS A POINTER TO THE REMOVED NODE
// IF INDEX = 0: RETURNS A POINER TO THE NEW FRONT
struct node * remove_node( struct node * n, int index ){
    if( !index ){
        return remove_front( n );
    }
    while( --index ){
        n = n->next;
    }
    struct node * temp = n->next; // to return
    n->next = n->next->next;
    return temp;
}


// removes the first node from the list
struct node * remove_front( struct node * n ){
    struct node * temp = n; // for freeing memory
    n = n->next;
    free(temp);
    return n;
}


// returns a pointer based on a artist name and song name in the form artist:song
struct node * find_song( struct node * n, char * art_song_name){
    while( n ){
        if( !strcmp(n->data, art_song_name) ){
            return n;
        }
        n = n->next;
    }
    return NULL;
}


// returns a pointer to the first song of the given artist name
struct node * first_song_by( struct node * n, char * artist){
    while( n ){
        if( strstr(n->data, artist) ){
            return n;
        }
        n = n->next;
    }
    return NULL;
}



// returns a pointer to a random node in the list (I DON'T LIKE THIS IMPLEMENTATION
// BUT I'M TOO LAZY TO MAKE A BETTER ONE)
struct node * rand_song( struct node * n ){
    struct node * temp = n;
    int list_len = 0;
    while( temp ){
        list_len++;
        temp = temp->next;
        // printf("CURRENT ADDRESS: %p\n", temp);
    }
    int index = rand() % list_len;
    // printf("INDEX = %d\n", index);
    while( index ){
        index--;
        n = n->next;
    }
    return n;
}
