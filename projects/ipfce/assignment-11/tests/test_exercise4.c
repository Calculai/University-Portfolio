#include <stdio.h>
#include <assert.h>
#include "../include/exercise4.h"

int main(void) {
    printf("Testing Exercise 4: sum_recursive vs sum_tail_recursive vs sum_iterative\n\n");

    int tests[] = {1, 2, 3, 5, 10, 50, 100, 1000};
    int ntests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < ntests; ++i) {
        int n = tests[i];
        printf("Test n=%d\n", n);
        int r = sum_recursive(n);
        int t = sum_tail_recursive(n);
        int it = sum_iterative(n);

        printf("  sum_recursive(%d) = %d\n", n, r);
        printf("  sum_tail_recursive(%d) = %d\n", n, t);
        printf("  sum_iterative(%d) = %d\n", n, it);

        assert(r == t && "tail-recursive result must equal original recursive result");
        assert(t == it && "iterative result must equal tail-recursive result");

        printf("  ✓ all implementations agree for n=%d\n\n", n);
    }

    printf("All tests passed for exercise4 implementations.\n");
    return 0;
}
