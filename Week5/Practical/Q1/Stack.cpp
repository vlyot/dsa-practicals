#include <iostream>
#include <vector>
#include <array>
#include "Stack.h"
using namespace std;

// Constructor implementation
Stack::Stack() {
    topNode = nullptr;  // Initialize topNode to nullptr indicating an empty stack
}

Stack::~Stack(){
    Node* current = topNode;  // Start at the top of the stack
    while (current != nullptr) {
        Node* temp = current;  // Store the current node
        current = current->next;  // Move to the next node
        delete temp;  // Delete the stored node
    }
    topNode = nullptr;
};


//push item on top of the stack
bool Stack::push(ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = topNode;

    topNode = newNode;
    return true;
}


//pop item from top of stack
bool Stack::pop(){
    bool success = !isEmpty();
    if (success){
        Node* temp = topNode; 
        topNode = topNode->next;
        delete temp;
        return true;
    }
    return false;
};

//retrieve and pop item from top of stack
bool Stack::pop(ItemType &item){
    bool success = !isEmpty();
    if (success){
        Node* temp = topNode;
        item = temp->item; 
        topNode = topNode->next;
        delete temp;
        return true;
    }
    return false;
};

//retrieve item from top of stack
void Stack::getTop(ItemType &item){
    if (!isEmpty()) {
        item = topNode->item;  // Retrieve the item at the top
        cout << "Top item from stack: " << item << endl;
    } else {
        cout << "Error: Stack is empty" << endl;
    }
};

bool Stack::isEmpty(){
    return (topNode == nullptr);
}
