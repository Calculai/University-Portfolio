#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

//insert returns the root of the modified tree
tree_node* insert(int data, tree_node* root);

//remove returns the root of the modified tree
tree_node* remove_node(int data, tree_node* root);

//contains returns true if data is in the tree, false otherwise
bool contains(int data, tree_node* root);

//full 
bool full(tree_node* root);

//empty
bool empty(tree_node* root);

#endif // BINARY_TREE_H