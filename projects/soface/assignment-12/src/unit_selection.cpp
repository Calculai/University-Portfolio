#include "unit_selection.hpp"
#include "weapon.hpp"

void UnitSelection::addToSelection(Unit &unit)
{
    // add unit pointer to selected vector
    this->selected.push_back(&unit);
}


void UnitSelection::shootAt(Unit &unit)
{
    // loop through selected vector and have each unit use 
    // the shootAt function on the unit passed to the function
    for (auto &u : this->selected)
    {
        u->shootAt(unit);
    }
}

void UnitSelection::takeHit(Projectile &projectile)
{
    // loops through selected vector and use takehit for each 
    // unit in regard to the projectile passed
    for (auto &u : this->selected)
    {
        u->takeHit(projectile);
    }
}
