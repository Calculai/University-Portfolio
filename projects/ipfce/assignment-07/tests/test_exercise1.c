/*
 * Test file for Exercise 1 - Taylor Sine Function
 * Assignment 7 - IPFCE 2025
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../include/taylor_sine.h"

#define EPSILON 0.0001

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    printf("Testing Exercise 1: Taylor Sine Function\n");
    
    // Test 1: sin(0) should be 0
    double result1 = taylor_sine(0.0, 10);
    assert(fabs(result1 - 0.0) < EPSILON && "Test 1 failed: sin(0) should be 0");
    printf("Test 1 passed: sin(0) = 0\n");
    
    // Test 2: sin(π/6) ≈ 0.5 (30 degrees)
    double result2 = taylor_sine(M_PI / 6.0, 10);
    assert(fabs(result2 - 0.5) < EPSILON && "Test 2 failed: sin(π/6) should be ≈ 0.5");
    printf("Test 2 passed: sin(π/6) ≈ 0.5\n");
    
    // Test 3: sin(π/4) ≈ 0.7071 (45 degrees)
    double result3 = taylor_sine(M_PI / 4.0, 10);
    assert(fabs(result3 - sin(M_PI / 4.0)) < 0.001 && "Test 3 failed: sin(π/4) should be ≈ 0.7071");
    printf("Test 3 passed: sin(π/4) ≈ 0.7071\n");
    
    // Test 4: sin(π/2) = 1 (90 degrees)
    double result4 = taylor_sine(M_PI / 2.0, 15);
    assert(fabs(result4 - 1.0) < 0.001 && "Test 4 failed: sin(π/2) should be ≈ 1.0");
    printf("Test 4 passed: sin(π/2) = 1\n");
    
    // Test 5: sin(π) ≈ 0 (180 degrees)
    double result5 = taylor_sine(M_PI, 15);
    assert(fabs(result5 - 0.0) < 0.001 && "Test 5 failed: sin(π) should be ≈ 0");
    printf("Test 5 passed: sin(π) ≈ 0\n");
    
    // Test 6: sin(-π/6) ≈ -0.5 (negative angle)
    double result6 = taylor_sine(-M_PI / 6.0, 10);
    assert(fabs(result6 - (-0.5)) < EPSILON && "Test 6 failed: sin(-π/6) should be ≈ -0.5");
    printf("Test 6 passed: sin(-π/6) ≈ -0.5\n");
    
    // Test 7: Accuracy with more terms (sin(1.0))
    double result7 = taylor_sine(1.0, 20);
    assert(fabs(result7 - sin(1.0)) < 0.0001 && "Test 7 failed: sin(1.0) should match math.h sin");
    printf("Test 7 passed: sin(1.0) with 20 terms\n");
    
    // Test 8: Small value (sin(0.1))
    double result8 = taylor_sine(0.1, 5);
    assert(fabs(result8 - sin(0.1)) < EPSILON && "Test 8 failed: sin(0.1) should be ≈ 0.0998");
    printf("Test 8 passed: sin(0.1) ≈ 0.0998\n");
    
    printf("\nAll Exercise 1 tests passed!\n");
    return 0;
}
