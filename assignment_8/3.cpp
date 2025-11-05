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
    if (val == root->data) return root; 
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        } 
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
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

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 10);

    cout << "Inorder after deleting 10: ";
    inorder(root);
    cout << endl;

    cout << "Maximum depth: " << maxDepth(root) << endl;
    cout << "Minimum depth: " << minDepth(root) << endl;
}
