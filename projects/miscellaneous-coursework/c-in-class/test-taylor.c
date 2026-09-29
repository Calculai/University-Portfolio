#include "taylor_sine.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    double x;
    int n;

    // Input
    printf("Enter x (in radians): ");
    if (scanf("%lf", &x) != 1) {return 1;}
    printf("Enter number of terms n (<170): ");
    if (scanf("%d", &n) != 1) {return x;}
    assert(n < 170);

    // Calculate Taylor sine approximation
    double sine_approx = taylor_sine(x, n);
    printf("Taylor sine approximation: %.10lf\n", sine_approx);

    // Calculate actual sine value
    double sine_actual = sin(x);
    printf("Actual sine value: %.10lf\n", sine_actual);

    // Calculate and print error
    double error = fabs(sine_approx - sine_actual);
    printf("Error: %.10lf\n", error);

    return 0;
}