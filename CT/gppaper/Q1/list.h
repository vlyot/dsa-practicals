// List.h - Specification of a Linked List ADT implemented using pointers
#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef int ItemType;

class LinkedList
{
  private:
    struct Node
    {
        ItemType item;  // Data item
        Node* next;     // Pointer to the next node
    };

    Node* head;    // Pointer to the first node in the list
    int length;    // Number of items in the list

  public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Add an item to the front of the list
    bool addFront(ItemType item);

    // Add an item to the back of the list
    bool addBack(ItemType item);

    // Add an item at a specified position in the list (index starts at 0)
    bool addAt(int index, ItemType item);

    // Remove an item from the front of the list
    bool removeFront();

    // Remove an item from the back of the list
    bool removeBack();

    // Remove an item at a specified position in the list
    bool removeAt(int index);

    // Get an item at a specified position of the list
    ItemType get(int index) const;

    // Find an item in the list (returns the index, or -1 if not found)
    int find(ItemType item) const;

    // Check if the list is empty
    bool isEmpty() const;

    // Get the length of the list
    int getLength() const;

    // Print all items in the list
    void printList() const;
};
