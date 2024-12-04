#include "Dictionary.h"
using namespace std;
#include <iostream>
// constructor
Dictionary::Dictionary()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = nullptr;
    }
}

// destructor
Dictionary::~Dictionary() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        while (table[i] != nullptr) 
        {
            KeyValuePair* temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
}

// returns the hash value of a given key.
int Dictionary::hashFunction(int key) 
{
    if (80 <= key <100){
        return 0;
    }
    else if (70<= key < 80){
        return 1;
    }
    else if (60<=key<70){
        return 2;
    }
    else if (50<-key<60){
        return 3;
    }
    else{
        return 4;
    }

}

// inserts a new key-value pair to the table array.
void Dictionary::insert(int key, string value)
{
int index = hashFunction(key);

    // Create a new key-value pair node
    KeyValuePair* newNode = new KeyValuePair();
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    // Insert at the appropriate index using chaining
    if (table[index] == nullptr) {
        // No collision, simply insert the new node
        table[index] = newNode;
    } else {
        // Collision occurred, add to the chain (linked list)
        KeyValuePair* current = table[index];

        // Traverse the chain to check if the key already exists
        while (current != nullptr) {
            if (current->key == key) {
                // If key already exists, update its value and return
                current->value = value;
                delete newNode;  // Avoid memory leak
                return;
            }
            if (current->next == nullptr) {
                break;  // Stop at the end of the chain
            }
            current = current->next;
        }

        // Append the new node to the end of the chain
        current->next = newNode;
    }

    cout << "Inserted key " << key << " with value: " << value << endl;

}



