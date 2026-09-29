#include "soldier.hpp"
#include "weapon.hpp"

#include <sstream>

Soldier::Soldier(std::string name, Weapon *weapon) : weapon(weapon), name(name)
{
}

void Soldier::shootAt(Unit &unit)
{
    // uses the weapon associated with the class (which is made to be associated in construction)
    // this weapons shootat function is then used which works by having the unit shot at
    // use the takehit function
	this->weapon->shootAt(unit);
}

void Soldier::takeHit(Projectile &projectile)
{
    // takes the hits from the shootat function it just announces damage taken (a more advance version would have hp)
    // the projectile is gotten through get_projectile() which is an abstract class that we in this case
    // implement in the revolver class
	std::stringstream ss;
	ss << this->name << " got hit for " << projectile.damage << " damage";
	this->notify(UnitEvent{ss.str()});
}