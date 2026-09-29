#include <stdio.h>

int main (void){
    
    int n, m;
    printf("Enter two integers (n m): ");
    scanf("%d %d", &n, &m);
    int q = 0; // Quotient, count how many times m is subtracted from n
    int r = m; // Remainder, stores what is left after finding quotient
    int b = n;
    while (r >= b) {
    b *= 2;
    }
    while (b != n) {
        q *= 2;
        b /= 2;
        if (r >= b)
        {
            q += 1;
            r -= b;
        }
    }

    printf("\nThe quotient of %d divided by %d is: %d with a remainder of %d\n\n", n, m, q, r);
    
    return 0;
}
