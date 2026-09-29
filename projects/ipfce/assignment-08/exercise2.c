/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "exercise2.h"

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */
node* isort(node* list) {
    
    if (list == NULL || list->next == NULL) {return list;}
    
    node* sorted = NULL;

    while (list != NULL) {
        node* curr = list;
        list = list->next;
        /*
        Insertion sorting needs to look through all previously sorted elements so
        with a traditionally linked list it gets very complicated so we are going
        to make a list called sorted where we have all the sorted elements

        In this implementation we will go from the bottom of the list which makes 
        sense since we make a sepparate sorted list. It also doesn't create new
        nodes so it is an in-place implementation
        */

        if (sorted == NULL || curr->data < sorted->data) { 
            curr->next = sorted; // Linkes node to sorted list
            sorted = curr;  // Sets head of sorted list
        } else {
            node* temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data) {temp = temp->next;} 
            // Goes through sorted list till the current node data is smaller than next node data

            curr->next = temp->next; // Inserts node and relinks list
            temp->next = curr;
        }
    }
    return sorted;
}

/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
