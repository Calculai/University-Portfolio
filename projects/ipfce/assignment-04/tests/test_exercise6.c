#include <stdio.h>
#include <assert.h>
#include <string.h>

// Include the student's implementation
void count_1_to_20(int a[100][150], int count[20]); // Declaration only

int main() {
    // Test case: Small example
    int test_array[100][150];
    int count[20];
    
    // Initialize array with zeros
    memset(test_array, 0, sizeof(test_array));
    
    // Set some test values
    test_array[0][0] = 1;
    test_array[0][1] = 1;
    test_array[0][2] = 2;
    test_array[1][0] = 20;
    test_array[1][1] = 15;
    
    count_1_to_20(test_array, count);
    
    // Check results
    assert(count[0] == 2);  // Two 1's
    assert(count[1] == 1);  // One 2
    assert(count[14] == 1); // One 15
    assert(count[19] == 1); // One 20
    assert(count[2] == 0);  // No 3's
    
    printf("Exercise 6 tests passed\n");
    return 0;
}
