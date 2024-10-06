#include <iostream>
#include <queue>
using namespace std;

// Template class for the queue
template <class T>
class Queue {
private:
    queue<T> q; // Standard library queue to hold the elements

public:
    void enqueue(T el) {
        q.push(el); // Add element to the back of the queue
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop(); // Remove the front element from the queue
        }
    }

    T front() const {
        if (!q.empty()) {
            return q.front(); // Return the front element
        }
        throw out_of_range("Queue is empty"); // Handle empty queue access
    }

    bool isEmpty() const {
        return q.empty(); // Check if the queue is empty
    }

    size_t size() const {
        return q.size(); // Get the size of the queue
    }
};

// Template class for the stack using the queue
template <class T>
class StackQ {
private:
    Queue<T> pool; // Queue to hold the stack elements

public:
    void push(T el) {
        // Enqueue the new element
        pool.enqueue(el);

        // Move all the elements behind the newly added element to maintain LIFO order
        for (size_t i = 0; i < pool.size() - 1; ++i) {
            T frontElement = pool.front();
            pool.dequeue(); // Remove front element from the queue
            pool.enqueue(frontElement); // Re-enqueue it to the back
        }
    }

    void pop() {
        if (!pool.isEmpty()) {
            pool.dequeue(); // Remove the front element, which is the top of the stack
        } else {
            cout << "Stack is empty!" << endl; // Handle empty stack
        }
    }

    T top() const {
        if (!pool.isEmpty()) {
            return pool.front(); // Return the front element, which is the top of the stack
        }
        throw out_of_range("Stack is empty"); // Handle empty stack access
    }

    bool isEmpty() const {
        return pool.isEmpty(); // Check if the stack is empty
    }

    size_t size() const {
        return pool.size(); // Get the size of the stack
    }
};

// Main function to test the StackQ class
int main() {
    StackQ<int> stack; // Create a stack of integers

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl; // Output: 3

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Output: 2

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is now empty." << endl; // Output: Stack is now empty.
    }

    return 0;
}
