// cd algoritmos\c++
// g++ avlTree.cpp -o avl
// ./avl

#include <iostream>

class Node {    
private:
    int key;
    int value;
    int height;
    Node* left;
    Node* right;

public:
    Node(int k, int v) {
        key = k;
        value = v;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

    int getKey() { return key; }
    int getValue() { return value; }
    int getHeight() { return height; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setKey(int k) { key = k; }
    void setValue(int v) { value = v; }
    void setHeight(int h) { height = h; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }

};

class Avl {
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

    Node* insertHelp(Node* root, int k, int v) {
        if (root == nullptr) {
            Node* newNode = new Node(k, v);
            newNode->setKey(k);
            newNode->setValue(v);
            return newNode;
            
        }
        
        if (root->getKey() > k) {
            root->setLeft(insertHelp(root->getLeft(), k, v));
            
        } else {
            root->setRight(insertHelp(root->getRight(), k, v));
            
        }
        
        root->setHeight(1 + std::max(h(root->getLeft()), h(root->getRight())));
        int balance = getBalance(root);
        if (balance < -1 && k >= root->getRight()->getKey()) {
            return leftRotate(root);
        }
        if (balance > 1 && k < root->getLeft()->getKey()) {
            return rightRotate(root);
        }
        if (balance > 1 && k >= root->getLeft()->getKey()) {
            root->setLeft(leftRotate(root->getLeft()));
            return rightRotate(root);
        }
        if (balance < -1 && k < root->getRight()->getKey()) {
            root->setRight(rightRotate(root->getRight()));
            return leftRotate(root);
        }
        return root;
        
    }

    Node* removeHelp(Node* root, int k) {
        if (root == nullptr) {
            return nullptr;
            
        }
        if (root->getKey() > k) {
            root->setLeft(removeHelp(root->getLeft(), k));
            
        } else if (root->getKey() < k) {
            root->setRight(removeHelp(root->getRight(), k));

        } else {
            if (root->getLeft() == nullptr) {
                return root->getRight();
                
            } else if (root->getRight() == nullptr) {
                return root->getLeft();
                
            } else {
                Node* temp = getmin(root->getRight());
                root->setValue(temp->getValue());
                root->setKey(temp->getKey());
                root->setRight(deletemin(root->getRight()));

            }
            
        }
        root->setHeight(1 + std::max(h(root->getLeft()), h(root->getRight())));
        int balance = getBalance(root);
        if (balance < -1 && getBalance(root->getRight()) <= 0)
            return leftRotate(root);
        if (balance > 1 && getBalance(root->getLeft()) >= 0)    
            return rightRotate(root);           
        if (balance > 1 && getBalance(root->getLeft()) < 0) {
            root->setLeft(leftRotate(root->getLeft()));
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->getRight()) > 0) {
            root->setRight(rightRotate(root->getRight()));
            return leftRotate(root);
        }
        return root;

    }

    int h(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        return root->getHeight();
    }

    int getBalance(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return h(root->getLeft()) - h(root->getRight());
    }

    Node* rightRotate(Node* root) {
        Node* leftChild = root->getLeft();
        Node* leftRightChild = leftChild->getRight();
        leftChild->setRight(root);
        root->setLeft(leftRightChild);
        root->setHeight(std::max(h(root->getLeft()), h(root->getRight())) + 1);
        leftChild->setHeight(std::max(h(leftChild->getLeft()), h(leftChild->getRight())) + 1);
        return leftChild;
    }

    Node* leftRotate(Node* root) {
        Node* rightChild = root->getRight();
        Node* rightLeftChild = rightChild->getLeft();
        rightChild->setLeft(root);
        root->setRight(rightLeftChild);
        root->setHeight(std::max(h(root->getLeft()), h(root->getRight())) + 1);
        rightChild->setHeight(std::max(h(rightChild->getLeft()), h(rightChild->getRight())) + 1);
        return rightChild;
    }

public:
    Avl() : root(nullptr), nodeCnt(0) {}

    ~Avl() { recursiveDeletion(root); }

    int find(int k) {
        return findHelp(root, k);
        
    }

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
        if (root->getLeft() == NULL) {
            return root;
            
        }
        return getmin(root->getLeft());
        
    }
    
    Node* deletemin(Node* root) {
        if (root->getLeft() == NULL) {
            return root->getRight();
            
        }
        root->setLeft(deletemin(root->getLeft()));
        return root;
        
    }

    // Funções de travessia
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