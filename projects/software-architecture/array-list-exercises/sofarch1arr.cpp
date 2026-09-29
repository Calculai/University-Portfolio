#include <iostream>
#include <cstring>
#include "sofarch1arr.h"

// implementation is a circular queue, like we learned in first semester to avoid shifting elements

// preset capacity used by default constructor
static const int precap = 50;

// Default constructor: uses preset capacity
Queue::Queue() {
    cap = precap;
    front = 0;
    rear = -1;
    size = 0;
    arr = new int[cap];
}

// Constructor with initial capacity: makes its size depend on user specification
Queue::Queue(int capacity) {
    if (capacity <= 0) {
        capacity = precap;
        std::cout << "Invalid capacity specified. Using preset capacity of " << precap << '.' << std::endl;
    }
    // if invalid capacity use preset and notify user

    // initialization
    this->cap = capacity;
    front = 0;
    rear = -1;
    size = 0;
    arr = new int[cap];
}

// Destructor
Queue::~Queue() {
    delete[] arr;
}

bool Queue::is_full() const {
    return size == cap;
}

bool Queue::is_empty() const {
    return size == 0;
}

void Queue::enqueue(int value) {
    if (is_full()) {
        std::cout << "Queue is full, cannot enqueue." << std::endl;
        return;
    }
    // if full do nothing and notify user

    // expand rear while using modulo to wrap around
    rear = (rear + 1) % cap;
    arr[rear] = value;
    ++size;
}

int Queue::dequeue() {
    if (is_empty()) {
        std::cout << "Queue is empty, cannot dequeue." << std::endl;
        return -1;
    }
    // if user tries to dequeue from empty queue, notify and return sentinel value

    // move front while using modulo to wrap around
    int val = arr[front];
    front = (front + 1) % cap;
    --size;
    return val;
}