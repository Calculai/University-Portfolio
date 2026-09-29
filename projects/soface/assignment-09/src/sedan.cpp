#include "sedan.hpp"
#include <array>

static const std::array<double, 7> gear_ratios = {-1, 1, 2, 3, 4, 5, 6};

Sedan::Sedan() : current_gear(0)
{
    // initialize the sedan and set geat to be gear index 0 (reverse)
}

void Sedan::shift_up()
{
    // shift gear indexer up one
    current_gear =+ 1;
}

void Sedan::shift_down()
{
    // shift gear indexer down one
    current_gear =- 1;
}

double Sedan::get_torque(double engine_rpm, double throttle)
{
    /*
    since we were permitted to choose a simple model I will spare 
    the work of trying to make an advanced model
    */

    (void)engine_rpm; 
    // discard engine_rpm since our model doesn't use it

    const double max_torque_nm = 960.0;
    return max_torque_nm * throttle;
}

double Sedan::get_weight()
{
    /* 
    since there is no variable in the class for it
    and ideally it shouldn't change during the drive
    we select a weight and just return it

    (the car class using get_weight makes sense because if we instead had
    a tesla we could just make a tesla class and override the get weight)
    */
    return 1000;
}

double Sedan::get_wheel_radius()
{
    /*
    again this should be constant so we just pick the relevant value and 
    return it
    */
    return 0.3;
}

double Sedan::get_current_gear_ratio()
{
    /*
    We have a vector of all our gearratios and a variable that keep track of
    our current gear so we make it return the equivalent ratio
    */
    return gear_ratios.at(current_gear);
}