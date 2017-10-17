struct node {
    int data;
    struct node * next;
};



void print_list( struct node * current );

struct node * insert_front( struct node * n, int i );

struct node * free_list( struct node * current );
