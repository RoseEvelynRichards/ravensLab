#include <iostream>
#include <string>
#include <thread>   // For this_thread::sleep_for
#include <chrono>   // For chrono::seconds
using namespace std;


struct Node {
    std::string data;
    Node* next;
};

// PROVIDED: Linked queue operations

void enqueue(Node*& front, Node*& rear, std::string name) {
    Node* newNode = new Node{name, nullptr};
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

std::string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";
    Node* oldFront = front;
    std::string name = oldFront->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete oldFront;
    return name;
}

void displayQueue(Node* front) {
    if (front == nullptr) {
        std::cout << "Queue is empty.\n";
        return;
    }
    std::cout << "Waiting customers: ";
    for (Node* current = front; current != nullptr; current = current->next)
        std::cout << current->data << " ";
    std::cout << std::endl;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front, rear, "Ali");
    enqueue(front, rear, "John");
    enqueue(front, rear, "Sara");
    enqueue(front, rear, "David");
    enqueue(front, rear, "Emma");

    displayQueue(front);
    int faketime = 5;

    while(front != nullptr){
        std::string curr = front->data;
        std::cout << "Now serving: " << curr << std::endl;
        this_thread::sleep_for(chrono::seconds(1));
        std::cout << "Service completed: " << dequeue(front,rear) 
        << " (" << faketime << " seconds)" <<std::endl; 
        faketime = faketime + 5;
    }

    std::cout << "All customers have been served." << std::endl;
    displayQueue(front);

    while (front != nullptr) dequeue(front, rear);
    return 0;
}
