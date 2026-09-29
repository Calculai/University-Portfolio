#include "Abs_ShoeShop.h"
#include <stdio.h>

int main() {
	// I added print statements to make it clearer what is happening
	// when testing the program
	printf("Creating a ShoeShop with polymorphism...\n");  
	ShoeShop* shoeshop = ShoeShop_create(2);
	
	printf("Casting ShoeShop to Shop pointer...\n");  
	Shop* shop = (Shop*)shoeshop;
	// since the first member of ShoeShop is Shop we can safely cast between the two types

	/*
	above is the intial work we need to do to set up polymorphism in C
	below the implementation works independant of the specific shop type
	we could create a shop called BookShop that also inherits from Shop
	and use the same code below to interact with it without changing anything

	this is the power of polymorphism
	*/

	
	printf("Adding 2 items to shelf 0 (via Shop pointer)\n"); 
	shop->add_items(shop, 0, 2);
	printf("Adding 3 items to shelf 1 (via Shop pointer)\n"); 
	shop->add_items(shop, 1, 3);
	
	int tot = shop->count_items(shop);
	printf("Total items in shop: %d\n", tot);  
	
	if (tot > 0) {
		printf("Clearing shelf 0 - in stock: %d\n", shop->clear(shop, 0));  
		printf("Clearing shelf 1 - in stock: %d\n", shop->clear(shop, 1));  
	}
	
	int tot_after = shop->count_items(shop);
	printf("Total items after clearing: %d\n", tot_after); 
	
	printf("Destroying shop...\n");  
	shop->destroy(shop);
	printf("Done!\n");  
	
	return 0;
}
