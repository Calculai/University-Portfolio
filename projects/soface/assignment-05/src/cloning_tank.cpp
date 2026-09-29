#include "cloning_tank.hpp"

// Implement this:
void CloningTank::filter_op(std::vector<Monkey> &monkeys)
{
    const std::size_t original_size = monkeys.size();
    // index the original size of segment wished copied
	for (std::size_t i = 0; i < original_size; ++i)
	{
		monkeys.push_back(monkeys[i]); // push a copy of each element to the back of the vector
	}
}