#include <string>
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
    frontNode = nullptr;
    backNode = nullptr;
}

Queue::~Queue() {
    while (frontNode != nullptr) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
    backNode = nullptr;
}

bool Queue::enqueue(ItemType item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (frontNode == nullptr) {
        frontNode = newNode;
    } else {
        backNode->next = newNode;
    }
    backNode = newNode;
    return true;
}

bool Queue::dequeue() {
    if (frontNode == nullptr) {
        return false;
    } else {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        delete temp;
        return true;
    }
}

bool Queue::dequeue(ItemType& item) {
    if (frontNode == nullptr) {
        return false;
    } else {
        Node* temp = frontNode;
        item = frontNode->item; // Get the item at the front
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        delete temp;
        return true;
    }
}

void Queue::getFront(ItemType& item) {
    if (frontNode != nullptr) {
        item = frontNode->item;
    } else {
        cout << "Queue is empty." << endl;
    }
}

bool Queue::isEmpty() {
    return (frontNode == nullptr);
}

void Queue::displayItems() {
    if (frontNode == nullptr) {
        cout << "Queue is empty!" << endl;
    } else {
        Node* current = frontNode;
        int count = 0;
        while (current != nullptr) {
            count++;
            cout << "Item " << count << ": " << current->item.getName() << endl;
            current = current->next;
        }
    }
}
