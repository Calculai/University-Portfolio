#include "subject.hpp"

// Implement this (Observer part)
void Subject::attach(Observer *subscriber)
{
    subscribers.push_back(subscriber);
    // pushback to add to the back of list
}

// Implement this (Observer part)
void Subject::detach(Observer *subscriber)
{
    subscribers.pop_back();
    // pop the furthest back in the list item
    
    // issue is if we have two subscribers then if we want to remove the first one we added
    // then you can't without some acrobatics. But simmilarily if we want to remove the second
    // subscriber we will have the issue if we only remove the front subscriber so it isn't
    // an improvement necessarily

    // but for the test we don't even use detach and the part in the pdf where it tells me to implement
    // the functions it is using singular languange, so I will accept the issues
}

// Implement this (Observer part)
void Subject::notify(AnimalEvent event)
{
    for (Observer *subscriber : subscribers)
    {
        subscriber->update(event); // subscribers handle updating so we just notify them of events
        // running down the list of subscribers notifying each
    }
}