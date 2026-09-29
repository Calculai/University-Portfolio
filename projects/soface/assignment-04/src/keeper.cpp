#include "keeper.hpp"
#include "monkey.hpp"
#include "tiger.hpp"
#include "fish.hpp"

// Implement this (visitor part)
void Keeper::visit(Monkey &monkey)
{
    monkey.feed_banana();
    // the pdf says that when the keeper visits it needs to call the function of the class
}

// Implement this (visitor part)
void Keeper::visit(Tiger &tiger)
{
    tiger.scratch_back();
    // see above in monkey
}

// Implement this (visitor part)
void Keeper::visit(Fish &fish)
{
    fish.clean_teeth();
    // see above in monkey
}