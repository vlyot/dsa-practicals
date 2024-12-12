// Dictionary.cpp - Implementation of Dictonary ADT using Hash Table with separate chaining
#include <list>
#include "Dictionary.h"	// firstNodeer file

// constructor
Dictionary::Dictionary()
{
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

// destructor
Dictionary::~Dictionary()
{
}

// get the hash value for the given search key
int Dictionary::hash(KeyType key) {
	int numbers[] = {key[0], key[1],key[2],key[3],key[4],key[5],key[6]};
    int weights[] = {7, 6, 5, 4, 3, 2, 2};
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += (numbers[i]) * weights[6 - i];
        numbers[i] /= 10;
    }
    return sum % 11; // Return remainder
}

// add a new item with a specified key in the Dictionary
void Dictionary::add(KeyType newKey, ItemType newItem) {
    int index = hash(newKey);
    Node* newNode = new Node();
    newNode->key = newKey;
    newNode->item = newItem;
    newNode->next = nullptr;

    Node* current = items[index];
    int chainLength = 0;

    while (current != nullptr) {
        chainLength++;
        current = current->next;
    }

    if (chainLength < 50) {
        newNode->next = items[index];
        items[index] = newNode;
    } else {
        int newIndex = (index + 1) % size;
        newNode->next = items[newIndex];
        items[newIndex] = newNode;
    }
}


// check if the Dictionary is empty
bool Dictionary::isEmpty()
{
	return size == 0;
}

// check the size of the Dictionary
int Dictionary::getLength()
{
	return size;
}

// print the Dictionary
void Dictionary::print()
{
	for (int i = 0; i < MAX_SIZE; i++)
		if (items[i] != NULL)
		{
			Node *current = items[i];
			while (current)
			{
				cout << current->key << " - " << current->item << endl;
				current = current->next;
			}
		}
}