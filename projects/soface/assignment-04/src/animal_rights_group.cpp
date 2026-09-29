#include "animal_rights_group.hpp"

AnimalRightsGroup::AnimalRightsGroup(int n_monkeys, int n_tigers, int n_fish)
    : n_monkeys(n_monkeys), n_tigers(n_tigers), n_fish(n_fish),
      n_monkeys_fed(0), n_tigers_scratched(0), n_fish_teeth_brushed(0)
{
}

// Implement this (Observer part)
void AnimalRightsGroup::update(AnimalEvent event)
{
// discerns between different event via comparing to enum class inherinted from observer
// internally stores the amount of events triggered

    if (event == AnimalEvent::MonkeyFed) 
    {
        n_monkeys_fed++; 
    }
    else if (event == AnimalEvent::TigerScratched)
    {
        n_tigers_scratched++; 
    }
    else if (event == AnimalEvent::FishTeethCleaned)
    {
        n_fish_teeth_brushed++;
    }
}

bool AnimalRightsGroup::animals_ok()
{
    // do not modify
    return (n_monkeys == n_monkeys_fed && n_tigers == n_tigers_scratched && n_fish == n_fish_teeth_brushed);
}