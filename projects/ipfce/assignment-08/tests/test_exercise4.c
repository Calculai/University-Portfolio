/*
 * Test file for Exercise 4: Queue using Stacks (Information Hiding)
 * Assignment 8 - IPFCE 2025
 * 
 * Tests queue implementation that uses ONLY stack operations
 */

#include <stdio.h>
#include <assert.h>
#include "../include/exercise4.h"

int main() {
    printf("Testing Exercise 4: Queue Implementation using Stacks\n\n");
    
    // Test 1: Initialization
    printf("Test 1: Queue initialization\n");
    queue q1;
    init_queue(&q1);
    assert(queue_empty(&q1) && "Queue should be empty after initialization");
    assert(!queue_full(&q1) && "Queue should not be full");
    printf("✓ Queue is empty after initialization\n\n");
    
    // Test 2: Single enqueue and dequeue
    printf("Test 2: Single enqueue/dequeue\n");
    queue q2;
    init_queue(&q2);
    enqueue(&q2, 42);
    int val = dequeue(&q2);
    assert(val == 42 && "Dequeued value should be 42");
    assert(queue_empty(&q2) && "Queue should be empty after dequeue");
    printf("✓ Single enqueue/dequeue works correctly\n\n");
    
    // Test 3: FIFO order
    printf("Test 3: FIFO order with three elements\n");
    queue q3;
    init_queue(&q3);
    enqueue(&q3, 1);
    enqueue(&q3, 2);
    enqueue(&q3, 3);
    assert(dequeue(&q3) == 1 && "First element should be 1");
    assert(dequeue(&q3) == 2 && "Second element should be 2");
    assert(dequeue(&q3) == 3 && "Third element should be 3");
    assert(queue_empty(&q3) && "Queue should be empty");
    printf("✓ FIFO order maintained\n\n");
    
    // Test 4: Interleaved operations
    printf("Test 4: Interleaved enqueue/dequeue\n");
    queue q4;
    init_queue(&q4);
    enqueue(&q4, 10);
    enqueue(&q4, 20);
    assert(dequeue(&q4) == 10 && "Should dequeue 10");
    enqueue(&q4, 30);
    enqueue(&q4, 40);
    assert(dequeue(&q4) == 20 && "Should dequeue 20");
    assert(dequeue(&q4) == 30 && "Should dequeue 30");
    assert(dequeue(&q4) == 40 && "Should dequeue 40");
    assert(queue_empty(&q4) && "Queue should be empty");
    printf("✓ Interleaved operations work correctly\n\n");
    
    // Test 5: Multiple operations
    printf("Test 5: Multiple operations (10 elements)\n");
    queue q5;
    init_queue(&q5);
    for (int i = 1; i <= 10; i++) {
        enqueue(&q5, i * 10);
    }
    for (int i = 1; i <= 10; i++) {
        int val = dequeue(&q5);
        assert(val == i * 10 && "Values should be dequeued in FIFO order");
    }
    assert(queue_empty(&q5) && "Queue should be empty");
    printf("✓ Multiple operations maintain FIFO order\n\n");
    
    // Test 6: Larger stress test
    printf("Test 6: Stress test (25 elements)\n");
    queue q6;
    init_queue(&q6);
    for (int i = 0; i < 25; i++) {
        enqueue(&q6, i);
    }
    for (int i = 0; i < 25; i++) {
        int val = dequeue(&q6);
        assert(val == i && "Values should match in FIFO order");
    }
    assert(queue_empty(&q6) && "Queue should be empty");
    printf("✓ Stress test passed\n\n");
    
    printf("🎉 All tests passed!\n");
    return 0;
}

