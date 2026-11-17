#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void insert(Node*& root, int val) {     //insert ke bst
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
        return;
    }

    if (val < root->data) {
        insert(root->left, val);
    } else if (val > root->data) {
        insert(root->right, val);
    }
}

void inorder(Node* root) {      //traversal
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

