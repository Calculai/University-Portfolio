#include <stdio.h>
#include "linked_list.h"

// Write a recursive function that takes a linked list of integers, and a function pointer f,
// and returns a new linked list where each integer has been transformed by f
node *map(node *p, int (*f)(int)){

    if (p == NULL) {return NULL;} 

    node* n = malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "malloc failed in map\n");
        exit(EXIT_FAILURE);
    }

    n->data = f(p->data);
    n->next = map(p->next, f);

    return n;
}

