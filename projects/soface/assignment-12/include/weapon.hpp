#include "unit.hpp"
#include "projectile.hpp"

class Projectile;

class Weapon
{
public:
    void shootAt(Unit &u)
    {
        u.takeHit(get_projectile());
    }

private:
    virtual Projectile &get_projectile() = 0;
};
