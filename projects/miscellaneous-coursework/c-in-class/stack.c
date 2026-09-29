#include "stack.h"
#include <assert.h>

/* Create an empty stack */
void initialize(stack *s)
{
    s->head = NULL;

    /* post-condition: stack is empty */
    assert(empty(s));
}

/* Insert item x at the top of stack s */
void push(double x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {printf("Error: memory allocation failed\n"); return;}

    temp->data = x;
    temp->next = s->head;
    s->head = temp;

    /* post-condition: x is added to top of stack */
    assert(s->head->data == x);
    return;
}

/* Return (and remove) the top item of stack s */
double pop(stack *s)
{
    /* pre-condition: stack must not be empty */
    if (empty(s)){printf("No items to pop, stack is empty"); return 0;}
    assert(!empty(s));

    node *temp = s->head;
    double out = s->head->data;
    s->head = s->head->next;
    free(temp);

    /* post-condition: top item is removed and returned */
    if (!empty(s)){assert(s->head->data != out);}
    return out; 
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    return false; // Technically can be full if all memory is claimed but that is an unlikely case
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    return (s->head == NULL);
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */

    if (empty(s)){printf("No items to print, stack is empty"); return;}

    node *temp = s->head;
    int i = 1;
    while (temp != NULL)
    {
        printf("(%d) %.4lf | ",i ,temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
    /* post-condition: prints all items in the stack */ //Untestable outside visual confirmation
    return;
}

void destroy_stack(stack *s){
    while (s->head != NULL){pop(s);} return;
}
