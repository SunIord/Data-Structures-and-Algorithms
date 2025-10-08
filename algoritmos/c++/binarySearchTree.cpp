// cd algoritmos\c++
// g++ binarySearchTree.cpp -o bst
// ./bst

#include <iostream>

class Node {    
private:
    int key;
    int value;
    Node* left;
    Node* right;

public:
    Node(int k, int v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }

    int getKey() { return key; }
    int getValue() { return value; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setKey(int k) { key = k; }
    void setValue(int v) { value = v; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }

};

class Bst {
private:
    Node* root;
    int nodeCnt;
    Node* getRoot() { return root; }

    void recursiveDeletion(Node* curr) {
        if (curr != nullptr) {
            recursiveDeletion(curr->getLeft());
            recursiveDeletion(curr->getRight());        
            delete curr;
        } 
    }

    int findHelp(Node* root, int k) {
        if (root == NULL) return -1;
        
        if (root->getKey() > k) return findHelp(root->getLeft(), k); 
        else if (root->getKey() == k) return root->getValue();
        else return findHelp(root->getRight(), k);
    }

    Node* insertHelp(Node* root, int k, int v) {
        if (root == nullptr) {
            Node* newNode = new Node(k, v);
            newNode->setKey(k);
            newNode->setValue(v);
            return newNode;
        }
        
        if (root->getKey() > k) root->setLeft(insertHelp(root->getLeft(), k, v));
        else root->setRight(insertHelp(root->getRight(), k, v));   
    
        return root;
    }

    Node* removeHelp(Node* root, int k) {
        if (root == nullptr) return nullptr;
        if (root->getKey() > k) {
            root->setLeft(removeHelp(root->getLeft(), k));
        } else if (root->getKey() < k) {
            root->setRight(removeHelp(root->getRight(), k));
        } else {
            if (root->getLeft() == nullptr) return root->getRight(); 
            else if (root->getRight() == nullptr) return root->getLeft();
            else {
                Node* temp = getmin(root->getRight());
                root->setValue(temp->getValue());
                root->setKey(temp->getKey());
                root->setRight(deletemin(root->getRight()));
            }  
        }
        return root;
    }

public:
    Bst() : root(nullptr), nodeCnt(0) {}

    ~Bst() { recursiveDeletion(root); }

    int find(int k) { return findHelp(root, k); }

    void insert(int k, int v) {
        root = insertHelp(root, k, v);
        nodeCnt++;
    }

    int erase(int k) {
        int temp = findHelp(root, k);
        if (temp != -1) {
            root = removeHelp(root, k);
            nodeCnt--;
        }
        return temp;
    }

    Node* getmin(Node* root) {
        if (root->getLeft() == NULL) return root;
        return getmin(root->getLeft());
    }
    
    Node* deletemin(Node* root) {
        if (root->getLeft() == NULL) return root->getRight();
        root->setLeft(deletemin(root->getLeft()));
        return root;
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            std::cout << root->getKey() << " ";
            preOrder(root->getLeft());
            preOrder(root->getRight());
        }
    }
    
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->getLeft());
            std::cout << root->getKey() << " ";
            inOrder(root->getRight());
        }
    }
    
    void posOrder(Node* root) {
        if (root != nullptr) {
            posOrder(root->getLeft());
            posOrder(root->getRight());
            std::cout << root->getKey() << " ";
        }
    }
};