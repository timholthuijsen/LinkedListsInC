#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


//Depth first search in a bst
list* bt_ints_depth_first(BST* bst) {
    struct cell* output;
    BST* newtree;
    newtree = NULL;
    output = NULL;


    while (bst->value != NULL) {
        output = (struct cell*) malloc(sizeof(struct cell));    
        output->first = bst->value;
        output->rest = bt_ints_depth_first(bst->left);
      
        if (bst->left != NULL) {
            output->rest = bt_ints_depth_first(bst->left);
        }
        if (bst->right != NULL) {
            output->rest = bt_ints_depth_first(bst->right);
        }
        
        bst->value = NULL;
        
       
    }
    return output;

}

/* Returns true if node n is present in bst, false otherwise. */

bool bst_contains(BST* bst, int n) {
    if (bst == NULL) {
        return false;
    }
    if (bst->value == n) {
        return true;
    }
    BST* searchtree;
    searchtree = bst;

    while (searchtree != NULL) {
        searchtree = bst->left;
        if (searchtree->value == n) {
            return true;
        }
        searchtree = searchtree->left;
        if (searchtree->value == n) {
            return true;
        }
        searchtree = searchtree->right;
        if (searchtree->value == n) {
            return true;
        }


    }
    searchtree = bst;

    while (searchtree != NULL) {
        searchtree = bst->right;
        if (searchtree->value == n) {
            return true;
        }
        searchtree = searchtree->left;
        if (searchtree->value == n) {
            return true;
        }
        searchtree = searchtree->right;
        if (searchtree->value == n) {
            return true;
        }
        return false;
    }
}


void print_bst_left(BST* bst) {
    BST* printtree = bst;
    while (printtree->value != NULL) {
        printf("%d", printtree->value);
        printtree = printtree->left;
    }
}




//A function to insert an integer at the appropriate location in a BST
BST* insert_bst(struct node* root, int val) {
    /*Create a new node*/
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = val;
    struct node* first = root;
    while (root != NULL) {
        first = root;
        if (val < root->value)
        {
            root = root->left;
            printf("took a step to the left with %d \n", val);
        }
        else {
            root = root->right;
            printf("took a step to the right with %d \n", val);
        }
    }

    if (first == NULL)
    {
        first = new_node;
        printf("inserted %d in this location \n", val);
    }
    else if (val < first->value) {
        first->left = new_node;
        printf("inserted %d to the left \n", val);
    }
    else {
        first->right = new_node;
        printf("inserted %d to the right \n", val);
    }

    return first;
}


//creates a bst containing n random numbers
BST* bst_insert_randoms(int n) {
    BST* newtree = NULL;
    int b = 0;

    for (b = 0; b < n; b++) {
        int a = rand() % 100;
        newtree = insert_bst(newtree, a);
       
    }
    return newtree;
}

//checks whether a list is exclusively ascending
bool ascending(list* list) {
    int firstlist;
    int firstrestlist;

    while (list->rest) {
        firstlist = list->first;
        list = list->rest;
        firstrestlist = list->first;
        if (firstlist > firstrestlist) {
            printf("%s", "false");
            return false;
        }
    }
    printf("%s", "true");
    return true;
}



list* make_random_list(int length) {
    list* list;
    struct cell* c;

    list = NULL;
    while (length--) {
        c = (struct cell*) malloc(sizeof(struct cell));
        c->first = rand() % 100;
        c->rest = list;
        list = c;
    }

    printf("\n");

    return list;
}


int list_length(list* list) {
    int length = 0;

    while (list) {
        length++;
        list = list->rest;
    }

    return length;
}


void print_list(list* list) {
    while (list) {
        printf("%d ", list->first);
        list = list->rest;
    }
    printf("\n");
}

// Free the memory of all of the cells in list
void free_list(list* list) {
    struct cell* next;

    while (list) {
        next = list->rest;
        free(list);
        list = next;
    }
}

void main() {
    BST* bt = NULL;
    list* list = NULL;
    bt = bst_insert_randoms(50);
    //list = bt_ints_depth_first(bt);
    print_bst(bt);

    print_list(list);

   

    

}


