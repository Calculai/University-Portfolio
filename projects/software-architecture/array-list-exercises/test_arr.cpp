#include <iostream>
#include "sofarch1arr.h"

int main() {
    // test array-based queue
    Queue q(5); // fixed capacity of 5

    std::cout << "[array] Initially empty? " << (q.is_empty() ? "yes" : "no") << "\n";

    std::cout << "[array] Enqueue: 1,2,3,4,5\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << "[array] is_full(): " << (q.is_full() ? "true" : "false") << "\n";

    std::cout << "[array] Attempt enqueue when full (should notify)\n";
    q.enqueue(6); // should be rejected

    std::cout << "[array] Dequeue all:\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "[array] Dequeue -> " << q.dequeue() << "\n";
    }

    std::cout << "[array] Finally empty? " << (q.is_empty() ? "yes" : "no") << "\n";
    return 0;
}
