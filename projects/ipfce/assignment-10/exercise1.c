#include <stdio.h>
#include "linked_list.h"

// Write a *recursive* function that prints out a linked list of integers, with the following signature:
void print_list(node *p){

    if (p == NULL) {return;}
    
    fprintf(stderr,"%d ", p->data);
    p = p->next;
    print_list(p);
}