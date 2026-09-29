#ifndef SHOP_H
#define SHOP_H

#include <stdbool.h>

typedef struct Shop {
	// function pointers for virtual methods

	// add items to a specific row
	void (*add_items)(struct Shop* self, int row, int num);
	// check if items are in stock at a specific row
	int (*in_stock)(struct Shop* self, int row);
	// count total items in the shop
	int (*count_items)(struct Shop* self);
	// clear items from a specific row, returns true if row had items
	bool (*clear)(struct Shop* self, int row);
	// destructor equivalent - free memory
	void (*destroy)(struct Shop* self);

	/* when shop is created the struct can be called with 
	the function pointers to perform functions independant 
	of the specifics of the shoe shop implementation */
} Shop;

#endif
