#include "sofarch1lis.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr), size(0) {}

Queue::~Queue() {
    // delete all nodes
    // important to avoid memory leaks
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    size = 0;
}

bool Queue::is_empty() const {
    return head == nullptr;
}

bool Queue::is_full() const {
    // only here to make the interface compatible with software that checks for full
    // and because the assignment requested it
    return false;
}

void Queue::enqueue(int value) {
    Node* n = new Node(value);
    if (tail) {
        tail->next = n;
    } else {
        head = n;
    }
    tail = n;
    ++size;
}

int Queue::dequeue() {
    if (is_empty()) {
        std::cout << "Queue is empty, cannot dequeue." << std::endl;
        return -1;
    }
    Node* n = head;
    int val = n->value;
    head = head->next;
    if (!head) tail = nullptr;
    delete n;
    --size;
    return val;
}

