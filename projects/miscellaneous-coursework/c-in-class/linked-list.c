#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
   struct node *next;
} node;

void add(node *head, int val);
void printout(node *head);

int main(void){

    node *head = NULL;

    add(head,8);
    
    printout(head);

    return 0;
}


void add(node **head, int val){
   struct node *current = head;

    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = (node *) malloc(sizeof(node));
    current -> next -> x = val;
}

void printout(node *head){
    struct node *current = head;

    while(current != NULL){
        printf("%d",current -> x);
        current = current -> next;
    }
}