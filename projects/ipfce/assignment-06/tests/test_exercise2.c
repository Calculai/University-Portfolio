#include <stdio.h>
#include <assert.h>

// Include the student's implementation
int max(int* numbers, int size);

int main() {
    int numbers1[] = {1, 3, 2};
    int numbers2[] = {-5, -1, -10};
    int numbers3[] = {42};

    // Test max function
    assert(max(numbers1, 3) == 3); // Maximum is 3
    assert(max(numbers2, 3) == -1); // Maximum is -1
    assert(max(numbers3, 1) == 42); // Maximum is 42

    printf("Exercise 2 tests passed\n");
    return 0;
}
