#include <stdio.h>
#include <assert.h>

int doublesum(int n);

int main(void){
    int n = 2;
    int result = doublesum(n);
    printf("\nThe double sum for %d is: %d\n", n, result);

    n = 3;
    result = doublesum(n);
    printf("\nThe double sum for %d is: %d\n\n", n, result);

    n = 6;
    result = doublesum(n);
    printf("The double sum for %d is: %d\n\n", n, result);

    n = 0;
    result = doublesum(n);
    printf("The double sum for %d is: %d\n\n", n, result);

    n = 8;
    result = doublesum(n);
    printf("The double sum for %d is: %d\n\n", n, result);

    n = 2147483647; 
    result = doublesum(n);
    printf("The double sum for %d is: %d\n\n", n, result);

    return 0;
}

int doublesum(int n){
    int sum = 0;
    int expected = 0;
    assert(n >= 0); // Precondition, n must be a non-negative integer

    for (int m = 1; m < n+1; m++)
    {
        for (int k = 1; k < m+1; k++)
        {
            sum += 2*k-1;
        }
        
    }


    expected = (n*(n+1)*(2*n+1))/6;
    assert(sum == expected); // Post condition, the sum is equal to the value from the given formula
    
    return sum;
}

