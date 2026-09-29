#include <stdio.h>
#include <assert.h>

typedef struct {
    double num;
    char op;
} node;

int main(void) {
    node equation[100];
    double n;
    char ch;
    int i = 0;

    // First number
    if (scanf("%lf", &n) != 1) {return 1;}
    equation[i].num = n;
    equation[i].op = 0;  // no operator yet
    i++;

    double result = n;   // initialize running total

    while (1) {
        if (scanf(" %c", &ch) != 1) break;  // operator
        if (ch == '.') {
            break;  // end of input
        }

        if (scanf("%lf", &n) != 1) break;  // next number

        equation[i].num = n;
        equation[i].op = ch;
        i++;

        // apply operator immediately
        if (ch == '+') {
            result += n;
        } else if (ch == '-') {
            result -= n;
        } else if (ch == '*') {
            result *= n;
        } else if (ch == '/') {
            assert(n != 0.0);
            result /= n;
        }

        printf(" %.2lf\n", result);
    }

    // Print final total
    printf("Final total: %.2lf\n", result);

    // Print all numbers and operators
    printf("Equation: ");
    for (int j = 0; j < i; j++) {
        if (j > 0) {
            printf(" %c ", equation[j].op);
        }
        printf("%.2lf", equation[j].num);
    }
    printf(" = %.2lf\n", result);

    return 0;
}