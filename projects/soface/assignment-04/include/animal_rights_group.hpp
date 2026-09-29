#ifndef ANIMAL_RIGHTS_GROUP_HPP
#define ANIMAL_RIGHTS_GROUP_HPP

#include "observer.hpp"

class AnimalRightsGroup : public Observer
{

public:
    virtual ~AnimalRightsGroup(){};

    AnimalRightsGroup(int n_monkeys, int n_tigers, int n_fish);

    virtual void update(AnimalEvent event) override;

    bool animals_ok();

private:
    int n_monkeys;
    int n_tigers;
    int n_fish;
    int n_monkeys_fed;
    int n_tigers_scratched;
    int n_fish_teeth_brushed;
};

#endif // ANIMAL_RIGHTS_GROUP_HPP