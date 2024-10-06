#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* previous = nullptr; // Previous node starts as null
    Node* current = head; // Start with the head of the list
    Node* next = nullptr; // Next node starts as null

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = previous; // Reverse the current node's pointer
        previous = current; // Move previous one step forward
        current = next; // Move current one step forward
    }
    head = previous; // Update head to the new first node
}

// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the reverse function
int main() {
    // Create list L: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Clean up the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
