//defining a struct for BT/BST
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} BST, root, first;

//defining a struct for lists
typedef struct cell {
    int first;
    struct cell* rest;
} list, rest;
