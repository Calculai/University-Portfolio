#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "visitor.hpp"
#include "subject.hpp"

class Animal : public Subject
{
public:
    virtual void accept(Visitor &visitor) = 0;

    virtual ~Animal(){};
};

#endif // ANIMAL_HPP