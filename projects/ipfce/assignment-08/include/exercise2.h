/*
 * Header file for Exercise 2
 * Assignment 8 - IPFCE 2025
 * 
 * Insertion sort for singly linked list
 */

#ifndef _EXERCISE2_H_
#define _EXERCISE2_H_

#include <stdio.h>
#include <stdlib.h>

/* Node structure for singly linked list */
typedef struct node {
    int data;
    struct node *next;
} node;

/* 
 * Sort a singly linked list in-place using insertion sort
 * The list should be sorted from smallest to largest
 * No new nodes should be allocated - only pointers should be changed
 * Returns pointer to the new head of the sorted list
 */
node* isort(node* list);

/* Helper function to create a node */
node* create_node(int data);

/* Helper function to free the list */
void free_list(node* list);

/* Helper function to print the list (for testing) */
void print_list(node* list);

#endif
