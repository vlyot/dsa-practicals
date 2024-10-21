#include <string>
#include <iostream>
#include "list.h"
using namespace std;

// Add an item to the front of the list
bool LinkedList::addFront(ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = head;
    head = newNode;
    return true;
};

// Add an item to the back of the list
bool LinkedList::addBack(ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    // Step 2: Check if the list is empty
    if (head == nullptr) {
        // If the list is empty, new node becomes the first node
        head = newNode;
    } else {
        // Step 3: Traverse to the end of the list
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Step 4: Link the last node to the new node
        current->next = newNode;
    }

    // Step 5: Increment the length of the list
    length++; 
};

// Add an item at a specified position in the list (index starts at 0)
bool LinkedList::addAt(int index, ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if(index == 0){
        newNode->next = head;
        head = newNode;
    }else{
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    length++;
    return true;
};

// Remove an item from the front of the list
bool LinkedList::removeFront(){
    Node* temp = head;    // Store the current head node in a temporary pointer
    head = head->next;    // Update head to point to the second node

    delete temp;

    length--;
};

// Remove an item from the back of the list
bool LinkedList::removeBack() {
    // Step 1: Check if the list is empty
    if (head == nullptr) {
        return false;  // Cannot remove from an empty list
    }

    // Step 2: Handle the case where there is only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        // Step 3: Traverse to the second to last node
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        // Step 4: Delete the last node and update pointers
        Node* temp = current->next;
        delete temp;
        current->next = nullptr;  // Set the new last node's next pointer to nullptr
    }

    // Step 5: Decrement the length
    length--;

    return true;  // Indicate that the node was successfully removed
}

// Remove an item at a specified position in the list
bool LinkedList::removeAt(int index){
    if (head == nullptr) {
        return false;  // Cannot remove from an empty list
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        delete temp;
        current->next = nullptr; 
    }

    // Step 5: Decrement the length
    length--;

    return true;  // Indicate that the node was successfully removed
};

// Get an item at a specified position of the list
ItemType LinkedList::get(int index) const{
    // Step 1: Input validation
    if (head == nullptr || index < 0 || index >= length) {
        throw out_of_range("Index is out of range or the list is empty."); // Handle error
    }

    // Step 2: Traverse to the node at the specified index
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    // Step 3: Return the item of the specified node
    return current->item;
};

// Find an item in the list (returns the index, or -1 if not found)
int LinkedList::find(ItemType item) const{
    if (head == nullptr) {
        throw out_of_range("Index is out of range or the list is empty."); // Handle error
    }
    if (head->item == item){
        return 0;
    }
    Node* current = head;
    for (int i = 0; i < length; ++i) {
        if(current->item == item){
            return i;
        }
        current = current->next;
    }
    return -1;
};

// Check if the list is empty
bool isEmpty() const;

// Get the length of the list
int getLength() const;

// Print all items in the list
void printList() const;