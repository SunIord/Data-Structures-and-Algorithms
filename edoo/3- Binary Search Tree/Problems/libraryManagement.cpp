// cd "edoo\3- Binary Search Tree\Problems"
// g++ -std=c++11 libraryManagement.cpp -o libraryManagement
// ./libraryManagement
// Código feito em períodos passados

#include <iostream>
//#include <string>  por alguma razão funciona sem

using namespace std;

//Bst mais completa até agr
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
                root->value = temp->value;
                root->key = temp->key;
                root->right = deletemin(root->right);
                
            }
            
        }
        return root;
        
    }
    
    void printBstHelp(Node* root) {
        if (root == nullptr) {
            return;
            
        }
        printBstHelp(root->left);
        cout << root->key << " ";
        printBstHelp(root->right);
        
    }
    
    int getHeightHelp(Node* root) {
        if (root == nullptr) return -1;  //altura 0
        int leftHeight = getHeightHelp(root->left);
        int rightHeight = getHeightHelp(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        
    }

public:
    Bst() : root(nullptr), nodeCnt(0) {}
    
    ~Bst() {recursiveDeletion(root);}
    
    bool find(int k) {
        return findHelp(root, k);
        
    }

    void insert(int k) {
        root = insertHelp(root, k);
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
    
    Node* getRoot() {
        return root;
        
    }
    
    Node* getmin(Node* root) {
        if (root->left == NULL) {
            return root;
            
        }
        return getmin(root->left);
        
    }
    
    Node* getmax(Node* root) {
        if (root->right == NULL) {
          return root;
          
        }
        return getmax(root->right);
        
    }
    
    Node* deletemin(Node* root) {
        if (root->left == NULL) {
            return root->right;
            
        }
        root->left = deletemin(root->left);
        return root;
        
    }
    
    Node* deletemax(Node* root) {
        if (root->right == NULL) {
            return root->left;
            
        }
        root->right = deletemax(root->right);
        return root;
        
    }
    
    void printBst() {
        printBstHelp(root);
        cout << endl;
        
    }
    
    int getHeight() {
        return getHeightHelp(root);
        
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
    string cmnd;
    int value;
    
    cin >> cmnd;
    while (cmnd != "END") {
        if (cmnd == "INSERT") {
            cin >> value;
            abb.insert(value);
            
        } else if (cmnd == "REMOVE") {
            cin >> value;
            abb.erase(value);
            
        } else if (cmnd == "EXISTS") {
            cin >> value;
            if (abb.find(value)) {
                cout << "YES" << endl;
                
            } else {
                cout << "NO" << endl;
                
            }
            
        } else if (cmnd == "MAX") {
            if (abb.getRoot() == nullptr) {
                cout << "EMPTY" << endl;
                
            } else {
                cout << abb.getmax(abb.getRoot())->key << endl;
                
            }
            
        } else if (cmnd == "MIN") {
            if (abb.getRoot() == nullptr) {
              cout << "EMPTY" << endl;
              
            } else {
                cout << abb.getmin(abb.getRoot())->key << endl;
                
            }
            
        } else if (cmnd == "INORDER") {
            abb.printBst();
            
        } else if (cmnd == "HEIGHT") {
            cout << abb.getHeight() << endl;
            
        }
        cin >> cmnd;
        
    }
    return 0;
  
}