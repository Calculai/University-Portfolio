#include "Org_ShoeShop.h"
#include <stdlib.h>

ShoeShop* ShoeShop_create(int size) {
	// allocated memory for called amount of shelves
	ShoeShop* shop = (ShoeShop*) malloc(sizeof(ShoeShop));
	
	// initialize shelves to 0
	shop->shelf = (int*)calloc(size, sizeof(int));
	
	// set the size of the shoe shop
	shop->size = size;

	// return shop pointer to caller
	return shop;
}

void ShoeShop_destroy(ShoeShop* shop) {
	// free allocated memory for shelves and shop struct
	if (shop != NULL) {
		free(shop->shelf);
		free(shop);
	}
	// important to start with shelf since shop is our only access to shelf
}

void ShoeShop_add_items(ShoeShop* shop, int row, int num) {
	shop->shelf[row] += num;
	/* add item amount to existing amount on shelf (are these 
	types of comments relevant? seems pretty self-explanatory 
	but nothing else to comment on for this function) */
}

int ShoeShop_in_stock(ShoeShop* shop, int row) {
	return shop->shelf[row] > 0;
	/* return true if shelf has items, false if shelf is empty
	not formatted as bool since the provided functions didn't 
	use bool return type, but the logic is the same */
}

int ShoeShop_count_items(ShoeShop* shop) {
	// uses stored size to loop through all shelves and add them together
	int tot = 0;
	for (int k = 0; k < shop->size; k++) {
		tot += shop->shelf[k];
	}
	return tot;
}

bool ShoeShop_clear(ShoeShop* shop, int row) {
	// check if shelf had items before clearing
	// then clear shelf and return whether it had items
	bool rem = shop->shelf[row] > 0;
	shop->shelf[row] = 0;
	return rem;
}
