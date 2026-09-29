#include <assert.h>

/*
 * Returns the smallest of the first n values in list
 * Pre: n>0, list[0...n-1] is defined
 */
int get_min(int list[], int n)
{
    assert(n > 0);
    int min = list[0];
    for (int i = 1; i < n; i++) {
        if (list[i] < min) {
            min = list[i];
        }
    }
    //hey
    return min;
}