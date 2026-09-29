/*
 * Test file for Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Tests the three "laws" that any queue implementation should satisfy:
 * 1. After init_queue(q), the queue q must be empty
 * 2. After enqueue(q,x); y = dequeue(q); x must equal y
 * 3. After enqueue(q,x0); enqueue(q,x1); y0=dequeue(q); y1=dequeue(q);
 *    x0 must equal y0 and x1 must equal y1
 */

#include <stdio.h>
#include <assert.h>
#include "../include/exercise3.h"

/* Helper function to check queue state */
int queue_size(const queue *q) {
    return q->count;
}

int main() {
    printf("Testing Exercise 3: Queue Implementation using Singly-Linked Lists\n\n");
    
    // Test 1: Initialization (Queue Law 1)
    printf("Test 1: Queue Law 1 - After initialize(q), queue must be empty\n");
    queue q1;
    initialize(&q1);
    assert(empty(&q1) && "Queue should be empty after initialization");
    assert(q1.front == NULL && "Front should be NULL");
    assert(q1.rear == NULL && "Rear should be NULL");
    printf("✓ Queue is empty after initialization\n\n");
    
    // Test 2: Single enqueue/dequeue (Queue Law 2)
    printf("Test 2: Queue Law 2 - enqueue(q,x); y=dequeue(q); x must equal y\n");
    queue q2;
    initialize(&q2);
    int x = 42;
    enqueue(&q2, x);
    int y = dequeue(&q2);
    assert(x == y && "Dequeued value should equal enqueued value");
    assert(empty(&q2) && "Queue should be empty after dequeue");
    printf("✓ x=%d, y=%d (equal)\n\n", x, y);
    
    // Test 3: FIFO order (Queue Law 3)
    printf("Test 3: Queue Law 3 - FIFO order with two elements\n");
    queue q3;
    initialize(&q3);
    int x0 = 10, x1 = 20;
    enqueue(&q3, x0);
    enqueue(&q3, x1);
    int y0 = dequeue(&q3);
    int y1 = dequeue(&q3);
    assert(x0 == y0 && "First dequeued should equal first enqueued");
    assert(x1 == y1 && "Second dequeued should equal second enqueued");
    assert(empty(&q3) && "Queue should be empty");
    printf("✓ FIFO maintained: x0=%d, y0=%d; x1=%d, y1=%d\n\n", x0, y0, x1, y1);
    
    // Test 4: Multiple operations
    printf("Test 4: Multiple operations (5 elements)\n");
    queue q4;
    initialize(&q4);
    for (int i = 1; i <= 5; i++) {
        enqueue(&q4, i);
    }
    for (int i = 1; i <= 5; i++) {
        int val = dequeue(&q4);
        assert(val == i && "Values should be dequeued in FIFO order");
    }
    assert(empty(&q4) && "Queue should be empty");
    printf("✓ Multiple operations maintain FIFO order\n\n");
    
    // Test 5: Interleaved operations
    printf("Test 5: Interleaved enqueue and dequeue\n");
    queue q5;
    initialize(&q5);
    enqueue(&q5, 1);
    enqueue(&q5, 2);
    assert(dequeue(&q5) == 1 && "Should dequeue 1");
    enqueue(&q5, 3);
    assert(dequeue(&q5) == 2 && "Should dequeue 2");
    assert(dequeue(&q5) == 3 && "Should dequeue 3");
    assert(empty(&q5) && "Queue should be empty");
    printf("✓ Interleaved operations work correctly\n\n");
    
    // Test 6: Larger test
    printf("Test 6: Larger test (20 elements)\n");
    queue q6;
    initialize(&q6);
    for (int i = 0; i < 20; i++) {
        enqueue(&q6, i);
    }
    for (int i = 0; i < 20; i++) {
        int val = dequeue(&q6);
        assert(val == i && "Values should match in FIFO order");
    }
    assert(empty(&q6) && "Queue should be empty");
    printf("✓ Larger test passed\n\n");
    
    printf("🎉 All tests passed! All three queue laws verified.\n");
    return 0;
}
