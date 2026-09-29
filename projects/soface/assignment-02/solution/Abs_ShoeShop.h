#ifndef SHOESHOP_H
#define SHOESHOP_H

#include "Abs_Shop.h"

typedef struct {
	Shop base;  // inherit from Shop (must be first member so we can cast between Shop* and ShoeShop*)
	int* shelf;
	int size;
} ShoeShop;

// constructor equivalent - create and initialize a ShoeShop
ShoeShop* ShoeShop_create(int size);

#endif
