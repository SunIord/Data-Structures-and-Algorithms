#ifndef BST_HPP
#define BST_HPP

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

};

class Bst {
    Node* root;
    int nodeCnt;
    void recursiveDeletion(Node* curr) {
        if (curr != nullptr) {
            recursiveDeletion(curr->getLeft());
            recursiveDeletion(curr->getRight());        
            delete curr;
            
        } 
      
    }

    int findHelp(Node* root, int k) {
        if (root == NULL) {
            return -1;
            
        }
        
        if (root->getKey() > k) {
            return findHelp(root->getLeft(), k);
            
        } else if (root->getKey() == k) {
            return root->getValue();
            
        } else {
            return findHelp(root->getRight(), k);
            
        }
       
    }

    

};

#endif 