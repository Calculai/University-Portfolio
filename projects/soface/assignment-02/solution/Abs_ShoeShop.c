#include "Abs_ShoeShop.h"
#include <stdlib.h>

// forward declarations of ShoeShop-specific functions
// all of them static because user is supposed to use 
// the shop struct and its function pointers
static void ShoeShop_add_items(Shop* self, int row, int num);
static int ShoeShop_in_stock(Shop* self, int row);
static int ShoeShop_count_items(Shop* self);
static bool ShoeShop_clear(Shop* self, int row);
static void ShoeShop_destroy(Shop* self);

// constructor equivalent 
ShoeShop* ShoeShop_create(int size) {
	// allocated memory for the whole struct, including the base Shop struct
	ShoeShop* shoe_shop = (ShoeShop*)malloc(sizeof(ShoeShop));
	// initialize shelves to 0
	shoe_shop->shelf = (int*)calloc(size, sizeof(int));
	// set the size of the shoe shop
	shoe_shop->size = size;
	
	// initialize function pointers in the base Shop struct
	shoe_shop->base.add_items = ShoeShop_add_items;
	shoe_shop->base.in_stock = ShoeShop_in_stock;
	shoe_shop->base.count_items = ShoeShop_count_items;
	shoe_shop->base.clear = ShoeShop_clear;
	shoe_shop->base.destroy = ShoeShop_destroy;
	/* 
	now when we call shop.add_items(Shop*, int, int) it will 
	call ShoeShop_add_items with the correct self pointer
	making it work without needingnto know it is a shoeshop
	*/

	return shoe_shop;
	// we return the shoe_shop struct pointer which includes our functions and relvant data
}

static void ShoeShop_add_items(Shop* self, int row, int num) {
	((ShoeShop*)self)->shelf[row] += num;
	/*
	notable the self pointer we pass around is of type Shop*
	so we need to case it to ShoeShop* to access shoe shop specific data
	this isn't an issue since we allocate the correct type in the create function
	so malloc will take care of the space for us 
	*/
}

static int ShoeShop_in_stock(Shop* self, int row) {
	return ((ShoeShop*)self)->shelf[row] > 0;
	// again returns true or false formatted as int
}

static int ShoeShop_count_items(Shop* self) {
	int tot = 0;
	for (int k = 0; k < ((ShoeShop*)self)->size; k++) {
		tot += ((ShoeShop*)self)->shelf[k];
	}
	// uses the size we set to loop through all shelves and add them together
	return tot;
}

static bool ShoeShop_clear(Shop* self, int row) {
	bool rem = ((ShoeShop*)self)->shelf[row] > 0;
	((ShoeShop*)self)->shelf[row] = 0;
	return rem; // return true if the item was cleared (i.e., was in stock before clearing)
}

static void ShoeShop_destroy(Shop* self) {
	if (((ShoeShop*)self) != NULL) {
		free(((ShoeShop*)self)->shelf);
		free(((ShoeShop*)self));
	}
	// we only allocated memory for the ShoeShop struct and its shelf, so free those (order matters)
}
