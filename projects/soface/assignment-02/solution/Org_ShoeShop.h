#ifndef SHOESHOP_H
#define SHOESHOP_H

#include <stdbool.h>

typedef struct {
	int* shelf;
	int size;
} ShoeShop;

// Constructor equivalent - initialize the shop
ShoeShop* ShoeShop_create(int size);
/* 
Size is the number of shelves in the shoe shop, the size of the shop is limited
to the number of shelves chosen on construction.

Do not try to add items to a row that is out of bounds (i.e. row >= size) 
that will overwrite unallocated memory
*/

// destructor equivalent - free memory
void ShoeShop_destroy(ShoeShop* shop);

// add items to a specific row
void ShoeShop_add_items(ShoeShop* shop, int row, int num);

// check if items are in stock at a specific row
int ShoeShop_in_stock(ShoeShop* shop, int row);

// count total items in the shop
int ShoeShop_count_items(ShoeShop* shop);

// clear items from a specific row, returns true if row had items
bool ShoeShop_clear(ShoeShop* shop, int row);

#endif
