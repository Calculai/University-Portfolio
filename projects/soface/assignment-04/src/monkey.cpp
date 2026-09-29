#include "monkey.hpp"

// Implement this (visitor pattern)
void Monkey::accept(Visitor &visitor)
{
    visitor.visit(*this); // as said in the pdf we simply make the visitor use its function on this object
}

// Implement this (Observer part)
void Monkey::feed_banana()
{
    notify(AnimalEvent::MonkeyFed); // use the inherinted function from Monkey -> Animal -> Subject
}