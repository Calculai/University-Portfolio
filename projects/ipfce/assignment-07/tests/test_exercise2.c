/*
 * Test file for Exercise 2 - Stack Implementation
 * Assignment 7 - IPFCE 2025
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/stack.h"

int main() {
    stack s;
    
    printf("Testing Exercise 2: Stack Implementation\n");
    
    // Test 1: Initialize stack
    initialize(&s);
    assert(s.head == NULL && "Test 1 failed: Stack should be initialized with NULL head");
    printf("Test 1 passed: Stack initialization\n");
    
    // Test 2: Empty stack check
    assert(empty(&s) == true && "Test 2 failed: Empty stack should return true");
    printf("Test 2 passed: Empty stack returns true\n");
    
    // Test 3: Full check (should always be false for linked list)
    assert(full(&s) == false && "Test 3 failed: Linked list stack should never be full");
    printf("Test 3 passed: Full stack returns false (linked list)\n");
    
    // Test 4: Push single item
    push(10, &s);
    assert(empty(&s) == false && "Test 4 failed: Stack should not be empty after push");
    printf("Test 4 passed: Push single item (stack not empty)\n");
    
    // Test 5: Pop single item
    int popped = pop(&s);
    assert(popped == 10 && "Test 5 failed: Pop should return 10");
    printf("Test 5 passed: Pop returns correct value (10)\n");
    
    // Test 6: Stack empty after popping all items
    assert(empty(&s) == true && "Test 6 failed: Stack should be empty after popping all items");
    printf("Test 6 passed: Stack empty after popping all items\n");
    
    // Test 7: Push multiple items and check LIFO order
    push(1, &s);
    push(2, &s);
    push(3, &s);
    int top = pop(&s);
    assert(top == 3 && "Test 7 failed: LIFO order - should pop 3 first");
    printf("Test 7 passed: LIFO order (push 1,2,3; pop returns 3)\n");
    
    // Test 8: Continue popping in LIFO order
    int second = pop(&s);
    assert(second == 2 && "Test 8 failed: LIFO order - should pop 2 second");
    printf("Test 8 passed: LIFO order continues (pop returns 2)\n");
    
    // Test 9: Last item
    int third = pop(&s);
    assert(third == 1 && "Test 9 failed: LIFO order - should pop 1 last");
    printf("Test 9 passed: LIFO order final (pop returns 1)\n");
    
    // Test 10: Push multiple items and verify order
    initialize(&s);
    for (int i = 1; i <= 5; i++) {
        push(i * 10, &s);
    }
    int first_pop = pop(&s);
    int second_pop = pop(&s);
    assert(first_pop == 50 && "Test 10 failed: First pop should be 50");
    assert(second_pop == 40 && "Test 10 failed: Second pop should be 40");
    printf("Test 10 passed: Multiple push/pop maintains LIFO order\n");
    
    // Clean up remaining items
    while (!empty(&s)) {
        pop(&s);
    }
    
    printf("\nAll Exercise 2 tests passed!\n");
    return 0;
}
