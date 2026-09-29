#ifndef MONKEY_HPP
#define MONKEY_HPP

#include "visitor.hpp"
#include "animal.hpp"

class Monkey : public Animal
{
public:
    virtual void accept(Visitor &visitor) override;
    void feed_banana();
};

#endif // MONKEY_HPP