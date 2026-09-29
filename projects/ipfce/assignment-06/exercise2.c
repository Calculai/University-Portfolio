#include <assert.h>

// Write a function `int max(int* numbers, int size)` that, 
// given an array of numbers (and its size), finds the maximum value in the array. 
int max(int* numbers, int size)
{
    assert(size > 0); // Precondition
    int max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    
    return max; // TODO: implement this function
}
