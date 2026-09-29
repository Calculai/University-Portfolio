#include <stdio.h>
#include <assert.h>

// Student function prototype
int sum(const int a[], int n);

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, -10, 10, -10};
    int arr3[] = {};
    int arr4[] = {42};

    // Test 1: regular case
    assert(sum(arr1, 5) == 15); // 1+2+3+4+5 = 15

    // Test 2: includes positive and negative
    assert(sum(arr2, 4) == 0); // cancels out

    // Test 3: empty array
    assert(sum(arr3, 0) == 0); // base case

    // Test 4: single element
    assert(sum(arr4, 1) == 42);

    printf("Exercise 2 tests passed successfully!\n");
    return 0;
}
