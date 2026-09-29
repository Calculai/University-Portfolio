#include <stdio.h>

int main(void){
    double x;
    double *x_array;
    int n;
    double S;

    printf("Enter the number for precision: ");    
    scanf("%d", &n);

    x_array = (double *)malloc(n * sizeof(double));
    if (x_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the number to find the square root of: ");    
    scanf("%lf", &S);
    printf("Insert first guess: ");
    scanf("%lf", &x);

    for (int i = 0; i < n; i++)
    {
        x_array[i] = x;
        x = (x + S/x) / 2;
        printf("Iteration %d: Approximation = %lf\n", i + 1, x);
    }
    
    free(x_array);
    return 0;
}