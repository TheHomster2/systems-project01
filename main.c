#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"


int main(){
    // LINKED LIST TESTS:

    struct node * test_list = NULL;
    srand( time(NULL) );

    printf("LINKED LIST TESTS:\n");
    printf("===========================================================================================\n");

    printf("\nTesting insert_front/print_list:\n");
    test_list = insert_front(test_list, "kendrick lamar:humble");
    test_list = insert_front(test_list, "adelle:hello");
    print_list(test_list);
    printf("==============================\n");

    printf("\nTesting insert_ordered:\n");
    test_list = insert_ordered( test_list, "kendrick lamar:dna");
    test_list = insert_ordered(test_list, "mariah kerry:all i want for christmas");
    print_list(test_list);
    printf("==============================\n");


    printf("\nTesting find_song:\n");
    printf("Finding \"mariah kerry:all i want for christmas\"...\n");
    printf("%s\n", find_song( test_list, "mariah kerry:all i want for christmas")->data );
    printf("Finding \"adelle:hello\"...\n");
    printf("%s\n", find_song( test_list, "adelle:hello")->data );
    printf("Finding \"kendrick lamar:dna\"...\n");
    printf("%s\n", find_song( test_list, "kendrick lamar:dna")->data );
    printf("Finding \"kendrick lamar:humble\"...\n");
    printf("%s\n", find_song( test_list, "kendrick lamar:humble")->data );
    printf("Finding \"big sean:bounce back\"...\n");
    if( !find_song( test_list, "big sean:bounce back") ){
        printf("Can't find the song...\n");
    }
    printf("==============================\n");

    printf("\nTesting first_song_by:\n");
    printf("Finding first song by \"mariah kerry\"...\n");
    printf("%s\n", first_song_by( test_list, "mariah kerry")->data );
    printf("Finding first song by \"adelle\"...\n");
    printf("%s\n", first_song_by( test_list, "adelle")->data );
    printf("Finding first song by \"kendrick lamar\"...\n");
    printf("%s\n", first_song_by( test_list, "kendrick lamar")->data );
    printf("Finding first song by \"big sean\"...\n");
    if( !first_song_by( test_list, "big sean") ){
        printf("Can't find a song by that artist...\n");
    }
    printf("==============================\n");

    printf("\nTesting rand_song:\n");
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("==============================\n");

    printf("\nTesting remove_node:\n");
    test_list = remove_node( test_list, find_song( test_list, "mariah kerry:all i want for christmas") );
    test_list = remove_node( test_list, find_song( test_list, "adelle:hello") );
    print_list( test_list );
    printf("==============================\n");


    free( test_list );



    printf("\nMUSIC LIBRARY TESTS:\n");
    printf("\n===========================================================================================\n");

    struct node * player[26];
    for(int i = 0; i < 26; i++){
        player[i] = NULL;
    }
    // print_lib( player );

    printf("\nTesting add_song/print_lib:\n");
    add_song(player, "bruno mars:uptown funk");
    add_song(player, "bruno mars:star");
    add_song(player, "bruno mars:a song with a");
    add_song(player, "bruno mars:a song with z");
    add_song(player, "eminem:campaign speech");
    add_song(player, "eminem:stronger");
    add_song(player, "adelle:hello");
    add_song(player, "adelle:rolling in the deep");
    add_song(player, "pearl jam:a song");
    add_song(player, "pearl jam:b song");
    add_song(player, "pearl jam:c song");
    add_song(player, "pink floyd:a song");
    add_song(player, "pink floyd:b song");
    add_song(player, "pink floyd:c song");
    add_song(player, "post malone:white iverson");
    add_song(player, "post malone:rockstar");
    print_lib( player );
    printf("==============================\n");

    printf("\nTesting get_song:\n");
    printf("Getting adelle:hello:\n");
    printf("%s\n", get_song(player, "adelle:hello")->data );
    printf("Getting eminem:stronger:\n");
    printf("%s\n", get_song(player, "eminem:stronger")->data );
    printf("==============================\n");

    printf("\nTesting find_artist:\n");
    printf("All songs following pink floyd:\n");
    print_list( find_artist(player, "pink floyd") );
    printf("==============================\n");

    printf("\nTesting print_letter:\n");
    printf("All songs by artists starting with \'p\'\n");
    print_letter(player, 'p');
    printf("==============================\n");

    printf("\nTesting print_songs_of:\n");
    printf("All songs by post malone:\n");
    print_songs_of(player, "post malone");
    printf("All songs by eminem:\n");
    print_songs_of(player, "eminem");
    printf("==============================\n");


    printf("\nTesting shuffle:\n");
    shuffle(player, 10);
    printf("==============================\n");

    printf("\nTesting remove_song:\n");
    remove_song(player, "eminem:stronger");
    printf("Removed eminem:stronger:\n");
    print_lib(player);
    printf("==============================\n");

    printf("\nTesting remove_all:\n");
    remove_all(player);
    print_lib(player);
    printf("==============================\n");


    return 0;
}
