#include "fish.hpp"

// Implement this (visitor pattern)
void Fish::accept(Visitor &visitor)
{
    visitor.visit(*this); // as said in the pdf we simply make the visitor use its function on this object
}

// Implement this (Observer part)
void Fish::clean_teeth()
{
    notify(AnimalEvent::FishTeethCleaned); // use the inherinted function from Fish -> Animal -> Subject
}