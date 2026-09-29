#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void){
    // empty list
    node *empty = NULL;
    assert(sum_squares(empty) == 0);

    // 1 -> 2 -> 3 : 1 + 4 + 9 = 14
    node *n3 = new_node(3, NULL);
    node *n2 = new_node(2, n3);
    node *n1 = new_node(1, n2);
    assert(sum_squares(n1) == 1 + 4 + 9);

    // 5 -> -2 : 25 + 4 = 29
    node *m2 = new_node(-2, NULL);
    node *m1 = new_node(5, m2);
    assert(sum_squares(m1) == 25 + 4);

    free(n3); free(n2); free(n1);
    free(m2); free(m1);

    printf("Exercise 3 tests passed successfully!\n");
    return 0;
}
