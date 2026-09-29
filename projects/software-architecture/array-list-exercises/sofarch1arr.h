#ifndef SOFARCH1ARR_H
#define SOFARCH1ARR_H   

class Queue {
private:
    int cap;       // capacity of the queue
    int front;     // front element
    int rear;      // rear element
    int size;      // current number of elements
    int* arr;      // array to store queue elements

    /*
    all these members are private to prevent user from messing up
    the queue like we talked about in class
    */

public:
    // Default constructor: will use preset capacity of 50
    Queue();
    // Use constructor with an integer parameter to set capacity to specified value
    Queue(int cap);

    /*
    Check if the queue is empty or full, public because caller may need to know 
    and there is no harm in calling it since it just reads doesn't modify, but 
    intended for internal use.
    */
    bool is_full() const;
    bool is_empty() const;

    // basic queue operations
    void enqueue(int value);
    int dequeue();

    // destructor
    ~Queue();
};

#endif