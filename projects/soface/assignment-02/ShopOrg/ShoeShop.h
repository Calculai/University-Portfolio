#ifndef SHOESHOP_H
#define SHOESHOP_H

class ShoeShop {
private:
	int* shelf;
	int size;
public:
	ShoeShop(int);
	~ShoeShop();
	void add_items(int, int);
	int in_stock(int);
	int count_items();
	bool clear(int);
};

#endif