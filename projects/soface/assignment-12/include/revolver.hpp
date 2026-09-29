#pragma once
#include "weapon.hpp"
class Revolver : public Weapon
{
public:
    Revolver();

private:
    virtual Projectile &get_projectile() override;

    Projectile projectile;
};