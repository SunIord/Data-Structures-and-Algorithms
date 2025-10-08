// cd algoritmos
// g++ binarySearchTree.c -o bst
// ./bst

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int k, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = k;
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void recursiveDeletion(Node* curr) {
    if (curr != NULL) {
        recursiveDeletion(curr->left);
        recursiveDeletion(curr->right);        
        free(curr);
    }
}

int find(Node* root, int k) {
    if (root == NULL) return -1;
    if (root->key > k) return find(root->left, k);
    else if (root->key == k) return root->value;
    else return find(root->right, k);
}

Node* insert(Node* root, int k, int v) {
    if (root == NULL) return createNode(k, v);
    if (root->key > k) root->left = insert(root->left, k, v);
    else root->right = insert(root->right, k, v);
    return root;
}

Node* getmin(Node* root) {
    if (root->left == NULL) return root;
    return getmin(root->left);
}

Node* deletemin(Node* root) {
    if (root->left == NULL) return root->right;
    root->left = deletemin(root->left);
    return root;
}

Node* erase(Node* root, int k) {
    if (root == NULL) return NULL;
    if (root->key > k) root->left = erase(root->left, k);
    else if (root->key < k) root->right = erase(root->right, k);
    else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        else {
            Node* temp = getmin(root->right);
            root->value = temp->value;
            root->key = temp->key;
            root->right = deletemin(root->right);
        }  
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void posOrder(Node* root) {
    if (root != NULL) {
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ", root->key);
    }
}

typedef struct Bst {
    Node* root;
    int nodeCnt;
} Bst;

Bst* createBst() {
    Bst* tree = (Bst*)malloc(sizeof(Bst));
    tree->root = NULL;
    tree->nodeCnt = 0;
    return tree;
}

void freeBst(Bst* tree) {
    recursiveDeletion(tree->root);
    free(tree);
}