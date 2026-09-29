/*
 * Header file for Exercise 3
 * Assignment 8 - IPFCE 2025
 * 
 * Queue implementation using singly-linked lists
 */

#ifndef _EXERCISE3_H_
#define _EXERCISE3_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Node structure for the queue */
typedef struct node {
    int data;
    struct node *next;
} node;

/* Queue structure using singly-linked list */
typedef struct {
    node *front;  // Pointer to the front of the queue
    node *rear;   // Pointer to the rear of the queue
    int count;    // Number of elements in the queue
} queue;

/* Initialize an empty queue */
void initialize(queue *q);

/* Insert item x at the back of queue q */
void enqueue(queue *q, int x);

/* Return (and remove) the front item from queue q */
int dequeue(queue *q);

/* Check if the queue is empty */
bool empty(const queue *q);

/* Check if the queue is full (always false for linked list implementation) */
bool full(const queue *q);

/* Helper function to print the queue (for testing) */
void print_queue(const queue *q);

#endif
