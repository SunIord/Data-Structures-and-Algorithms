// cd "3- Binary Search Tree\Problems"
// g++ -std=c++11 swapNodes.cpp -o swapNodes
// ./swapNodes

#include <iostream>

class Node {
private:  
    int index;
    Node* left;
    Node* right;
    
public:
    Node(int idx) : index(idx), left(nullptr), right(nullptr) {}

    int getIndex() { return index; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    
    void setIndex(int idx) { index = idx; }
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }
    
};

class BinaryTree {
private:
    Node* root;
    Node** nodes;
    int nodeCnt;
    void recursiveDeletion(Node* curr) {
        if (curr != nullptr) {
            recursiveDeletion(curr->getLeft());
            recursiveDeletion(curr->getRight());        
            delete curr;
            
        } 
      
    }

public:
    BinaryTree() : root(nullptr), nodeCnt(0) {}

    ~BinaryTree() { recursiveDeletion(root); }

    void buildTree(int n) {
        if (n <= 0) return;
        
        nodes = new Node*[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i + 1);
        }
        
        root = nodes[0];
        nodeCnt = n;

        for (int i = 0; i < n; i++) {
            int leftIndex, rightIndex;
            std::cin >> leftIndex >> rightIndex;
            
            if (leftIndex != -1) {
                nodes[i]->setLeft(nodes[leftIndex - 1]);
            }
            if (rightIndex != -1) {
                nodes[i]->setRight(nodes[rightIndex - 1]);
            }
        }
    }

    void swapNodes(int k) {
        if (!root) return;
        Node** queue = new Node*[nodeCnt];
        int* depths = new int[nodeCnt];
        int front = 0, rear = 0;

        queue[rear] = root;
        depths[rear] = 1;
        rear++;
        
        while (front < rear) {
            Node* current = queue[front];
            int depth = depths[front];
            front++;
            
            if (depth % k == 0) {
                Node* temp = current->getLeft();
                current->setLeft(current->getRight());
                current->setRight(temp);
            }
            
            if (current->getLeft()) {
                queue[rear] = current->getLeft();
                depths[rear] = depth + 1;
                rear++;
            }
            if (current->getRight()) {
                queue[rear] = current->getRight();
                depths[rear] = depth + 1;
                rear++;
            }
        }
        
        delete[] queue;
        delete[] depths;
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->getLeft());
            std::cout << node->getIndex() << " ";
            inOrder(node->getRight());
        }

    }

    Node* getRoot() { return root; }
    
};

int main() {
    int n, t;
    std::cin >> n;

    BinaryTree tree;
    tree.buildTree(n);
    
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        std::cin >> k;
        tree.swapNodes(k);
        tree.inOrder(tree.getRoot());
        std::cout << std::endl;

    }

    return 0;
}