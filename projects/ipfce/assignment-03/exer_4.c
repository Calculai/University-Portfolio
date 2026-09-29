#include <stdio.h>
#include <assert.h>

int main(void){
    int n, m, r;

    printf("Enter two integers (n m): ");
    scanf("%d %d", &n, &m);

    if (m > n)
    {
        r = 0;
        printf("\n%d is not divisble by %d therefore no remainder\n\n", n, m);
        return 0;
    }
    

    r = n;
    while (r >= m) // smaller numerator than denominator means no iterations
    {
        r -= m;
        assert(r >= 0); // invariant
    }


    printf("\nThe remainder of %d divided by %d is: %d\n\n", n, m, r);
    
    return 0;
}
