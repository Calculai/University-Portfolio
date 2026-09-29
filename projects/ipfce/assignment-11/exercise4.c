/* exercise4.c
 * Implementations for Exercise 4: convert the recursive sum
 * into (a) a tail-recursive version and (b) an iterative version using a while loop.
 */

#include "include/exercise4.h"
#include <assert.h>

static int sum_tail_recusive_helper(int, int);

int sum_recursive(int n)
{
    assert(1 <= n);
    if (1 < n)
    {
        return n + sum_recursive(n - 1);
    }
    else
    {
        return 1;
    }
}

/* Tail-recursive version. */
int sum_tail_recursive(int n)
{
    // TODO: Implement the function in a tail-recursive manner
	assert(1 <= n);
	return sum_tail_recusive_helper(n, 0);
}

static int sum_tail_recusive_helper(int n, int acc) {
    // acc accumulates the values across recursions and n counts down

    if (n == 0)
    {
        return acc;
    }

    return sum_tail_recusive_helper(n-1, acc+n);
}

/* Iterative version using a while loop. */
int sum_iterative(int n)
{
    // TODO: Implement the function iteratively using a while loop
    int sum=0;
    while (n > 0)
    {
        sum += n;
        n--;
    }

	return sum;
}

