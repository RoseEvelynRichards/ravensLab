#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// insert new value .
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        // Todo: create and return a new node with value.
    }

    if (value < root->data) {
        // TODO: insert into the left subtree
    } else {
        // TODO: Insert into the right subtree
    }

    return root;
}

// return the matching node or nullptr if key isn't in BST.
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data) {
        // TODO: Search the left subtree.
    } else {
        // TODO: Search the right subtree
    }
}

// Inorder expected result is : 20 30 40 50 60 65 70 80 
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

// Inorder: Left -> Root -> Right
}

int main(){
    vector<int> values = {50, 30, 70, 20, 40, 60, 80, 65};
    Node* root = nullptr;
    //insertion
    for (int value : values)
        root = insert(root, value);
   
        //traversal
    cout << "BST In-Order Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;
    //search
    int targets[] = {40, 55};
    for (int target : targets) {
        Node* result = search(root, target);
        cout << "Search for " << target << ": ";
        cout << (result != nullptr ? "Found" : "Not found") << endl;
    }

    return 0;
}


