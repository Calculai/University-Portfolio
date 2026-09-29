#include "ShoeShop.h"

int main() {
	ShoeShop* shop = new ShoeShop(2);
	shop->add_items(0, 2);
	shop->add_items(1, 3);
	int tot = shop->count_items();
	if (tot > 0) {
		shop->clear(0);
		shop->clear(1);
	}
}