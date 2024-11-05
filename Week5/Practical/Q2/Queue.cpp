#include<string>
#include<iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
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

bool Queue::dequeue(){
    if (frontNode == nullptr){
        return false;
    }
    else{
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        delete temp;
        return true;
    }
}

bool Queue::dequeue(ItemType &item){
    bool success = (frontNode != nullptr);
    if (success){
        Node* temp = frontNode;
        item = frontNode->item;  // Get the item at the front
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        cout<<"Item: "<<item<<" has been dequeued"<<endl;
        delete temp;
        return true;
    }
    else{
        return false;
    }
}

void Queue::getFront(ItemType &item){
    if (frontNode != nullptr){
        item = frontNode->item;
        cout<<"item at top is: "<<item<<"."<<endl;
    }
}

bool Queue::isEmpty(){
    return (frontNode == nullptr);
}

void Queue::displayItems(){
    int count = 0;
    if (frontNode == nullptr){
        cout<<"Queue is empty!"<<endl;
    }
    else{
        Node* current = frontNode;
        while (current != nullptr)
        {
            count++;
            cout<<"Item "<<count<<". : "<<current->item<<endl;
            current = current->next;
        }
    }
}