#ifndef SHOP_H
#define SHOP_H

class Shop {
public:
	virtual ~Shop() {}
	virtual void add_items(int, int) = 0;
	virtual int in_stock(int) = 0;
	virtual int count_items() = 0;
	virtual bool clear(int) = 0;
};

#endif