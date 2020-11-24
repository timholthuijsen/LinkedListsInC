#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




void main() {
    BST* bt = NULL;
    list* list = NULL;
    bt = bst_insert_randoms(50);
    //list = bt_ints_depth_first(bt);
    //print_bst(bt);
    //bst_contains(bt, 42);
    print_list(list);
}
