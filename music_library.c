#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"

srand(time(NULL));


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

struct node * get_song( struct node * player[], char * song ){
    int player_index = song[0] - 97;
    struct node * n = player[ player_index ];
    return find_song(n, song);
}

struct node * find_artist( struct node * player[], char * artist){
    int player_index = song[0] - 97;
    struct node * n = player[ player_index ];
    return first_song_by(n, artist);
}

void print_letter( struct node * player[], char letter){
    int player_index = letter - 97;
    struct node * n = player[ player_index ];
    print_list(n);
}

void print_songsof( struct node * player[], char * artist){
    struct node * n = find_artist(player, artist);
    while(n&&strstr(n->data,artist)){
        printf("%s\n", n->data);
    }
}

void shuffle( struct node * player[], int n){
    for (int i = 0; i < n; i++){
        int index = rand() % 26;
        printf("%s\n", rand_song(player[ index ]) -> data);
    }
}



