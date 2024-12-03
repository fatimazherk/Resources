#include <iostream>
using namespace std;

// Class for a Node in the circular linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() { head = nullptr; }

    // Function to insert a node at the beginning of the list
    void insertAtFirst(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position)
    {
        Node* newNode = new Node(value);
        if (position <= 1 || head == nullptr) {
            insertAtFirst(value);
        }
        else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete the first node of the list
    void deleteFromFirst()
    {
        if (head == nullptr)
            return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* tempHead = head;
            temp->next = head->next;
            head = head->next;
            delete tempHead;
        }
    }

    // Function to delete the last node of the list
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    // Function to delete a node with a specific key
    void deleteByKey(int key)
    {
        if (head == nullptr)
            return;
        if (head->data == key) {
            deleteFromFirst();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Function to print the elements of the list
    void display()
    {
        if (head == nullptr)
            return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

int main()
{
    // Initialize a circular linked list
    CircularLinkedList cll;

    cout << "Circular linked list after inserting node at the beginning:" << endl;
    cll.insertAtFirst(10);
    cll.display();

    cout << "Circular linked list after inserting 20, 30, 40, 50 at the end:" << endl;
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);
    cll.display();

    cout << "Circular linked list after inserting 15 at position 2:" << endl;
    cll.insertAtPosition(15, 2);
    cll.display();

    cout << "Circular linked list after deleting the first node:" << endl;
    cll.deleteFromFirst();
    cll.display();

    cout << "Circular linked list after deleting the last node:" << endl;
    cll.deleteFromEnd();
    cll.display();

    cout << "Circular linked list after deleting node with key 30:" << endl;
    cll.deleteByKey(30);
    cll.display();

    return 0;
}
