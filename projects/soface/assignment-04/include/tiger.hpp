#ifndef TIGER_HPP
#define TIGER_HPP

#include "visitor.hpp"
#include "animal.hpp"

class Tiger : public Animal
{
public:
    virtual void accept(Visitor &visitor) override;
    void scratch_back();
};

#endif // TIGER_HPP