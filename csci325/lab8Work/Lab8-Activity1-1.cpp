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

static int indx = -1;

Node* buildTree(std::vector<int> preorder){
    indx++;

    if(preorder[indx] == -1){
        return nullptr;
    }

    Node* root = new Node(preorder[indx]);
    root->left = buildTree(preorder); // LEFT
    root->right = buildTree(preorder); // RIGHT

    return root;
}

// Preorder: Root -> Left -> Right
void preorderTraversal(Node* root) {
    if (root == nullptr) return;

    preorderTraversal(root->left);
    if (root == nullptr)return;
    std::cout << root->data << " ";
    
    preorderTraversal(root->right);
    if (root == nullptr) return; 
    
}


void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Postorder: Left -> Right -> Root
void postorderTraversal(Node* root) {
    // TODO: postorder
}

int main(){
    std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    std::cout << "Preorder Traversal: " << std::endl;
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "In-order Traversal: " << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: " << std::endl;
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
//+ Lab8-Activity1-1.cpp -o Act1