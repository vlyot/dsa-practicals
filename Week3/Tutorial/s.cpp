#include<string>
#include<iostream>
#include "s.h"
using namespace std;

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

int List::getLength() {
    return size;
}