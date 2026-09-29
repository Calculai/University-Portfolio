/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "exercise3.h"
#include <assert.h>
#include <string.h>

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    memset(q, 0, sizeof(queue)); 
    /*
    Will ensure even if there are more fields 
    added they are set to zero equivalent for 
    data type
    */
}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
   
    node* n1 = malloc(sizeof(node));
    if (n1 == NULL) {printf("Memory allocation failed\n"); return;}

    n1->data = x;
    n1->next = NULL;
    if (q->count == 0)
    {
        q->front = n1;
        q->rear = n1;
        
    }else{
        q->rear->next = n1;
        q->rear = n1;
    }
    
    q->count++;
    assert(q->rear->data == x);
    return;
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    if (empty(q)) {printf("failed to dequeue, queue empty, returned -1\n"); return -1;}
    
    int val = q->front->data;
    node* garb = q->front;
    q->front = q->front->next;
    free(garb);
    q->count--;

    return val;  
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    return (q->count == 0); 
}

/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
    return (0 == 1);
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

