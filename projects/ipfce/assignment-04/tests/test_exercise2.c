#include <stdio.h>
#include <assert.h>

// Include the student's implementation
int get_min(int list[], int n); // Declaration only

int main() {
    // Test case 1: Normal array
    int test1[] = {5, 2, 8, 1, 9};
    int result1 = get_min(test1, 5);
    assert(result1 == 1);
    
    // Test case 2: Single element
    int test2[] = {42};
    int result2 = get_min(test2, 1);
    assert(result2 == 42);
    
    // Test case 3: All same elements
    int test3[] = {7, 7, 7, 7};
    int result3 = get_min(test3, 4);
    assert(result3 == 7);
    
    // Test case 4: Negative numbers
    int test4[] = {-1, -5, -2, -10};
    int result4 = get_min(test4, 4);
    assert(result4 == -10);
    
    printf("Exercise 2 tests passed\n");
    return 0;
}
