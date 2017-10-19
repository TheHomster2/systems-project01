#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"


int main(){
    struct node * test_list = NULL;
    srand( time(NULL) );

    printf("\nTesting insert_front:\n");
    test_list = insert_front(test_list, "kendrick lamar:humble");
    test_list = insert_front(test_list, "adelle:hello");
    test_list = insert_front(test_list, "mariah kerry:all i want for christmas");
    print_list(test_list);

    printf("\nTesting insert_at:\n");
    insert_at( test_list, 2, "kendrick lamar:dna");
    print_list(test_list);

    printf("\nTesting remove_node:\n");
    free( remove_node( test_list, 1) );
    print_list(test_list);
    test_list = remove_node( test_list, 0 );
    print_list( test_list );

    printf("\nREFRESHING LIST:\n");
    test_list = insert_front(test_list, "adelle:hello");
    test_list = insert_front(test_list, "mariah kerry:all i want for christmas");
    print_list( test_list );

    printf("\nTesting find_song:\n");
    printf("%s\n", find_song( test_list, "mariah kerry:all i want for christmas")->data );
    printf("%s\n", find_song( test_list, "adelle:hello")->data );
    printf("%s\n", find_song( test_list, "kendrick lamar:dna")->data );
    printf("%s\n", find_song( test_list, "kendrick lamar:humble")->data );
    if( !find_song( test_list, "big sean:bounce back") ){
        printf("Can't find the song...\n");
    }

    printf("\nTesting first_song:\n");
    printf("%s\n", first_song( test_list, "mariah kerry")->data );
    printf("%s\n", first_song( test_list, "adelle")->data );
    printf("%s\n", first_song( test_list, "kendrick lamar")->data );
    if( !find_song( test_list, "big sean") ){
        printf("Can't find a song by that artist...\n");
    }

    printf("\nTesting rand_song:\n");
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );
    printf("%s\n", rand_song( test_list )->data );


    free( test_list );
    return 0;
}
