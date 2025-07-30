// cd "3- Binary Search Tree\Problems"
// g++ -std=c++11 fallingsLeaves.cpp -o fallingsLeaves
// ./fallingsLeaves
// Código feito em períodos passados

#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    /**/
    
public:
    char key;
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
    
    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->key;
            preOrder(root->left);
            preOrder(root->right);
            
        }
        
    }
    
    Node* getRoot() {
        return root;
        
    }

};

int main() {
    string line = "";
    string l = "";
    Bst abb;
    
    while (cin >> line) {
        if (line[0] == '*' || line[0] == '$') {
            for (int i = l.length() - 1; i >= 0; i--) {
                abb.insert(l[i]);
                
            }
            abb.preOrder(abb.getRoot());
            cout << endl;
            
            if (line[0] == '$') {
                return 0;
                
            }
            abb = Bst(); 
            l = "";
            line = "";
            
        }
        l += line;
        
    }
    return 0;
    
}