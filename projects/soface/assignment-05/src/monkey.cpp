#include "monkey.hpp"

Monkey::Monkey(std::string name, int hunger_level) : hunger_level(hunger_level), name(name) {}

std::ostream &operator<<(std::ostream &os, const Monkey &m)
{
    os << '(' << m.name << ", " << m.hunger_level << ")";
    return os;
}