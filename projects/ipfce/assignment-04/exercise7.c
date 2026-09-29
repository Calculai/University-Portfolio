#include <assert.h>

/*
 * Returns the average of an array
 * Pre: n>0, list[0...n-1] is defined
 */
double average(int list[], int n)
{
    assert(n > 0);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += list[i];
    }
    double avg = sum/n;

    return avg;
}