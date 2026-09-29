#include "binary_tree.h"
#include <stdio.h>

static tree_node* small(tree_node* root);

//insert returns the root of the modified tree
tree_node* insert(int data, tree_node* root){

    if (root == NULL) 
    {
        root = malloc(sizeof(tree_node));
        if (root == NULL) {
        fprintf(stderr, "malloc failed in insert\n");
        exit(EXIT_FAILURE);
        }

        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    } 
    // base case

    if (data > root->data) {
        root->right = insert(data, root->right);
    } else if (data < root->data) {
        root->left = insert(data, root->left);
    }
    // return the original root, not the child
    return root;
}

//remove returns the root of the modified tree
tree_node* remove_node(int data, tree_node* root){
        
    if (root == NULL) {
        return NULL;
    } // base case

    // found
    if (data == root->data) {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        
        if (root->right == NULL)
        {
            tree_node *temp = root->left;
            free(root);
            return temp;
        }
        
        if (root->left == NULL)
        {
            tree_node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            tree_node *min = small(root->right);
            root->data = min->data;
            root->right = remove_node(root->data, root->right);
            
        }
        return root; 
    }

    if (data > root->data) root->right = remove_node(data, root->right);
    if (data < root->data) root->left = remove_node(data, root->left);

    return root;
}

//contains returns true if data is in the tree, false otherwise
bool contains(int data, tree_node* root){
    
    if (root == NULL) {return false;} // base case

    // found
    if (data == root->data) {return true;}
    // look right
    if (data > root->data) {return contains(data,root->right);}
    // look left
    if (data < root->data) {return contains(data,root->left);}
    

    return false; // base case
}

//full 
bool full(tree_node* root){
    return false;   
}

//empty
bool empty(tree_node* root){
    if (root == NULL)
    {
        return true;
    }
    
    return false;
}   

static tree_node* small(tree_node* root) {  
    if (root->left == NULL) {return root;}
    return small(root->left);
}