#include <stdio.h>
#include <time.h>

/* ---------- FACTORIAL ---------- */

int factorial_recursive(int n) {
    if (n <= 1)
        return 1;
    return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

/* ---------- FIBONACCI ---------- */

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/* ---------- MAIN TEST ---------- */

int main() {
    int n = 12;      // factorial test value
    int fib_n = 35;  // fibonacci test value (35–40 is good)
    int repeats = 100000;  // repeat many times to amplify timing difference
    clock_t start, end;
    double time_used;
    volatile int dummy; // prevent compiler optimization

    printf("=== FACTORIAL TEST ===\n");

    start = clock();
    for (int i = 0; i < repeats; i++) {
        dummy = factorial_recursive(n);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive factorial(%d) x%d = %f sec\n", n, repeats, time_used);

    start = clock();
    for (int i = 0; i < repeats; i++) {
        dummy = factorial_iterative(n);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative factorial(%d) x%d = %f sec\n\n", n, repeats, time_used);


    printf("=== FIBONACCI TEST ===\n");

    repeats = 100; // fewer repeats since recursive Fibonacci is slow
    start = clock();
    for (int i = 0; i < repeats; i++) {
        dummy = fibonacci_recursive(fib_n);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive fibonacci(%d) x%d = %f sec\n", fib_n, repeats, time_used);

    start = clock();
    for (int i = 0; i < repeats; i++) {
        dummy = fibonacci_iterative(fib_n);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative fibonacci(%d) x%d = %f sec\n", fib_n, repeats, time_used);

    return 0;
}
