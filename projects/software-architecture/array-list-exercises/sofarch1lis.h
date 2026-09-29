#ifndef SOFARCH1LIS_H
#define SOFARCH1LIS_H

// Queue using linked list 

class Queue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    }; 
    // linked list node

    Node* head; // points to front of queue
    Node* tail; // points to tail of queue
        int size;   // number of elements

     /*
    all these members are private to prevent user from messing up
    the queue like we talked about in class
    */

public:
    Queue();
    ~Queue();

    bool is_empty() const;
    // internal check but public because caller may need to know and it does no harm to call it since it just reads doesn't modify

    bool is_full() const;
    // always returns false but is compatible with software that checks for full

    // queue operations
    void enqueue(int value);
    int dequeue();
};

#endif // SOFARCH1LIS_H
