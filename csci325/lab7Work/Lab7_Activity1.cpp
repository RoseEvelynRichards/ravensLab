#include <iostream>
#include <string>
#include <cctype>
//using namespace std;

struct Node {
    char data;
    Node* next;
};

// Linked stack operations
void push(Node*& top, char value) {
    top = new Node{value, top};
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* oldTop = top;
    char value = oldTop->data;
    top = oldTop->next;
    delete oldTop;
    return value;
}

char peek(Node* top) {
    return (top == nullptr) ? '\0' : top->data;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

/**
 * @brief Takes an infix expression and coverts it to a postfix expression.
 * 
 * @param infix Infix Expression (eg. A+B*C)
 * @return std::string Postfix Expression (eg. ABC*+)
 */
std::string infixToPostfix(std::string infix) {
    Node* top = nullptr;
    std::string postfix = "";
    
    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if (isalnum(c)) postfix += c;
        else if (c == '(') push(top, '(');
        else if (c == ')'){
            while(peek(top) != '(' && !isEmpty(top)){
                postfix += peek(top);
                pop(top);
            }
            pop(top);
        }
        else{
            while(!isEmpty(top) && precedence(c) <= precedence(peek(top))){
               postfix += peek(top);
               pop(top); 
            }
            push(top, c);
        }
    }
    while(!isEmpty(top)){
        postfix += peek(top);
        pop(top);
    }

    return postfix;
}

int main() {
    std::string expression;
    std::cout << "Enter infix expression: ";
    std::cin >> expression;
    std::cout << "Postfix: " << infixToPostfix(expression) 
    << std::endl;

    return 0;
}
