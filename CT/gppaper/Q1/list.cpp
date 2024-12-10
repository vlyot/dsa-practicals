#include "list.h"
#include <stdexcept>
#include <iostream>
using namespace std;

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
    length = 0;
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Check if the list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Get the length of the list
int LinkedList::getLength() const {
    return length;
}

// Print all items in the list
void LinkedList::printList() const {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}
