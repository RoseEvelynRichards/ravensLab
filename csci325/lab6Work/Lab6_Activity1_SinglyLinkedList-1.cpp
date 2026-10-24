// Activity 1: Singly Linked List (Starter Code)
// Complete each TODO func and add your own tests in main().

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// TODO 1: insert a new node at the beginning of the list.
void insertFront(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    return;
}
// Provided: Insert a node at the end.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) curr = curr->next;
    curr->next = newNode;
}

// Provided: Display the list from beginning to end.
void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// TODO 2: if exist return treu; otherwise return false.
bool search(Node* head, int value) {
    Node* curr = head;
    while(curr != NULL){
        if (curr->data == value) return true;
        curr = curr->next;
    }
    return false;  
}

// TODO 3: count and return the number of nodes.
int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;
    while(curr != NULL){
        count++;
        curr=curr->next;
    }
    return count;  
}

// TODO 4: Delete the node containing value.
// Update head when needed and release the removed node using delete.
void deleteValue(Node*& head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "Invalid position or list is empty." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse to the node before the target position
    Node* current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;
    //already provided insertEnd()
    insertEnd(head, 10); 
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    //already provided display()
    cout << "Original list: ";
    display(head);

    insertFront(head, 2);
    //if (search(head, 11)) cout << "True";
    //else cout << "False";

    //cout << countNodes(head);
    
    cout << "Edited List V1: ";
    display(head);

    deleteValue(head,1);
    deleteValue(head,4);
    //deleteValue(head,6);
    cout << "Edited List V2: ";
    display(head);

    return 0;
}
