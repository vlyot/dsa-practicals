// List.cpp - Implementation of List ADT using Pointers (Linked-implementation

#include "List.h"	// firstNodeer file

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}

// add a new item to the back of the list (append)
bool List::add(ItemType newItem)
{
	// create a new node to store the data item
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
	}

	size++;

	return true;  // no size constraint
}

// add a new item at a specified position in the list (insert)
bool List::add(int index, ItemType newItem)
{
	bool success = (index >= 0) && (index <= size);

	if (success)
	{
		// create a new node to store the data item
		Node* newNode = new Node;
		newNode->item = newItem;
		newNode->next = NULL;

		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++)
				temp = temp->next;		// move to node at the position before the index

			newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
		}
		size++;
	}

	return success;
}

// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index <= size - 1) && (size != 0);
	if (success)
	{
		Node* tmp = firstNode;
		if (index == 0) // remove front node
			firstNode = firstNode->next;
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->next;		// move to next node
			}

			previous->next = current->next;	// delete the current node by
		}		                                // making previous node point to the node pointed to by current node
		delete tmp;
		tmp = NULL;
		size--;  // decrease the size of the list by one
	}
}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
	ItemType dataItem = -1;
	bool success = (index >= 0) && (index <= size - 1);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;		// move to next node

		dataItem = current->item;
	}

	return dataItem;
}

// check if the list is empty
bool List::isEmpty()
{
	return size == 0;
}

// check the size of the list
int List::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void List::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << temp->item << "\t";
			temp = temp->next;		// move to next node
		}
	}
}

void List::sortedInsertR(ItemType item) {
    // Base case: If list is empty or new item should be placed before firstNode
    if (firstNode == nullptr || firstNode->item > item) {
        Node* newNode = new Node();
        newNode->item = item;
        newNode->next = firstNode;
        firstNode = newNode;  // Update the head of the list to point to the new node
        return;
    }

    // Recursive case: Traverse through the list until the correct position is found
    Node* current = firstNode;
    if (current->next == nullptr || current->next->item > item) {
        Node* newNode = new Node();
        newNode->item = item;
        newNode->next = current->next;
        current->next = newNode;
    } else {
        // Continue the recursion on the next node
        firstNode = firstNode->next;
        sortedInsertR(item);
        firstNode = current;  // Restore firstNode after recursion returns
    }
}



void List::sortedInsert(ItemType item)
{
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (firstNode == nullptr) {
        firstNode = newNode;
    } 
	else if (item <= firstNode->item){
		newNode->next = firstNode;
		firstNode = newNode;
	}
	else{
		Node* current = firstNode;
		while (current->next != nullptr && current->next->item < item) {
            current = current->next;
        }
        
        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }
    
    size++;
	
}
	