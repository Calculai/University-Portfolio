#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include\exercise4.h"

// struct node *dfs_search(struct tree_node *root);

int main(void)
{
    // --- Construct the example tree ---

    // Expected DFS (preorder, using stack): 4 → 7 → 28 → 77 → 23 → 86 → 3 → 9 → 98

    struct tree_node *root = malloc(sizeof(struct tree_node));
    root->data = 4;

    struct tree_node *n7 = malloc(sizeof(struct tree_node));
    struct tree_node *n28 = malloc(sizeof(struct tree_node));
    struct tree_node *n77 = malloc(sizeof(struct tree_node));
    struct tree_node *n23 = malloc(sizeof(struct tree_node));
    struct tree_node *n86 = malloc(sizeof(struct tree_node));
    struct tree_node *n3 = malloc(sizeof(struct tree_node));
    struct tree_node *n9 = malloc(sizeof(struct tree_node));
    struct tree_node *n98 = malloc(sizeof(struct tree_node));

    // Set data values
    n7->data = 7;
    n23->data = 23;
    n28->data = 28;
    n77->data = 77;
    n86->data = 86;
    n3->data = 3;
    n9->data = 9;
    n98->data = 98;

    // Link tree nodes
    root->left = n7;
    root->right = n98;
    n7->left = n28;
    n7->right = n86;
    n28->left = n77;
    n28->right = n23;
    n86->left = n3;
    n86->right = n9;
    n23->left = n23->right = NULL;
    n77->left = n77->right = NULL;
    n3->left = n3->right = NULL;
    n9->left = n9->right = NULL;
    n98->left = n98->right = NULL;

    // --- Run the DFS search ---
    struct node *visited = dfs_search(root);

    // --- Expected visitation order ---
    int expected[] = {4, 7, 28, 77, 23, 86, 3, 9, 98};
    int i = 0;

    // --- Verify sequence ---
    struct node *cur = visited;
    while (cur != NULL)
    {
        assert(cur->data == expected[i]);
        cur = cur->next;
        i++;
    }
    assert(i == 9); // should have visited exactly 9 nodes

    printf("Exercise 4 DFS test passed successfully!\n");
    return 0;
}
