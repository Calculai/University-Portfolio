#include <stdio.h>
#include <assert.h>

int largestPrime(int n);

int main(void){
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int result = largestPrime(n);
    printf("The largest prime number less than or equal to %d is: %d\n", n, result);
    return 0;
}

int largestPrime(int n){
int i, j, prime;
assert(n > 0);
if (n <= 3) {return n;}
if (n == 4) {return 3;}

for (i = 2; i <= n ; i++)
{
    j = 2;
    while (j <= i/j && i%j != 0) {
        j++;
        if (j > i/j) {
            prime = i;
        }
    }
}

return prime;
}

