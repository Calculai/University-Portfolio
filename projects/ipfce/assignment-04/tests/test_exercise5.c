#include <stdio.h>
#include <assert.h>

// Include the student's implementation
int longest_seq(int list[], int n); // Declaration only

int main() {
    // Test case 1: Normal array with zeros
    int test1[] = {1, 0, 0, 0, 1, 0, 0, 1};
    int result1 = longest_seq(test1, 8);
    assert(result1 == 1); // Longest sequence starts at index 1
    
    // Test case 2: No zeros
    int test2[] = {1, 2, 3, 4, 5};
    int result2 = longest_seq(test2, 5);
    assert(result2 == -1);
    
    // Test case 3: Single zero
    int test3[] = {1, 0, 2};
    int result3 = longest_seq(test3, 3);
    assert(result3 == 1);
    
    // Test case 4: All zeros
    int test4[] = {0, 0, 0, 0};
    int result4 = longest_seq(test4, 4);
    assert(result4 == 0);
    
    // Test case 5: Multiple sequences of same length
    int test5[] = {0, 0, 1, 0, 0, 1};
    int result5 = longest_seq(test5, 6);
    assert(result5 == 0); // First occurrence
    
    printf("Exercise 5 tests passed\n");
    return 0;
}
