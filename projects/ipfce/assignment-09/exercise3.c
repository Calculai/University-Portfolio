#include <stdbool.h>

// write a recursive function that searches for integer x in the integer array a of length n
bool search(const int a[], int n, int x) {
    if (n==0)
    {
        return false;
    }
    
    if (*a == x)
    {
        return true;
    }
    
    return search(a+1,n-1,x);
}