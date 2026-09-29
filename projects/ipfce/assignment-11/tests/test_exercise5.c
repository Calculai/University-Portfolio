/* tests/test_exercise5.c
 * Simple unit tests for exercise5: tail-recursive Fibonacci
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/exercise5.h"

int main(void)
{
    /* Basic known values */
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(7) == 13);
    assert(fib(10) == 55);

    assert(fib(20) == 6765);

    printf("test_exercise5: all assertions passed\n");
    return 0;
}
