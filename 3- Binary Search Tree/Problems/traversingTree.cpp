// cd "3- Binary Search Tree\Problems"
// g++ -std=c++11 traversingTree.cpp -o traversingTree
// ./traversingTree
// Código feito em períodos passados

#include <iostream>

using namespace std;

class Node {
private:
    /**/
    
public:
    int key;
    int value;
    Node* left;
    Node* right;
    
};

class Bst {
private:
    Node* root;
    int nodeCnt;
    
    void recursiveDeletion(Node* curr) {
        if (curr != nullptr) {
            recursiveDeletion(curr->left);
            recursiveDeletion(curr->right);        
            delete curr;
            
        } 
      
    }
    
    Node* insertHelp(Node* root, int k) {
        if (root == nullptr) {
            Node* newNode = new Node();
            newNode->key = k;
            newNode->left = newNode->right = nullptr;
            return newNode;
            
        }
        
        if (root->key > k) {
            root->left = insertHelp(root->left, k);
            
        } else {
            root->right = insertHelp(root->right, k);
            
        }
        return root;
        
    }
    
public:
    Bst() : root(nullptr), nodeCnt(0) {}
    
    ~Bst() {recursiveDeletion(root);}

    void insert(int k) {
        root = insertHelp(root, k);
        nodeCnt++;
        
    }

    Node* getRoot() {
        return root;
        
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
            
        }
        
    }
    
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
            
        }
        
    }
    
    void posOrder(Node* root) {
        if (root != nullptr) {
          posOrder(root->left);
          posOrder(root->right);
          cout << root->key << " ";
          
        }
        
    }
    
};

int main() {
    Bst abb;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        abb.insert(value);
        
    }
    cout << "Pre order : ";
    abb.preOrder(abb.getRoot());
    cout << endl;
    
    cout << "In order  : ";
    abb.inOrder(abb.getRoot());
    cout << endl;
    
    cout << "Post order: ";
    abb.posOrder(abb.getRoot());
    cout << endl;
    
    return 0;
    
}