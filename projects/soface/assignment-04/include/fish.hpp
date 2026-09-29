#ifndef FISH_HPP
#define FISH_HPP

#include "visitor.hpp"
#include "animal.hpp"

class Fish : public Animal
{
public:
    virtual void accept(Visitor &visitor) override;
    void clean_teeth();
};

#endif // FISH_HPP