#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return findMin(x->right);
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else if (x->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return findMax(x->left);
    Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else if (x->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int x : arr) root = insert(root, x);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int key = 15;
    Node* r1 = searchRecursive(root, key);
    Node* r2 = searchIterative(root, key);
    cout << "Search " << key << " (recursive): " << (r1 ? "Found" : "Not Found") << endl;
    cout << "Search " << key << " (iterative): " << (r2 ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, r1);
    Node* pred = inorderPredecessor(root, r1);
    cout << "Inorder successor of " << key << ": " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder predecessor of " << key << ": " << (pred ? to_string(pred->data) : "None") << endl;
}
