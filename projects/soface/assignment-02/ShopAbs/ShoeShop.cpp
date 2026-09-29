#include "ShoeShop.h"

ShoeShop::ShoeShop(int size) {
	this->shelf = new int[size];
	this->size = size;
}

ShoeShop::~ShoeShop() {
	delete this->shelf;
}

void ShoeShop::add_items(int row, int num) {
	this->shelf[row] += num;
}

int ShoeShop::in_stock(int row) {
	return this->shelf[row] > 0;
}

int ShoeShop::count_items() {
	int tot = 0;
	for (int k = 0; k < size; k++) {
		tot += this->shelf[k];
	}
	return tot;
}

bool ShoeShop::clear(int row) {
	bool rem = shelf[row] > 0;
	this->shelf[row] = 0;
	return rem;
}

