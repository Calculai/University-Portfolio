#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "observer.hpp"
#include <vector>
class Subject
{

private:
    std::vector<Observer *> subscribers;

public:
    void attach(Observer *subscriber);
    void detach(Observer *subscriber);

    void notify(AnimalEvent event);

    virtual ~Subject(){};
};

#endif // SUBJECT_HPP