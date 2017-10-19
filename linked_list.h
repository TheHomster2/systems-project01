// the node struct we will use to build our linked lists
struct node {
    char * data;
    struct node * next;
};




// original functions
void print_list( struct node * );
struct node * insert_front( struct node *, char * );
struct node * free_list( struct node * );

// new functions
struct node * insert_at( struct node *, int, char * );
char * remove_node( struct node *, int );
struct node * remove_front( struct node * );
struct node * find_song(struct node *, char *);
struct node * first_song(struct node *, char *);
