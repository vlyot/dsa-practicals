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

int Dictionary::hash(KeyType key) {
    int intKey = 0;
    for (char a : key) {
        intKey += charvalue(a);
    }
    return intKey % MAX_SIZE;
}


bool Dictionary::add(KeyType newKey, ItemType newItem){
    Node* newNode = new Node();
    int index = hash(newKey);
    newNode->key = newKey;
    newNode->item = newItem;
    newNode->next = nullptr;

    if (items[index] == nullptr){
        items[index] = newNode;
    }
    else{
        Node* current = items[index];
        while (current->next != nullptr){
            if (current->key == newKey){
                current->item = newItem;
                delete newNode;
                return true;
            }
            current = current->next;
        }
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


