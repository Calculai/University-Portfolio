#include "feeder.hpp"

// Implement this:
void Feeder::filter_op(std::vector<Monkey> &monkeys)
{
    for (Monkey &monkey : monkeys) // range based for loop to feed each monkey
    {
        monkey.hunger_level -= 1; // lower hunger for each monkey
    }
}