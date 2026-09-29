// TODO implement composite pattern allowing multiple
// soldiers to be selected and treated as one
#pragma once;
#include <vector>
#include "unit.hpp"
#include "soldier.hpp"

class UnitSelection : public Unit
{
public:
    void addToSelection(Unit &unit);
    virtual void shootAt(Unit &unit);
    virtual void takeHit(Projectile &projectile);

private:
    std::vector<Unit *> selected;
};