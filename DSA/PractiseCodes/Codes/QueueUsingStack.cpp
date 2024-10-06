#include <iostream>
#include <stack>
using namespace std;

// Template class for the queue
template <class T>
class Queue {
private:
    stack<T> stack1; // Stack for enqueue operations
    stack<T> stack2; // Stack for dequeue operations

public:
    // Enqueue operation
    void enqueue(const T& el) {
        stack1.push(el); // Push the element onto the first stack
    }

    // Dequeue operation
    void dequeue() {
        if (stack2.empty()) {
            // If the second stack is empty, transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // If stack2 is still empty after transferring, throw an error
        if (stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        stack2.pop(); // Pop the front element from the second stack
    }

    // Get the front element of the queue
    T front() {
        if (stack2.empty()) {
            // If the second stack is empty, transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // If stack2 is still empty after transferring, throw an error
        if (stack2.empty()) {
            throw out_of_range("Queue is empty");
        }

        return stack2.top(); // Return the top element of the second stack
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return stack1.empty() && stack2.empty(); // Queue is empty if both stacks are empty
    }

    // Get the size of the queue
    size_t size() const {
        return stack1.size() + stack2.size(); // Size is the sum of both stacks' sizes
    }
};

// Main function to test the Queue class
int main() {
    Queue<int> queue; // Create a queue of integers

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.front() << endl; // Output: 1

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl; // Output: 2

    queue.dequeue();
    queue.dequeue();

    if (queue.isEmpty()) {
        cout << "Queue is now empty." << endl; // Output: Queue is now empty.
    }

    return 0;
}
