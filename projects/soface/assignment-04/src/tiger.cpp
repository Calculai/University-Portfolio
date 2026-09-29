#include "tiger.hpp"

// Implement this (visitor pattern)
void Tiger::accept(Visitor &visitor)
{
    visitor.visit(*this); // as said in the pdf we simply makes the visitor use its function on this object
}

// Implement this (Observer part)
void Tiger::scratch_back()
{
    notify(AnimalEvent::TigerScratched); // use the inherinted function from Tiger -> Animal -> Subject
}