#include <assert.h>

/*
 * Returns in rev_array the elements of list in reversed order
 * Pre: n>0, list[0...n-1] is defined
 */
void reverse(int list[], int rev_array[], int n)
{
    assert(n > 0);
    for (int i = 0; i < n; i++)
    {
        rev_array[i] = list[n-i-1];
    }
    
    return;
}