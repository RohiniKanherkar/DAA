#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Check if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Access the front (oldest) element
    std::cout << "Front element: " << q.front() << std::endl;

    // Access the back (newest) element
    std::cout << "Back element: " << q.back() << std::endl;

    // Pop the front element
    q.pop();

    // Get the size of the queue
    std::cout << "Queue size: " << q.size() << std::endl;

    return 0;
}
