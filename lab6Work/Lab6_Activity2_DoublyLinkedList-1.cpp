// Activity 2: Doubly Linked List (Starter Code)
// Complete each TODO function and add your own tests in main().

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Provided: Insert a node at the end, check difference of prev.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
}

// Provided: Display from the first node to the last.
void displayForward(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// TODO 1: display nodes backward using prev.
void displayBackward(Node* head) {
    Node* curr = head;
}

// TODO 2: Delete the node containing value.
// Update next, prev, and head as necessary, and release the node.
void deleteValue(Node*& head, int value) {
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Forward: ";
    displayForward(head);

    // see task guidelines from Activity 2.

    return 0;
}
