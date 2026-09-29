/* exercise3.c
 * Recursive implementation that computes the sum of the first n positive odd numbers.
 * The mathematical identity is: (2*1-1) + (2*2-1) + ... + (2*n-1) = n^2
 */

#include "include/exercise3.h"


long sum_first_n_odds(int n)
{
    if(n<1) {return 0;}
    
    if (n == 1)
    {
        return 1;
    }

    return (2*n-1) + sum_first_n_odds(n-1);
}

