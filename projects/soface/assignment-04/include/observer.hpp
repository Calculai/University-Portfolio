#ifndef OBSERVER_HPP
#define OBSERVER_HPP

enum AnimalEvent
{
    MonkeyFed,
    TigerScratched,
    FishTeethCleaned,
};

class Observer
{

public:
    virtual ~Observer(){};

    virtual void update(AnimalEvent event) = 0;
};

#endif // OBSERVER_HPP