#include <stdio.h>
#include <assert.h>
#include "../include/exercise3.h"

int main(void) {
    printf("Testing Exercise 3: sum_first_n_odds\n\n");

    // Test 1: n = 1
    printf("Test 1: n = 1\n");
    assert(sum_first_n_odds(1) == 1L);
    printf("✓ n=1 -> 1\n\n");

    // Test 2: n = 2
    printf("Test 2: n = 2\n");
    assert(sum_first_n_odds(2) == 4L);
    printf("✓ n=2 -> 4\n\n");

    // Test 3: n = 5
    printf("Test 3: n = 5\n");
    assert(sum_first_n_odds(5) == 25L);
    printf("✓ n=5 -> 25\n\n");

    // Test 4: n = 10
    printf("Test 4: n = 10\n");
    assert(sum_first_n_odds(10) == 100L);
    printf("✓ n=10 -> 100\n\n");

    // Test 5: n = 0 (edge case)
    printf("Test 5: n = 0 (edge case)\n");
    assert(sum_first_n_odds(0) == 0L);
    printf("✓ n=0 -> 0\n\n");

    // Test 6: negative n (should return 0 per header contract)
    printf("Test 6: n = -3 (negative)\n");
    assert(sum_first_n_odds(-3) == 0L);
    printf("✓ n=-3 -> 0\n\n");

    // Test 7: larger value (sanity)
    printf("Test 7: n = 1000 (sanity)\n");
    long val = sum_first_n_odds(1000);
    long expected = 1000L * 1000L;
    assert(val == expected);
    printf("✓ n=1000 -> %ld\n\n", val);

    printf("All tests in test_exercise3.c passed.\n");
    return 0;
}
