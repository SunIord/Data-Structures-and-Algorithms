// cd "edoo\3- Binary Search Tree\Problems"
// g++ -std=c++11 niceBinaryTree.cpp -o niceBinaryTree
// ./niceBinaryTree

#include <iostream>
#include <string>

class Node {
private:
    char label;
    Node* left;
    Node* right;

public:
    Node(char nl) {
        label = nl;
        left = nullptr;
        right = nullptr;
      
    }

    char getLabel() { return label; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setLabel(char nl) { label = nl; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }
};

class Nbt {
private:
    Node* root;
    int idx;

    void recursiveDeletion(Node* curr) {
        if (curr != nullptr) {
            recursiveDeletion(curr->getLeft());
            recursiveDeletion(curr->getRight());        
            delete curr;
        } 
    }

    Node* buildTree(const std::string& preorder) {
        if (idx >= preorder.size()) {
            return nullptr;
        
        }
        
        char c = preorder[idx++];
        Node* node = new Node(c);
        
        if (c == 'n') {
            node->setLeft(buildTree(preorder));
            node->setRight(buildTree(preorder));
            
        }
        
        return node;
    }

    int getDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        
        }
        if (node->getLabel() == 'l') {
            return 0;
        
        }
        
        int leftDepth = getDepth(node->getLeft());
        int rightDepth = getDepth(node->getRight());
        
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }

public:
    Nbt() : root(nullptr), idx(0) {}

    ~Nbt() { 
        recursiveDeletion(root); 
    }

    void build(const std::string& preorder) {
        idx = 0;
        root = buildTree(preorder);
    }
    int depth() {
        if (root == nullptr) return 0;
        return getDepth(root);
    }
};

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); 
    
    while (t--) {
        std::string preorder;
        getline(std::cin, preorder);
        
        Nbt tree;
        tree.build(preorder);
        std::cout << tree.depth() << std::endl;
    }
    return 0;
}