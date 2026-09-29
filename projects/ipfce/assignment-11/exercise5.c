/* exercise5.c
 * Tail-recursive Fibonacci implementation for Exercise 5.
 */

#include "include/exercise5.h"
#include <assert.h>

int fibhelper(int, int, int);

int fib(int n)
{
    // TODO: Implement the function using tail recursion
	assert(n >= 1);

	return fibhelper(n, 0, 1);
}

int fibhelper(int n, int psum1, int psum2){

	if (n == 1)
	{
		return psum2;
	}
	

	return fibhelper(n-1, psum2, psum2+psum1);
}


