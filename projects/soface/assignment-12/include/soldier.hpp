#pragma once
#include "game_unit.hpp"

class Weapon;

class Soldier : public GameUnit
{
public:
    Soldier(std::string name, Weapon *weapon);

    virtual void shootAt(Unit &) override;

    virtual void takeHit(Projectile &) override;

private:
    Weapon *weapon;
    std::string name;
};
