#ifndef MONKEY_HPP
#define MONKEY_HPP
#include <string>
#include <iostream>

class Monkey
{
public:
    Monkey(std::string name, int hunger_level);

    bool operator==(const Monkey &other) const
    {
        return this->hunger_level == other.hunger_level && this->name == other.name;
    }

    bool operator!=(const Monkey &other) const
    {
        return !operator==(other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Monkey &m);

    int hunger_level;
    std::string name;
};

#endif // MONKEY_HPP