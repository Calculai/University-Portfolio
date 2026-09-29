
#include <stdio.h>
#include <assert.h>

// Function prototype
int GCD(int a, int b);

int main() {
    // Test cases: {a, b, expected GCD}
    int tests[][3] = {
        {15, 10, 5},
        {12, 8, 4},
        {81, 27, 27},
        {42, 56, 14},
        {17, 13, 1},   // relatively prime
        {100, 25, 25}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < num_tests; i++) {
        int a = tests[i][0];
        int b = tests[i][1];
        int expected = tests[i][2];
        int result = GCD(a, b);

        if (result == expected) {
            printf("Test %d passed: GCD(%d, %d) = %d PASS\n", i+1, a, b, result);
            passed++;
        } else {
            printf("Test %d FAILED: GCD(%d, %d) = %d FAIl (expected %d)\n", i+1, a, b, result, expected);
        }
    }

    printf("\n%d/%d tests passed.\n", passed, num_tests);

    return 0;
}


int GCD(int a, int b){
    assert(a>0 && b>0);

    if (a == b)
    {
        return a;
    }
    
    if (a>b) {return GCD(a-b,b);} else if (a<b) {return GCD(a,b-a);}
}