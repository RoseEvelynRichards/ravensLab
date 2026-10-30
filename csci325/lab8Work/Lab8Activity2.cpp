#include <iostream>
#include <vector>

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
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
       root->right = insert(root->right, value);
    }

    return root;
}

// return the matching node or nullptr if key isn't in BST.
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
        // TODO: Search the right subtree
    }
}

// Inorder expected result is : 20 30 40 50 60 65 70 80 
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->data << ' ';
    inorderTraversal(root ->right);

// Inorder: Left -> Root -> Right
}

int main(){
    std::vector<int> values = {50, 30, 70, 20, 40, 60, 80, 65};
    Node* root = nullptr;
    //insertion
    for (int value : values)
        root = insert(root, value);
   
        //traversal
    std::cout << "BST In-Order Traversal: " << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;
    //search
    int targets[] = {40, 55};
    for (int target : targets) {
        Node* result = search(root, target);
        std::cout << "Search for " << target << ": ";
        std::cout << (result != nullptr ? "Found" : "Not found") << std::endl;
    }

    return 0;
}


