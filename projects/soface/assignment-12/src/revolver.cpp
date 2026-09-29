#include "revolver.hpp"

Revolver::Revolver() : projectile(1)
{
    // simple implementation just have the constructor intialize the projectile with a damage of 1
}

Projectile &Revolver::get_projectile()
{
    return this->projectile;
}