#include<string>
#include "Dictionary.h"
#include<iostream>
using namespace std;

Dictionary::Dictionary(){
    for (int i=0; i < MAX_SIZE; i++){
        items[i] = nullptr;
    }
    size = 0;
}

Dictionary::~Dictionary(){
        for (int i=0; i < MAX_SIZE; i++){
            Node* current = items[i];
            while (current != nullptr){
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            items[i] = nullptr;
        }
}

    int Dictionary::charvalue(char c){
	    if (isalpha(c))
	    {
		    if (isupper(c))
			    return (int)c - (int) 'A';
		    else
			    return (int)c - (int) 'a' + 26;
	    }
	    else
		    return -1;
    }

int Dictionary::charvalue(char c){
    if (isalpha(c)) {
        if (isupper(c))
            return (int)c - (int) 'A';       // A-Z: 0-25
        else
            return (int)c - (int) 'a' + 26;  // a-z: 26-51
    } else {
        return -1;
    }
}

int Dictionary::hash(KeyType key) {
    int hash_value = 0;
    for (char a : key) {
        int char_val = charvalue(a);
        if (char_val >= 0) {
            hash_value = (hash_value * 52 + char_val) % MAX_SIZE; // Horner's rule
        }
    }
    return hash_value;
}


bool Dictionary::add(KeyType newKey, ItemType newItem) {
    // Create a new node with the provided key and item
    Node* newNode = new Node();
    int index = hash(newKey);
    newNode->key = newKey;
    newNode->item = newItem;
    newNode->next = nullptr;

    // Check if the bucket at the hashed index is empty
    if (items[index] == nullptr) {
        items[index] = newNode;
    } else {
        // Traverse the linked list to find duplicates or the end
        Node* current = items[index];
        while (current != nullptr) {
            if (current->key == newKey) {
                // If the key already exists, reject the new value
                cout << "Duplicate entry rejected: " << newKey << endl;
                delete newNode; // Prevent memory leak
                return false;
            }
            if (current->next == nullptr) {
                break; // Stop at the last node to add newNode at the end
            }
            current = current->next;
        }
        // Append new node at the end of the list
        current->next = newNode;
    }

    size++;
    return true;
}


void Dictionary::remove(KeyType key){
    int index = hash(key);
    if (items[index] == nullptr){
        cout << "Item not found!" << endl;
        return;
    }
    Node* current = items[index];
    Node* previous = nullptr;
    while (current != nullptr && current->key != key){
        previous = current;
        current = current->next;
    }
    if (current == nullptr){
        cout<<"Item not found!"<<endl;
    }
    if (previous == nullptr){
        items[index] = current->next;
    }else{
        previous->next = current->next;
    }

    delete current;
    size--;
}

ItemType Dictionary::get(KeyType key){
    int index = hash(key);
    Node* current = items[index];

    while (current != nullptr){
        if (current->key == key){
            return current->item;
        }
        current = current->next;
    }
    throw std::runtime_error("Key not found!");
}

bool Dictionary::isEmpty(){
    return size == 0;
}

int Dictionary::getLength(){
    return size;
}

void Dictionary::print(){
    for (int i = 0; i < MAX_SIZE; i++){
        Node* current = items[i];
        if (current != nullptr){
            cout<<"Bucket "<<i<<": ";
            while (current != nullptr){
                cout<< current->key<<" : "<<current->item;
                current = current->next;
            }
            cout<<endl;
        } 
    }
}


