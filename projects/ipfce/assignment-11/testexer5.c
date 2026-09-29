#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/exercise5.h"

int main(void){

    assert(fib(1) == 1);
    assert(fib(5) == 5);
    assert(fib(15) == 610);
    assert(fib(30) == 832040);
    assert(fib(46) == 1836311903);
    printf("test_exercise6: all assertions passed\n");

    return 0;
}
