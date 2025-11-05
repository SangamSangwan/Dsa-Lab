#include <iostream>
#include <climits>
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

bool isBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "The tree is a BST." << endl;
    else
        cout << "The tree is NOT a BST." << endl;
}
