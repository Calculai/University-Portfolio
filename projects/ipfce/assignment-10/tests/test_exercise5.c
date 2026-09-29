#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include "binary_tree.h" // for dfs_search declaration

int main() {
    tree_node *root = NULL;

    // empty tree
    assert(empty(root) == true);

    // insert root
    root = insert(10, root);
    assert(root != NULL);
    assert(empty(root) == false);
    assert(contains(10, root) == true);

    // insert left and right children
    root = insert(5, root);
    root = insert(15, root);
    assert(contains(5, root) == true);
    assert(contains(15, root) == true);

    // add a left-grandchild
    root = insert(3, root);
    assert(contains(3, root) == true);
    assert(full(root) == false);

    // remove the leaf 3
    root = remove_node(3, root);
    assert(contains(3, root) == false);

    // removing a non-existent element should not remove others
    root = remove_node(999, root);
    assert(contains(10, root) == true);
    assert(contains(5, root) == true);
    assert(contains(15, root) == true);

    // remove a leaf (5)
    root = remove_node(5, root);
    assert(contains(5, root) == false);
    assert(contains(10, root) == true);
    assert(contains(15, root) == true);

    printf("Exercise 5 tests passed successfully!\n");
    return 0;
}