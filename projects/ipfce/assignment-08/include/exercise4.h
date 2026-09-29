/*
 * Header file for Exercise 4
 * Assignment 8 - IPFCE 2025
 * 
 * Queue implementation using stacks (information hiding)
 * You must ONLY use stack methods, not access the stack implementation directly
 */

#ifndef _EXERCISE4_H_
#define _EXERCISE4_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Stack structure from Assignment 7 */
typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
} stack;

/* Stack operations from Assignment 7 (DO NOT MODIFY THESE) */
void initialize(stack *s);
void push(stack *s, int e);
int pop(stack *s);
bool empty(stack *s);
bool full(stack *s);

/* Queue structure using TWO stacks */
typedef struct {
    stack s1;  // Primary stack
    stack s2;  // Auxiliary stack
} queue;

/* Queue operations - implement these using ONLY stack methods above */
void init_queue(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
bool queue_empty(queue *q);
bool queue_full(queue *q);

/* Helper function to print the queue (for testing) */
void print_queue(queue *q);

#endif
