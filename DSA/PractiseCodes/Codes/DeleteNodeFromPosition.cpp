#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
    
    Node(char val) : data(val), next(nullptr) {}
};

// Function to delete nodes in `L1` based on positions in `L2`
void deleteNodesAtPositions(Node* head, int positions[], int size) {
    // Edge case: if the list is empty or positions are empty
    if (head == nullptr || size == 0) return;

    Node* current = head;
    Node* previous = nullptr;
    int currentIndex = 1; // 1-based index
    int posIndex = 0; // To track position in `L2`

    while (current != nullptr && posIndex < size) {
        if (currentIndex == positions[posIndex]) {
            // Delete the current node
            if (previous == nullptr) {
                head = current->next; // Update head if deleting the first node
            } else {
                previous->next = current->next;
            }

            Node* temp = current;
            current = current->next;
            delete temp;
            
            posIndex++; // Move to the next position in `L2`
        } else {
            // Move to the next node in `L1`
            previous = current;
            current = current->next;
        }
        currentIndex++;
    }
}

// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to demonstrate the deletion
int main() {
    // Creating list L1: A -> B -> C -> D -> E
    Node* L1 = new Node('A');
    L1->next = new Node('B');
    L1->next->next = new Node('C');
    L1->next->next->next = new Node('D');
    L1->next->next->next->next = new Node('E');

    // Ordered list L2 containing positions to delete
    int L2[] = {2, 4, 8};
    int size = sizeof(L2) / sizeof(L2[0]);

    // Delete nodes at positions specified in L2
    deleteNodesAtPositions(L1, L2, size);

    // Print the modified list L1
    cout << "Modified List L1: ";
    printList(L1);

    // Clean up memory
    while (L1 != nullptr) {
        Node* temp = L1;
        L1 = L1->next;
        delete temp;
    }

    return 0;
}
