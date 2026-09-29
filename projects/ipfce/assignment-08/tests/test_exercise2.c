/*
 * Test file for Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/exercise2.h"



/* Helper function to check if list is sorted */
bool is_sorted(node* list) {
    if (list == NULL || list->next == NULL) {
        return true;
    }
    
    node* current = list;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

/* Helper function to get list length */
int list_length(node* list) {
    int count = 0;
    node* current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* Helper function to create a list from an array */
node* create_list_from_array(int arr[], int size) {
    if (size == 0) return NULL;
    
    node* head = create_node(arr[0]);
    node* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = create_node(arr[i]);
        current = current->next;
    }
    
    return head;
}

/* Helper function to check if list matches expected array */
bool list_matches_array(node* list, int expected[], int size) {
    node* current = list;
    for (int i = 0; i < size; i++) {
        if (current == NULL || current->data != expected[i]) {
            return false;
        }
        current = current->next;
    }
    return current == NULL;  // Should be at end of list
}

int main() {
    printf("Testing Exercise 2: Insertion Sort for Singly Linked List\n\n");
    
    // Test 1: Sort the example from the assignment [5, 1, 3, 7, 2]
    printf("Test 1: Sort [5, 1, 3, 7, 2]\n");
    int arr1[] = {5, 1, 3, 7, 2};
    int expected1[] = {1, 2, 3, 5, 7};
    node* list1 = create_list_from_array(arr1, 5);
    printf("Before: ");
    print_list(list1);
    list1 = isort(list1);
    printf("After:  ");
    print_list(list1);
    assert(is_sorted(list1) && "Test 1 failed: List should be sorted");
    assert(list_matches_array(list1, expected1, 5) && "Test 1 failed: List order incorrect");
    assert(list_length(list1) == 5 && "Test 1 failed: List length changed");
    printf("✓ Test 1 passed\n\n");
    free_list(list1);
    
    // Test 2: Already sorted list
    printf("Test 2: Already sorted list [1, 2, 3, 4, 5]\n");
    int arr2[] = {1, 2, 3, 4, 5};
    node* list2 = create_list_from_array(arr2, 5);
    printf("Before: ");
    print_list(list2);
    list2 = isort(list2);
    printf("After:  ");
    print_list(list2);
    assert(is_sorted(list2) && "Test 2 failed: List should remain sorted");
    assert(list_matches_array(list2, arr2, 5) && "Test 2 failed: Order should not change");
    printf("✓ Test 2 passed\n\n");
    free_list(list2);
    
    // Test 3: Reverse sorted list
    printf("Test 3: Reverse sorted [5, 4, 3, 2, 1]\n");
    int arr3[] = {5, 4, 3, 2, 1};
    int expected3[] = {1, 2, 3, 4, 5};
    node* list3 = create_list_from_array(arr3, 5);
    printf("Before: ");
    print_list(list3);
    list3 = isort(list3);
    printf("After:  ");
    print_list(list3);
    assert(is_sorted(list3) && "List should be sorted");
    assert(list_matches_array(list3, expected3, 5) && "List order incorrect");
    printf("✓ Test 3 passed\n\n");
    free_list(list3);
    
    // Test 4: List with duplicates
    printf("Test 4: List with duplicates [3, 1, 4, 1, 5]\n");
    int arr4[] = {3, 1, 4, 1, 5};
    int expected4[] = {1, 1, 3, 4, 5};
    node* list4 = create_list_from_array(arr4, 5);
    printf("Before: ");
    print_list(list4);
    list4 = isort(list4);
    printf("After:  ");
    print_list(list4);
    assert(is_sorted(list4) && "List should be sorted");
    assert(list_matches_array(list4, expected4, 5) && "List order incorrect");
    printf("✓ Test 4 passed\n\n");
    free_list(list4);
    
    // Test 5: Two elements
    printf("Test 5: Two elements [2, 1]\n");
    int arr5[] = {2, 1};
    int expected5[] = {1, 2};
    node* list5 = create_list_from_array(arr5, 2);
    printf("Before: ");
    print_list(list5);
    list5 = isort(list5);
    printf("After:  ");
    print_list(list5);
    assert(is_sorted(list5) && "List should be sorted");
    assert(list_matches_array(list5, expected5, 2) && "List order incorrect");
    printf("✓ Test 5 passed\n\n");
    free_list(list5);
    
    // Test 6: Negative numbers
    printf("Test 6: Negative numbers [-5, 3, -2, 0]\n");
    int arr6[] = {-5, 3, -2, 0};
    int expected6[] = {-5, -2, 0, 3};
    node* list6 = create_list_from_array(arr6, 4);
    printf("Before: ");
    print_list(list6);
    list6 = isort(list6);
    printf("After:  ");
    print_list(list6);
    assert(is_sorted(list6) && "List should be sorted");
    assert(list_matches_array(list6, expected6, 4) && "List order incorrect");
    printf("✓ Test 6 passed\n\n");
    free_list(list6);
    
    printf("🎉 All tests passed!\n");
    return 0;
}
