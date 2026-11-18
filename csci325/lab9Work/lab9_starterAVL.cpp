#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(
            getHeight(node->left),
            getHeight(node->right)
        );
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    // TODO: pwrform the rotation, height update, and return new root
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    // TODO: pwrform the rotation, height update, and return new root
    return y;
}

Node* insert(Node* node, int data) {
    if (node == nullptr) return new Node(data);
    if (data < node->data) node -> left = insert(node->left, data);
    else if (data > node->data) node -> right = insert(node->right, data);
    else return node;

    node->height = 1 + max(getHeight(node->left),getHeight(node->right));

    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data) return rightRotate(node);
    if (balance < -1 && data > node->right->data) return leftRotate(node);
    if (balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int validateAVL(Node* node) {
    if (node == nullptr) return 0;
    int leftHeight = validateAVL(node->left);
    int rightHeight = validateAVL(node->right);
    if (leftHeight < 0 || rightHeight < 0) return -1;
    if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) return -1;
    int actualHeight = 1 + max(leftHeight, rightHeight);
    return node->height == actualHeight ? actualHeight : -1;
}

int main() {
    vector<int> values = {30, 20, 40, 10, 25, 22, 50, 60};
    Node* root = nullptr;

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "Inorder: ";
    inorder(root);
    cout << '\n';
    cout << "Root: " << (root == nullptr ? -1 : root->data) << '\n';
    cout << "AVL validation: "
         << (root != nullptr && validateAVL(root) >= 0 ? "PASS" : "FAIL") << '\n';
    return 0;
}
