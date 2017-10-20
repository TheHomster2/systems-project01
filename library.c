#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

struct node * player[26];

void add_song( char * song ){
    int index = song[0] - 97; // using the ascii values to get the index for the table
    struct node * n = player[ index ];
    while( n && strcmp( n->data, song ) ){
        
    }
}
