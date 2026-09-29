#include "exercise3.h"

int main(void){

queue *q;

printf("\nTest 1: Queue empty on initialization");
initialize(q);
assert(empty(q));
printf(" |PASS| \n");

printf("\nTest 2: Enqueue then dequeue consitency");
int x = 4;
enqueue(q, x);
int y = dequeue(q);
assert(x == y);
printf(" |PASS| \n");

printf("\nTest 3: Enqueue enqueue then dequeue dequeue consitency");
int x0 = 6;
int x1 = 7;
enqueue(q, x0);
enqueue(q, x1);
int y0 = dequeue(q);
int y1 = dequeue(q);
assert(x0 == y0);
assert(x1 == y1);
printf(" |PASS| \n");

enqueue(q, x);
enqueue(q, x0);
enqueue(q, x1);

printf("\nTest 4: Print\n");
print_queue(q);
printf("\n");

while (!empty(q)) {dequeue(q);}

return 0;
}