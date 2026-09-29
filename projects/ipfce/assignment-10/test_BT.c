#include "binary_tree.h"
#include <stdio.h>
#include <assert.h>


int main(void) {
    tree_node *root = NULL;

    FILE *file = fopen("results.txt", "w"); // open file for writing
    if (!file) {
        perror("fopen failed");
        return 1;
    }

    // Test insert
    fprintf(file, "Test 1 insert: ");
    root = insert(10, root);
    root = insert(5, root);
    root = insert(15, root);
    root = insert(3, root);
    root = insert(7, root);
    root = insert(12, root);

    assert(contains(10, root) == true);
    assert(contains(5, root) == true);
    assert(contains(15, root) == true);
    assert(contains(3, root) == true);
    assert(contains(7, root) == true);
    assert(contains(12, root) == true);
    assert(contains(999, root) == false);
    fprintf(file, "passed!\n\n");

    // Test remove
    fprintf(file, "Test 2 remove: ");
    root = remove_node(3, root); // remove leaf
    assert(contains(3, root) == false);
    root = remove_node(5, root); // remove node with one child
    assert(contains(5, root) == false);
    root = remove_node(10, root); // remove node with two children
    assert(contains(10, root) == false);
    fprintf(file, "passed!\n\n");

    // Test empty and full
    fprintf(file, "Test 3 empty and full: ");   
    assert(empty(root) == false);
    assert(full(root) == false);
    root = remove_node(7, root);
    root = remove_node(12, root);
    root = remove_node(15, root);
    assert(empty(root) == true);
    assert(full(root) == false);
    fprintf(file, "passed!\n\n");

    fprintf(file, "All tests passed successfully!");

    fclose(file); // close the file
    return 0;
}
