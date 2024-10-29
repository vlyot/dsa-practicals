#include <iostream>
#include <vector>
#include <array>
#include "stack.h"
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

//check if the stack is empty
bool Stack::isEmpty(){
    Node* current = topNode;
    if(current != nullptr){
        return false;
    }
    return true;
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
    bool success = !isEmpty();
    if (success){
        Node* temp = topNode;
        item = temp->item; 
        cout<<"Top item from stack: "<<item<<endl;
    }
    else{
        cout<<"error"<<endl;
    }
};

//display items in stack in order
void Stack::displayInOrder(){
    bool success = !isEmpty();
    if (success){
        Node* current = topNode;  // Start at the top of the stack
        while (current != nullptr) {
            cout<<current->item<<" ";  // Store the current node
            current = current->next;  // Move to the next node
        }
        cout<<endl;
    }
    else{
        cout<<"Error: Stack is empty"<<endl;
    }
};

//display items in stack in order of insertion
void Stack::displayInOrderOfInsertion(){
    bool success = !isEmpty();
    if (success){
        vector<ItemType> ar;
        Node* current = topNode;  // Start at the top of the stack
        while (current != nullptr) {
            ar.push_back(current->item);  // Store the current node
            current = current->next;  // Move to the next node
        }
        for (int i = ar.size() - 1; i >= 0; --i) {
            cout << ar[i] << " ";
        }
        cout << endl;  
    }
    else{
        cout<<"Error: Stack is empty"<<endl;
    }
};