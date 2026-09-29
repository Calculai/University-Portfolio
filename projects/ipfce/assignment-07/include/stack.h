/*
 * Stack data structure implemented using linked list
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc, free */
#include <stdbool.h> /* bool, true, false */

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
} stack;

/* Create an empty stack */
void initialize(stack *s);

/* Insert item x at the top of stack s */
void push(int x, stack *s);

/* Return (and remove) the top item of stack s */
int pop(stack *s);

/* Test whether a stack can accept more pushes */
bool full(stack *s);

/* Test whether a stack can accept more pops */
bool empty(stack *s);

/* Print the contents of the stack */
void print(stack *s);

/* Cleans up stack made with malloc */
void destroy_stack(stack *s);

#endif