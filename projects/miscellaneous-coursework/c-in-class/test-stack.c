#include <assert.h>
#include "stack.h"

int main(void){
    stack* s;
    int u, v;

    initialize(s);
    // Function checks for empty as post condition so not nessecery

    v = 3;
    push(v,s);
    u = pop(s);
    assert(v == u);
    printf("Test 1 succesful: Consistency through 1 push and pop\n");

    assert(empty(s));
    push(1,s);
    assert(!empty(s));
    push(2,s);
    assert(!empty(s));
    assert(!full(s));
    push(3,s);
    push(4,s);
    print(s);
    printf("Test 2 succesful: Print works\n");

    int v0 = 3;
    int v1 = 2;
    push(v0,s);
    push(v1,s);
    int u0 = pop(s);
    int u1 = pop(s);

    assert(v0 == u1);
    assert(v1 == u0);
    printf("Test 3 succesful: 2 push then pop\n");

    destroy_stack(s);
    assert(empty(s));
}