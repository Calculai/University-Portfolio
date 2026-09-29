#pragma once

#include <string>

#include "subject.hpp"

class Projectile;

class Unit
{
public:
    virtual void shootAt(Unit &) = 0;

    virtual void takeHit(Projectile &) = 0;
};
