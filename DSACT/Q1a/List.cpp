// List.cpp - Implementation of List ADT using Pointers

#include "List.h"	// List header

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}  

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
   // create a new node to store the item
   Node *newNode = new Node;
   newNode->item = item;
   newNode->next = NULL;

   if ( isEmpty() )
	firstNode = newNode;
   else
   {
	Node *temp = firstNode;
        while (temp->next != NULL)
		temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
   }
   size++;
   
   return true;  // no size constraint
}  

// add an item at a specified position in the list (insert)
bool List::add(int index, ItemType item)
{
   bool success = (index >= 0) && (index <= size+1);

   if (success)
   {
		// create a new node to store the item
		Node *newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		
		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node *temp = firstNode;
			for (int i=0; i<index-1; i++)
				temp = temp->next;		// move to node at the position before the index

			newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
		}
		size++;
   }

   return success;
}  

void List::rotate(int n) {
    if (firstNode == nullptr || n <= 0) return;

    Node* temp = firstNode;
    int length = 1;
    while (temp->next != nullptr) {
        temp = temp->next;
        length++;
    }


    temp->next = firstNode;


    Node* newTail = firstNode;

    for (int i = 1; i < n; i++) {
        newTail = newTail->next;
    }

    firstNode = newTail->next;
    newTail->next = nullptr;
}


// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
   ItemType item;
   bool success = (index >= 0) && (index < size);
   if (success)
   {
	  Node *current  = firstNode;
	  for (int i=0; i<index; i++)
		 current = current->next;		// move to next node
		
	  item = current->item;
   }

   return item;	
}  

// check if the list is empty
bool List::isEmpty() { return size == 0; }  

// check the size of the list
int List::getLength() { return size; }  

//------------------- Other useful functions -----------------
void List::print()
{
	Node *temp = firstNode;

	if (temp != NULL)		// list is NOT empty
	{
		while (temp != NULL)
		{
			cout << temp->item << endl;
			temp = temp->next;		// move to next node
		}
	}
	else   // list is empty
		cout << "The list is empty." << endl;
}



