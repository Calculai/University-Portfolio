#ifndef EXERCISE4_H
#define EXERCISE4_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h> // added to use intptr_t

// Define the tree node structure
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

// ll_tree_ node is a linked list node that holds a tree_node pointer as data
typedef struct ll_tree_node {
    tree_node *data;           // changed from int to intptr_t to safely store pointers
    struct ll_tree_node *next;
} ll_tree_node;

// the stack holds a pointer to the top ll_tree_node
typedef struct stack{
    ll_tree_node *head;
} stack;

// linked list node to store visited nodes (data only)
typedef struct node {
    int data;
    struct node *next;
} node;

/* Stack operations */
void initialize(stack *s);
void push_btree_node(stack *s, struct tree_node *tn);
struct tree_node *pop_btree_node(stack *s);
bool empty(stack *s);
bool full(stack *s);


/* 
 * Write a function that performs a depth-first search (DFS) for integer x
 * in the integer array a of length n using a stack.
 * Return the sequence of visited nodes
 */
 struct node *dfs_search(struct tree_node *root);

#endif /* EXERCISE4_H */