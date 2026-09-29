#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

static int dbl(int x){ return x * 2; }
static int sq(int x){ return x * x; }

int main(void){
    // original list 1 -> 2 -> 3
    node *o3 = new_node(3, NULL);
    node *o2 = new_node(2, o3);
    node *o1 = new_node(1, o2);

    // map with dbl -> expect 2,4,6
    node *d = map(o1, dbl);
    assert(d != NULL);
    assert(d->data == 2);
    assert(d->next->data == 4);
    assert(d->next->next->data == 6);

    // map with sq -> expect 1,4,9
    node *s = map(o1, sq);
    assert(s != NULL);
    assert(s->data == 1);
    assert(s->next->data == 4);
    assert(s->next->next->data == 9);

    // original list should remain unchanged
    assert(o1->data == 1);
    assert(o1->next->data == 2);

    free_list(d);
    free_list(s);
    free_list(o1);

    printf("Exercise 4 tests passed successfully!\n");
    return 0;
}