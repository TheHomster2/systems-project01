#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"


// adds a song to the appropriate linked list
void add_song( struct node * player[], char * song ){
    int player_index = song[0] - 97; // using the ascii values to get the index for the table
    struct node * n = player[ player_index ];
    n = insert_ordered(n, song);
    player[ player_index ] = n;
    return;
}


// prints the whole library
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


// returns the a pointer to the first instance of a song given the song name and
// artist name in the form artist:song
struct node * get_song( struct node * player[], char * song ){
    int player_index = song[0] - 97;
    struct node * n = player[ player_index ];
    return find_song(n, song);
}

// returns a pointer to the first song by the given artist
struct node * find_artist( struct node * player[], char * artist){
    int player_index = artist[0] - 97;
    struct node * n = player[ player_index ];
    return first_song_by(n, artist);
}

// prints all songs by artists starting with the given letter
void print_letter( struct node * player[], char letter){
    int player_index = letter - 97;
    struct node * n = player[ player_index ];
    print_list(n);
}

// prints all songs by the given artist
void print_songs_of( struct node * player[], char * artist){
    struct node * n = find_artist(player, artist);
    while(n&&strstr(n->data,artist)){
        printf("%s\n", n->data);
        n = n->next;
    }
}

/*
void shuffle( struct node * player[], int n){
    // find the first entry in the player
    int start_index = 0;
    while( !player[start_index] && start_index < 26){
        start_index++;
    }
    if (start_index >= 26){ // if there are no entries in the library
        return;
    }
    // link everything into one big list
    struct node * big_list = player[start_index];
    for( int i = 0; i < 26; i++ ){
        if( player[i] ){
            last_node( big_list )->next = player[i];
        }
    }

    for (int j = 0; j < n; j++){
        printf("%s\n", rand_song( big_list ) -> data);
    }
}
*/

// delete a song given in the form artist:song
void remove_song(struct node * player[], char * song){
    int index = song[0] - 97;
    player[index] = remove_node( player[index], get_song(player, song) );
}


void remove_all(struct node * player[]){
    for (int i = 0; i < 26; i++) {
        free_list( player[i] );
        player[i] = NULL;
    }
}
