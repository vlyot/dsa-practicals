#include<string>
#include "Dictionary.h"
#include<iostream>
using namespace std;

// Hash function
int Dictionary::hash(KeyType key) {
    return key % MAX_SIZE;
}

// Add a new item with the specified key to the Dictionary
bool Dictionary::add(KeyType newKey, ItemType newItem) {
    int index = hash(newKey);
    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->item = newItem;
    newNode->next = nullptr;

    // Insert the new node at the beginning of the linked list
    if (items[index] == nullptr) {
        items[index] = newNode;
    } else {
        Node* current = items[index];
        while (current->next != nullptr) {
            // If the key already exists, update the value and return
            if (current->key == newKey) {
                current->item = newItem;
                delete newNode;  // Cleanup as we don’t need a new node anymore
                return true;
            }
            current = current->next;
        }
        // Insert the new node
        current->next = newNode;
    }

    size++;
    return true;
}

void Dictionary::remove(KeyType key) {
    int index = hash(key);
    Node* current = items[index];
    Node* previous = nullptr;

    // Traverse the linked list to find the node to delete
    while (current != nullptr && current->key != key) {
        previous = current;
        current = current->next;
    }

    // Key not found
    if (current == nullptr) {
        cout << "Key not found!" << endl;
        return;
    }

    // Remove the node
    if (previous == nullptr) {
        // The node to be deleted is the first node in the bucket
        items[index] = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    size--;
}