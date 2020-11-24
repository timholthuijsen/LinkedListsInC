typedef struct cell {
  int first;
  struct cell *rest;
} list;

list * make_random_list(int length);
int list_length(list *list);
void free_list(list *list);
void print_list(list *list);
