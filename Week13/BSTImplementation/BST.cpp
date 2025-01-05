#include "BST.h"

// Constructor
BST::BST() : root(nullptr) {}

// Destructor
BST::~BST() {
    clear(root);
}

// Helper to clear nodes
void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Insert a key into the BST
void BST::insert(int key) {
    insert(root, key);
}

// Recursive helper for insertion
void BST::insert(Node*& node, int key) {
    if (node == nullptr) {
        node = new Node(key);
    } else if (key < node->key) {
        insert(node->left, key);
    } else if (key > node->key) {
        insert(node->right, key);
    }
}

// Search for a key in the BST
bool BST::search(int key) const {
    return search(root, key);
}

// Recursive helper for search
bool BST::search(Node* node, int key) const {
    if (node == nullptr) {
        return false;
    } else if (key == node->key) {
        return true;
    } else if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// Inorder traversal
void BST::inorder() const {
    inorder(root);
    cout << endl;
}

// Recursive helper for inorder traversal
void BST::inorder(Node* node) const {
    if (node) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

// Remove a key from the BST
void BST::remove(int key) {
    root = remove(root, key);
}

// Recursive helper for removal
BST::Node* BST::remove(Node* node, int key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->key) {
        node = remove(node->left, key);
    } else if (key > node->key) {
        node = remove(node->right, key);
    } else {
        // Node with one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Node with two children: Get the inorder successor
        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

// Find the node with the minimum key
BST::Node* BST::findMin(Node* node) const {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}
