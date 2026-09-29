/* exercise4.h
 * Prototypes for Exercise 4 - convert recursive sum(1..n) into
 * (a) tail-recursive version and (b) iterative version using while.
 */
#ifndef EXERCISE4_H
#define EXERCISE4_H

#include <stddef.h>

/*
 * sum_recursive - original recursive version (for reference)
 *   requires: n >= 1
 *   returns: 1 + 2 + ... + n
 */
int sum_recursive(int n);

/*
 * sum_tail_recursive - tail-recursive equivalent
 */
int sum_tail_recursive(int n);

/*
 * sum_iterative - iterative equivalent using a while loop
 */
int sum_iterative(int n);

#endif /* EXERCISE4_H */

