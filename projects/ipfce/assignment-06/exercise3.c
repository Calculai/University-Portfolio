#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "list.h"

void add(node *head, int x)
{
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: A new node containing x is added to the end of the list

  assert(head != NULL);
  node *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  } // p points to the last element

  node *element = malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;
}

void printout(node *l)
{
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  node *p = l->next;
  while (p != NULL)
  {
    printf("%d, ", p->data);
  }
  printf("\n");
}

// Implement a function with the following signature: `int size(node *l)`. 
// It has the same precondition as `add` and returns the number of elements in the list. 
// E.g. if `size(list)` was printed out at the first `// show list here`) in main, the result would be 3.
int size(node *l)
{
  assert(l != NULL);
  int counter = 0;
  node *current = l;
  while (current->next != NULL)
  {
    current = current->next;
    counter++;
  }
  
  return counter; // TODO: implement this function
}

int largest(node *l)
{
  // pre:  head point to the first, empty element.
  //       The last element's next is NULL.
  // post: Returns the largest value of the list
  assert(l != NULL);

  node *current = l->next;
  int max = current->data;
  while (current->next != NULL)
  {
    current = current->next;

    if (current->data > max)
    {
      max = current->data;
    }
  }

  return max; // TODO: implement this function
}

// NOTE: Uncomment main to test your implementation
// int main()
// {
//   node *list = malloc(sizeof(node));
//   list->next = NULL; // create first empty element
//   add(list, 1);
//   add(list, 3);
//   add(list, 2);
//   // Show list here
//   add(list, 2);
//   // Show list here

//   return 0;
// }