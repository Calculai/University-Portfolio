#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "taylor_sine.h"

#define M_PI 3.14159265358979323846

void comparesine(double x, int n);
void comparetable(int n);

int main(void) {

    comparetable(4);
    comparetable(10);
    comparetable(30);
    comparetable(100);

    /*
    So from the tests negative numbers seems to have no impact on
    the results accuracy, the only two values that are important
    are the x value and the amount of terms. This holds true for
    the mathematical model as well so is not an issue with 
    implementation

    This can also be seen in the test by examining the last test
    case because for the rest 40 is outside the range [-1000,1000] 
    but with 100 terms the precision of the model increases, but 
    the extra terms actually increase the value so far that it 
    reaches the limit of doubles. This is because it is more 
    unstable at far away values due to the polynomial nature of the 
    approximation.
    */ 

    return 0;
}


void comparesine(double x, int n) {

    // Calculate Taylor sine approximation
    double sine_approx = taylor_sine(x, n);

    // Calculate actual sine value
    double sine_actual = sin(x);
    
    // Calculate error
    double error = fabs(sine_approx - sine_actual);

    /*
    // Since sine is [-1,1] any value outside is a bad approximation,
    so to show reasonable error but avoid fomratting issue a range 
    was chosen.
    */
    if (sine_approx>1000 || sine_approx<-1000) 
    {
        printf("%12.4lf | Aproximation outside of range\n", 
           x);   
        return;
    }
    
   
    printf("%12.4lf | %14.8lf | %14.8lf | %14.8lf | %6d\n", 
           x, sine_approx, sine_actual, error, n);
    
    return;
}

void comparetable(int n){
    
    printf("\n%12s | %14s | %14s | %14s | %6s\n", 
           "X value", "Approx.", "Actual", "Error", "Terms");
    printf("-------------------------------------------------------------------------\n");

   
    comparesine(4.0, n);
    comparesine(M_PI, n);
    comparesine(-M_PI, n);
    comparesine(7.0, n);
    comparesine(-7.0, n);
    comparesine(3*M_PI, n);
    comparesine(34.0, n);
    comparesine(40, n);


    printf("\n");
}