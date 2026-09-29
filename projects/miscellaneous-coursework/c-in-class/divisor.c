#include <stdio.h>
#include <assert.h>

int main(void){
    int n, m, r, d, D[50], count, case1;

    printf("\nEnter two integers (n m) and decimal count: ");
    scanf("%d %d %d", &n, &m, &d);
    d = d + 1; // One extra for the integer part
    assert(m != 0); // Precondition
    if (d <= 0) {d = 5;} // No negative decimal places
    if (d > 50) {d = 50;} // Max 50 decimal places
    if (n < 0 && m < 0) {
        n = -n;
        m = -m;
    }
    if (n < 0 && m > 0) {
        n = -n;
        case1 = 1;
    }
    if (m < 0 && n > 0)
    {
        m = -m;
        case1 = 1;
    }
    
    r = n;
    for (int i = 0; i < d; i++) {
        count = 0;
        while (r >= m)
    {
        r -= m;
        count++;
    }
    D[i] = count;
    r = r * 10; }

    printf("\n%d divided by %d is:", n, m);
    if (case1 == 1) {printf(" -");} else {printf(" ");}
    printf("%d,", D[0]);
    for (int i = 1; i < d; i++) {
    printf("%d", D[i]); }
    printf("\n\n");
    
    return 0;
}



