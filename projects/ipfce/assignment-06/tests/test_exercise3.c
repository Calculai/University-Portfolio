#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

// Include the student's implementation
int size(node *l);
int largest(node *l);
void add(node *head, int x);

int main()
{
    node *list = malloc(sizeof(node));
    list->next = NULL; // create first empty element

    // Test size function
    assert(size(list) == 0); // Empty list
    add(list, 1);
    add(list, 3);
    add(list, 2);
    assert(size(list) == 3); // List has 3 elements

    // Test largest function
    assert(largest(list) == 3); // Largest value is 3
    add(list, 5);
    assert(largest(list) == 5); // Largest value is now 5

    // Test with negative values
    node *negList = malloc(sizeof(node));
    negList->next = NULL;
    add(negList, -1);
    add(negList, -3);
    add(negList, -2);
    assert(largest(negList) == -1); // Largest value is -1

    printf("Exercise 3 tests passed\n");
    return 0;
}
