#include <iostream>
#include "battle_monitor.hpp"


void BattleMonitor::do_update(void *event)
{
    // cast the downcasted void pointer to a UnitEvent pointer 
    // so that we can access the message and print it out
    UnitEvent *e = static_cast<UnitEvent *>(event);
    std::cout << e->message << std::endl;
    // also add the message to the messages vector so that we can later check it in tests
    this->messages.push_back(e->message);
}