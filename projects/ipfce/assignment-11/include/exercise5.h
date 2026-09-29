/* exercise5.h
 * Prototype for tail-recursive Fibonacci (exercise 5)
 */
#ifndef EXERCISE5_H
#define EXERCISE5_H

#include <stddef.h>

/*
 * fib - compute the n-th Fibonacci number (1-based) using a tail-recursive helper
 * requires: n >= 1, i.e. the sequence 1, 1, 2, 3, 5, 8, ...
 * returns: Fibonacci number at position n
 */
int fib(int n);

#endif /* EXERCISE5_H */

