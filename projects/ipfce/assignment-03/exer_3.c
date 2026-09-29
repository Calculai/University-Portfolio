
#include <stdio.h>
#include <assert.h>

int numOfFib(int a, int b);

int main(void) {
    int a, b;
    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);
    int result = numOfFib(a, b);
    if (a>b) { // Makes it so it is a range between the two numbers no matter the order
        int temp = a;
        a = b; 
        b = temp;
    }
    printf("Number of Fibonacci numbers in the range [%d, %d]: %d\n", a, b, result);
    return 0;
}

int numOfFib(int a, int b) {
    // Precondition a and b are integers

    if (a<=0 && b<=0) {return 0;} // If both numbers are zero or below no fib numbers inbetween
    if (a==b) {return 0;} // If both numbers are equal no fib numbers inbetween

    // Make a be the smaller number
    if (a>b) {
        int temp = a;
        a = b; 
        b = temp;
        printf("Order of numbers swapped so range is [%d, %d}\n",a,b);
    }

    // Initialize the first two Fibonacci numbers and count
    int fib1 = 1, fib2 = 2, count = 2;

    // Edge case for a > 3 or a=2
    if (a > 3) {count = count -2;}
    if (a == 2) {count = count -1;}
   
    // Can be negative range no problem

    while (1==1){
        int nextfib = fib1 + fib2;
        if (nextfib > b) {break;}
        if (nextfib >= a && nextfib <= b) {count++;}
        fib1 = fib2;
        fib2 = nextfib;
        assert(fib2 >= fib1); // Invariant
    }

    assert(count >= 0); // Postcondition
    return count;
}






