#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *p);

int sum_squares(node *p);

node *map(node *p, int (*f)(int));

// small helper to create nodes for tests
static node* new_node(int data, node* next){
    node *n = malloc(sizeof(node));
    if(!n) return NULL;
    n->data = data;
    n->next = next;
    return n;
}


static void free_list(node *p){
    while(p){
        node *t = p->next;
        free(p);
        p = t;
    }
}

#endif // LINKED_LIST_H