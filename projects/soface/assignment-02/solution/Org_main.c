#include "Org_ShoeShop.h"
#include <stdio.h>

int main() {
	// I added print statements to make it clearer what is happening
	// when testing the program
	printf("Creating a shoe shop with 2 shelves...\n"); 
	ShoeShop* shop = ShoeShop_create(2);
	
	printf("Adding 2 items to shelf 0\n"); 
	ShoeShop_add_items(shop, 0, 2);
	printf("Adding 3 items to shelf 1\n");  
	ShoeShop_add_items(shop, 1, 3);
	
	int tot = ShoeShop_count_items(shop);
	printf("Total items in shop: %d\n", tot); 
	
	if (tot > 0) {
		printf("Clearing shelf 0 - in stock: %d\n", ShoeShop_clear(shop, 0)); 
		printf("Clearing shelf 1 - in stock: %d\n", ShoeShop_clear(shop, 1));  
	}
	
	int tot_after = ShoeShop_count_items(shop);
	printf("Total items after clearing: %d\n", tot_after); 
	
	printf("Destroying shop...\n");  
	ShoeShop_destroy(shop);
	printf("Done!\n");  
	
	return 0;
}
