#include <iostream>
#include "sofarch1lis.h"

int main() {
    Queue q;

    std::cout << "Initially empty? " << (q.is_empty() ? "yes" : "no") << "\n";

    std::cout << "Enqueue: 10, 20, 30\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "After enqueue, empty? " << (q.is_empty() ? "yes" : "no") << "\n";
    std::cout << "is_full() (should be false for linked list): " << (q.is_full() ? "true" : "false") << "\n";

    std::cout << "Dequeue -> " << q.dequeue() << "\n";
    std::cout << "Dequeue -> " << q.dequeue() << "\n";
    std::cout << "Dequeue -> " << q.dequeue() << "\n";

    std::cout << "Attempt dequeue on empty (should print message and return -1) -> " << q.dequeue() << "\n";

    std::cout << "Finally empty? " << (q.is_empty() ? "yes" : "no") << "\n";

    return 0;
}
