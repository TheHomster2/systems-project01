#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"


void add_song( struct node * player[], char * song ){
    int player_index = song[0] - 97; // using the ascii values to get the index for the table
    struct node * n = player[ player_index ];
    n = insert_ordered(n, song);
    player[ player_index ] = n;
    return;
}


void print_lib( struct node * player[] ){
    int i = 0;
    for(; i < 26; i++){
        char letter = i + 97;
        if( player[i] ){
            printf("\'%c\' entries:\n", letter);
            print_list( player[i] );
        }
    }
}
