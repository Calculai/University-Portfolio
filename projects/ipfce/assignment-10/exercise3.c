#include <stdio.h>
#include "linked_list.h"

// Write a recursive function that takes a linked list of integers, and returns the sum of the _squares_ of the integers in the list
int sum_squares(node *p){
    
    if (p == NULL) {return 0;}

    return ((p->data * p->data) + sum_squares(p->next));
}