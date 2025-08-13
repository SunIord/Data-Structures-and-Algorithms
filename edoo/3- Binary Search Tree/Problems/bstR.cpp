// cd "edoo\3- Binary Search Tree\Problems"
// g++ -std=c++11 bstR.cpp -o bstR
// ./bstR
// Código feito em períodos passados

#include <iostream>

using namespace std;

class Node {
private:
    /**/

public:
    int key;
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
    
    bool findHelp(Node* root, int k) {
        if (root == nullptr) {
            return false;
            
        }

        if (root->key > k) {
            return findHelp(root->left, k);
            
        } else if (root->key == k) {
            return true;
            
        } else {
            return findHelp(root->right, k);
            
        }
        
    }
    
    Node* insertHelp(Node* root, int k, bool& inserted) {
        if (root == nullptr) {
            Node* newNode = new Node();
            newNode->key = k;
            newNode->left = newNode->right = nullptr;
            inserted = true;    //minha teoria pro caso 8
            return newNode;

        }
        
        if (root->key > k) {
            root->left = insertHelp(root->left, k, inserted);

        } else {
            root->right = insertHelp(root->right, k, inserted);

        }
        return root;

    }
    
   Node* removeHelp(Node* root, int k) { 
        if (root == nullptr) {
            return nullptr;
            
        }
        if (root->key > k) {
            root->left = removeHelp(root->left, k);
            
        } else if (root->key < k) {
            root->right = removeHelp(root->right, k);
            
        } else {
            if (root->left == nullptr) {
                return root->right;
                
            } else if (root->right == nullptr) {
                return root->left;
                
            } else {
                Node* temp = getmin(root->right);
                root->key = temp->key;
                root->right = deletemin(root->right);
                
            }
            
        }
        return root;
        
    }

public:
    Bst() : root(nullptr), nodeCnt(0) {}
    
    ~Bst() {recursiveDeletion(root);}
    
    bool find(int k) {
        return findHelp(root, k);
        
    }

    void insert(int k) {
        bool inserted = false;
        root = insertHelp(root, k, inserted);
        if (inserted) {
            nodeCnt++;

        }

    }

    int erase(int k) {
        int temp = findHelp(root, k);
        if (temp != -1) {
            root = removeHelp(root, k);
            nodeCnt--; 
            
        }
        return temp;
        
    }
    
    int getNodeCnt() {
        return nodeCnt;

    }
    
    Node* getmin(Node* root) {
        if (root->left == NULL) {
            return root;
            
        }
        return getmin(root->left);
        
    }
    
    Node* deletemin(Node* root) {
        if (root->left == NULL) {
            return root->right;
            
        }
        root->left = deletemin(root->left);
        return root;
        
    }
    
    void posOrder(Node* root) {
        if (root != nullptr) {
          posOrder(root->left);
          posOrder(root->right);
          cout << root->key << endl;
          
        }
        
    }

    void printPosOrder() {
        posOrder(root);

    }

};

int main() {
    Bst abb;
    int c;
    string cmnd;
    int n;
    
    cin >> c;
    
    for (int i = 0; i < c; i++) {
        cin >> cmnd;
        if (cmnd == "ins") {
            cin >> n;
            abb.insert(n);
            
        } else if (cmnd == "rem") {
            cin >> n;
            abb.erase(n);
            
        }
        
    }
    cout << abb.getNodeCnt() << endl;
    abb.printPosOrder();
    
    return 0;
    
}