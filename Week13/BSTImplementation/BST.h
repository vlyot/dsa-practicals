#pragma once
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int key);
    bool search(Node* node, int key) const;
    void inorder(Node* node) const;
    Node* remove(Node* node, int key);
    Node* findMin(Node* node) const;

public:
    BST();
    ~BST();

    void insert(int key);
    bool search(int key) const;
    void inorder() const;
    void remove(int key);
    void clear(Node* node);
};
