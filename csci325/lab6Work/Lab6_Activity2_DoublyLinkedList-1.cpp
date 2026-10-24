// Activity 2: Doubly Linked List (Starter Code)
// Complete each TODO function and add your own tests in main().

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

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

void displayForward(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//If you do something horrible, don't be caught by others, especially the FBI.
//-Professor Jian Wang
// TODO 1: display nodes backward using prev.
void displayBackward(Node* head) {
    Node* curr = head;
    int pos = 0;
    while(curr != nullptr) {
        pos++;
        curr = curr->next;
    }
    curr = head;
    for (int i = 0; i < pos - 1; i++) curr = curr->next;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl; 
}


int search(Node* head, int value){
    Node* curr = head;
    int pos = 0; 
    while (curr != nullptr && curr->data != value) {
        pos++;
        curr = curr->next;
    }
    return (pos + 1);
}

// TODO 2: Delete the node containing value.
//I assume this is asking me to search for a value to delete it
// Update next, prev, and head as necessary, and release the node.
void deleteValue(Node*& head, int value) {
    Node *curr = head;
    int pos = search(head, value);
    for (int i = 1; curr != nullptr && i < pos; ++i) {
        curr = curr->next;
    }
    if (curr->prev != nullptr) curr->prev->next = curr->next;
    if (curr->next != nullptr) curr->next->prev = curr->prev;
    if (head == curr) head = curr->next;
    
    delete curr;
    return;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 90);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);

    deleteValue(head,20);
    cout << "Edited: ";
    displayForward(head);
    // see task guidelines from Activity 2.

    return 0;
}
