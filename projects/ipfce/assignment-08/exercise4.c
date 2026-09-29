/*
 * Exercise 4: Queue Implementation using Stacks (Information Hiding)
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using TWO stacks and ONLY stack methods.
 * You must NOT access the stack implementation directly.
 * This demonstrates the concept of information hiding.
 */

#include "exercise4.h"

/* 
 * Stack operations from Assignment 7
 * These are the ONLY operations you can use on stacks
 */

/* Initialize an empty stack */
void initialize(stack *s) {
    s->head = NULL;
}

/* Push an element onto the stack */
void push(stack *s, int e) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node != NULL) {
        new_node->data = e;
        new_node->next = s->head;
        s->head = new_node;
    }
}

/* Pop an element from the stack */
int pop(stack *s) {
    if (empty(s)) {
        return -1;  // Error case
    }
    node *temp = s->head;
    int data = temp->data;
    s->head = s->head->next;
    free(temp);
    return data;
}

/* Check if stack is empty */
bool empty(stack *s) {
    return s->head == NULL;
}

/* Check if stack is full (always false for linked list) */
bool full(stack *s) {
    return false;
}

/* 
 * Queue operations - implement using ONLY the stack methods above
 * DO NOT access s->head or any internal stack structure directly!
 */

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: both stacks in the queue are empty
 */
void init_queue(queue *q) {
    initialize(&q->s1);
    initialize(&q->s2);
    /* TODO: initialize queue */
}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 */
void enqueue(queue *q, int x) {
    push(&q->s1,x);
    /* TODO: Implement enqueue using ONLY stack operations */
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 */
int dequeue(queue *q) {
    if (queue_empty(q)) {printf("failed to dequeue, queue is empty, returning -1"); return -1;}

    while (!empty(&q->s1)) {push(&q->s2,pop(&q->s1));} 
    // Reverse order to give access to back of queue
    
    int val = pop(&q->s2); 
    // Takes the former rear of queue

    while (!empty(&q->s2)) {push(&q->s1,pop(&q->s2));} 
    // Reverse order to original order with missing element from rear

    return val;  
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if both stacks are empty, false otherwise
 */
bool queue_empty(queue *q) {
    return empty(&q->s1);  
}

/* 
* Check if the queue is full
*/
bool queue_full(queue *q) {
    return false;
}

/* Helper function to print the queue */
void print_queue(queue *q) {
    /* Note: This function needs to access the structure for display purposes
     * In a real implementation, you might not have this function,
     * or you'd implement it using only the queue operations
     */
    printf("Queue contents: ");
    
    // Temporary stacks to preserve queue state
    stack temp1, temp2;
    initialize(&temp1);
    initialize(&temp2);
    
    // Copy s2 to temp (s2 has elements in dequeue order)
    while (!empty(&q->s2)) {
        int val = pop(&q->s2);
        push(&temp1, val);
    }
    
    // Copy s1 to temp (s1 has elements in reverse order)
    while (!empty(&q->s1)) {
        int val = pop(&q->s1);
        push(&temp2, val);
    }
    
    // Print temp1 (these will be dequeued first)
    while (!empty(&temp1)) {
        int val = pop(&temp1);
        printf("%d ", val);
        push(&q->s2, val);  // Restore
    }
    
    // Print temp2 in reverse (these will be dequeued last)
    while (!empty(&temp2)) {
        int val = pop(&temp2);
        push(&temp1, val);
    }
    while (!empty(&temp1)) {
        int val = pop(&temp1);
        printf("%d ", val);
        push(&q->s1, val);  // Restore
    }
    
    printf("\n");
}

