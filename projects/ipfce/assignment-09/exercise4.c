/*
 * Exercise 4: dfs search using stack
 */

#include "include/exercise4.h"

/* 
 * Stack operations from Assignment 7
 * These are the ONLY operations you can use on stacks
 */

/* Initialize an empty stack */
void initialize(stack *s) {
    s->head = NULL;
}

/* Push a tree node onto the stack */
void push_btree_node(stack *s, struct tree_node *tn) {
    ll_tree_node* new_node = (ll_tree_node*)malloc(sizeof(ll_tree_node));
    if (new_node == NULL) {
        fprintf(stderr, "malloc failed to create btree_node\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = tn;
    new_node->next = s->head;
    s->head = new_node;
}

/* Pop an element from the stack */
struct tree_node *pop_btree_node(stack *s) {
    if (empty(s))
    {
        return NULL;
    }
    ll_tree_node* temp = s->head;
    tree_node* popped_node = temp->data;
    s->head = s->head->next;
    free(temp);
    return popped_node;
}

/* Check if stack is empty */
bool empty(stack *s) {
    return s->head == NULL;
}

/* Check if stack is full (always false for linked list) */
bool full(stack *s) {
    return false;
}

/* 
* Write a function that performs a depth-first search (DFS) for integer x
* in the integer array a of length n using a stack.
* Return the sequence of visited nodes
*/

/*
I wanted to use the stack from my previous assignment like it says
in the pdf but the initialization function in here is 
incompatible and the data types are not the same so I opted to not
do that. 

The method still relies on the stack method and solves the problem 
like presented in class it just avoid the mess of having to adapt
my stack library and instead makes a linked list that pushes to
end to make my output.
*/

void append_node(node **head, int value) {
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        fprintf(stderr, "malloc failed in append_node\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

struct node *dfs_search(struct tree_node *root) {
    if (!root) return NULL;

    stack s;
    initialize(&s); // stack of tree nodes
    struct node *visited = NULL;

    push_btree_node(&s, root);

    while (!empty(&s)) {
        tree_node *curr = pop_btree_node(&s);
        if (!curr) continue;

        append_node(&visited, curr->data);

        // Push right first so left is visited first
        if (curr->right) push_btree_node(&s, curr->right);
        if (curr->left)  push_btree_node(&s, curr->left);
    }

    return visited;
}