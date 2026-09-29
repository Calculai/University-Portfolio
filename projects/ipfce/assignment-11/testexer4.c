#include "exercise4.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    printf("Testing Exercise 4: sum_tail_recursive, sum_iterative\n\n");
   
    assert(sum_iterative(6)== 21);
    assert(sum_iterative(7)== 28);
    assert(sum_iterative(10)== 55);
    assert(sum_iterative(50)==1275);
    assert(sum_iterative(500)==125250);
    assert(sum_iterative(2500)==3126250);

    assert(sum_tail_recursive(6) == 21);
    assert(sum_tail_recursive(7) == 28);
    assert(sum_tail_recursive(10) == 55);
    assert(sum_tail_recursive(50) == 1275);
    assert(sum_tail_recursive(500) == 125250);
    assert(sum_tail_recursive(2500) == 3126250);

    printf("All tests passed for exercise4.\n");
    return 0;
}