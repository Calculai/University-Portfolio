#pragma once
#include "observer.hpp"

#include <vector>

template <class E>
class Subject
{
public:
    void attach(Observer<E> &observer)
    {
        observers.emplace_back(&observer);
    }
    void detach()
    {
        observers.erase(observers.begin(), observers.end(), observers);
    }

    void notify(E event)
    {
        for (auto o : observers)
            o->update(event);
    }

private:
    std::vector<Observer<E> *> observers;
};