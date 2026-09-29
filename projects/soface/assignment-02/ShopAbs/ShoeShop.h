#ifndef SHOESHOP_H
#define SHOESHOP_H

#include "Shop.h"

class ShoeShop :public Shop {
private:
	int* shelf;
	int size;
public:
	ShoeShop(int);
	~ShoeShop() override;
	void add_items(int, int) override;
	int in_stock(int) override;
	int count_items() override;
	bool clear(int) override;
};

#endif