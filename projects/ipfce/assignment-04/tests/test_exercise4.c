#include <stdio.h>
#include <assert.h>

// Include the student's implementation
void reverse(int list[], int rev_array[], int n); // Declaration only

int main() {
    // Test case 1: Normal array
    int test1[] = {1, 2, 3, 4, 5};
    int result1[5];
    reverse(test1, result1, 5);
    int expected1[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        assert(result1[i] == expected1[i]);
    }
    
    // Test case 2: Single element
    int test2[] = {42};
    int result2[1];
    reverse(test2, result2, 1);
    assert(result2[0] == 42);
    
    // Test case 3: Even number of elements
    int test3[] = {10, 20, 30, 40};
    int result3[4];
    reverse(test3, result3, 4);
    int expected3[] = {40, 30, 20, 10};
    for (int i = 0; i < 4; i++) {
        assert(result3[i] == expected3[i]);
    }
    
    printf("Exercise 4 tests passed\n");
    return 0;
}
