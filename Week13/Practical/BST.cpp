#include "BST.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function for countNodes
int BST::countNodesHelper(BinaryNode* node) {
    if (!node) return 0; // Base case: no node
    // Count current node + nodes in left subtree + nodes in right subtree
    return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
}

// Public countNodes method
int BST::countNodes() {
    return countNodesHelper(root);
}

int BST::getHeight(){
    if (!root) return 0;

    queue<BinaryNode*> q;
    q.push(root);

    int count = 0;

    while (!q.empty()){
        BinaryNode* current = q.front();
        q.pop();
        count++;

        if (current->left){
            q.push(current->left);
        } 
        if (current->right){
            q.push(current->right);
        } 
    }

    return count;
}
bool BST::isBalanced() {
    return isBalanced(root); // Start the check from the root node
}
int BST::height(BinaryNode* t) {
    if (!t) return 0; // Base case: the height of an empty tree is 0
    return 1 + std::max(height(t->left), height(t->right)); // Recursively calculate height
}
// Helper method to check if a subtree is balanced
bool BST::isBalanced(BinaryNode* t) {
    if (!t) return true; // An empty tree is balanced

    // Calculate the heights of the left and right subtrees
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);

    // Check if the current node is balanced
    bool isCurrentNodeBalanced = std::abs(leftHeight - rightHeight) <= 1;

    // Recursively check if left and right subtrees are balanced
    bool isLeftSubtreeBalanced = isBalanced(t->left);
    bool isRightSubtreeBalanced = isBalanced(t->right);

    // The tree is balanced if the current node and both subtrees are balanced
    return isCurrentNodeBalanced && isLeftSubtreeBalanced && isRightSubtreeBalanced;
}
