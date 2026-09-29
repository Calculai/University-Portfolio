#pragma once

#include "unit.hpp"
#include "subject.hpp"

// TODO add more relevant information to struct
struct UnitEvent
{
    std::string message;
};

class GameUnit : public Unit, public Subject<UnitEvent>
{
};