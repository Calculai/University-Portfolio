#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void){
	// call with NULL (should handle empty list)
	print_list(NULL);

	// build 1 -> 2 -> 3
	node *n3 = new_node(3, NULL);
	node *n2 = new_node(2, n3);
	node *n1 = new_node(1, n2);

	// call on a small list; tests are lightweight: success means it runs without crashing
	print_list(n1);

	free(n3);
	free(n2);
	free(n1);

	printf("Exercise 1 tests passed successfully!\n");
	return 0;
}

