#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Declaration of student's function
bool is_jolly_jumper(const int seq[], int size);

int main() {
    // Test case 1: classic jolly
    int seq1[] = {1, 4, 2, 3};
    assert(is_jolly_jumper(seq1, 4) == true);

    // Test case 2: not jolly
    int seq2[] = {1, 4, 2, -1, 6};
    assert(is_jolly_jumper(seq2, 5) == false);

    // Test case 3: single element (trivial jolly)
    int seq3[] = {42};
    assert(is_jolly_jumper(seq3, 1) == true);

    // Test case 4: negative differences
    int seq4[] = {5, 1, 4, 2};
    assert(is_jolly_jumper(seq4, 4) == false);

    // Test case 5: larger sequence
    int seq5[] = {11, 7, 4, 2, 1, 6};
    assert(is_jolly_jumper(seq5, 6) == true);

    printf("Exercise 7 tests passed\n");
    return 0;
}
