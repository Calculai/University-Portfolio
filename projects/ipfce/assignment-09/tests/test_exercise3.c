#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Student function prototype
bool search(const int a[], int n, int x);

int main(void)
{
    int arr[] = {3, 7, 2, 9, 5};
    int empty[] = {};

    // Test 1: element present
    assert(search(arr, 5, 7) == true);

    // Test 2: element not present
    assert(search(arr, 5, 8) == false);

    // Test 3: last element
    assert(search(arr, 5, 5) == true);

    // Test 4: first element
    assert(search(arr, 5, 3) == true);

    // Test 5: empty array
    assert(search(empty, 0, 1) == false);

    printf("Exercise 3 tests passed successfully!\n");
    return 0;
}
