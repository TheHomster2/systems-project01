struct node {
    char * data;
    struct node * next;
};



void print_list( struct node * );

struct node * insert_front( struct node *, char * );

struct node * free_list( struct node * );

struct node * insert_after( struct node *, char * );
