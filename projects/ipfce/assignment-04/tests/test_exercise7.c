#include <stdio.h>
#include <assert.h>
#include <math.h>

// Include the student's implementation
double average(int list[], int n); // Declaration only

int main()
{
    // Test case 1: Normal array
    int test1[] = {10, 20, 30};
    double result1 = average(test1, 3);
    assert(fabs(result1 - 20.0) < 0.001);

    // Test case 2: Single element
    int test2[] = {42};
    double result2 = average(test2, 1);
    assert(fabs(result2 - 100.0) < 0.001); 

    // Test case 3: Large numbers
    int test3[] = {1000, 2000, 3000, 4000};
    double result3 = average(test3, 4);
    assert(fabs(result3 - 2500.0) < 0.001);

    // Test case 3: Negative numbers
    int test4[] = {-1, -2, -3};
    double result4 = average(test4, 3);
    assert(fabs(result4 - (-2.0)) < 0.001);

    // Test case 4: Mixed positive and negative
    int test5[] = {-5, 5, -3, 3};
    double result5 = average(test5, 4);
    assert(fabs(result5 - 0.0) < 0.001);

    printf("Exercise 8 tests passed\n");
    return 0;
}
