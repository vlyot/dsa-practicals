#include<string>
#include<iostream>
#include"List.h"
using namespace std;
// Constructor
List::List() {
    firstNode = nullptr;
    size = 0;
}

// Destructor
List::~List() {
    Node* current = firstNode;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// add an item to the back of the list (append)
bool List::add(ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    if (firstNode == nullptr) {
        firstNode = newNode;
    } else {
        Node* current = firstNode;
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = newNode;
    }
    size++;

    return true;
};

// add an item at a specified position in the list (insert)
bool List::add(int index, ItemType item){
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if(index == 0){
        newNode->next = firstNode;
        firstNode = newNode;
    }else{
        Node* current = firstNode;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
    return true;
};

void List::remove(int index) {
    if (firstNode == nullptr || index < 0 || index >= size) {
        return;  // Cannot remove from an empty list or invalid index
    }

    Node* temp;

    if (index == 0) {
        temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
    } else {
        Node* current = firstNode;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    size--;
}


// get an item at a specified position of the list (retrieve)
ItemType List::get(int index){
    if (firstNode== nullptr) {
        throw out_of_range("Index is out of range or the list is empty."); // Handle error
    }
    Node* current = firstNode;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->item;
}; 

// check if the list is empty
bool List::isEmpty(){
    if (firstNode== nullptr) {
        return true;
    }
    return false;
}; 

// check the size of the list
int List::getLength(){
return size;
};

// display all the items in the list
void List::print(){
    Node* current = firstNode;
    for (int i = 0; i < size; ++i) {
        cout<<i+1<<". "<<current->item<<"\n";
        current = current->next;
    }
    cout<<"======================"<<endl;
};