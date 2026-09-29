#pragma once
#include "observer.hpp"
#include "soldier.hpp"
class BattleMonitor : public Observer<UnitEvent>
{
public:
    std::vector<std::string> messages;

private:
    virtual void do_update(void *event);
};