#include<string>
#include<iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
    frontNode = nullptr;
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

int Queue::getNoOfElements(){
    int count = 0;
    if (frontNode == nullptr){
        return 0;
    }
    else{
        Node* current = new Node;
        current = frontNode;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
}

bool Queue::getLastElement(Queue& q, ItemType& item){
    if (q.isEmpty()){
        cout<<"Queue is empty!"<<endl;
        return false;
    }
    else{
        Queue::Node* current = q.frontNode;  // Start from the front node
        while (current->next != nullptr) {
            current = current->next;  // Traverse to the end of the queue
        }
        item = current->item;  // Get the last item
        cout << "Last element is: " << item << endl;
        return true;
    }
}