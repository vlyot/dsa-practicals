// List.cpp - Implementation of List ADT using Array
#include <iostream>
#include "List.h"  // header file
using namespace std;

// constructor
List::List() 
{ 
	firstNode = NULL; 
	size = 0;
}

List::List(int arr[], int aSize)
{
	Node* newNode = new Node;  
	newNode->item = arr[0];
	newNode->next = NULL;
	firstNode = newNode; 
	Node* temp = firstNode;
	for (int i = 1; i < aSize; i++)
	{
		Node* newNode = new Node;
		newNode->item = arr[i];
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
	}
	size = aSize;
}
int List::removeFirst()
{   // find and correct the errors
	Node* p = firstNode;
    firstNode = firstNode->next;
	int reint = p->item;
    delete p;
	size--;
	return reint;
}

// duplicate another copy of list and return the new list in �new_list�
void List::duplicateList(List& new_list) 
{
	if (firstNode == nullptr){
		new_list.firstNode = nullptr;
		new_list.size = 0;
		return;
	}
	Node* temp = firstNode;
	new_list.firstNode = new Node();
	new_list.firstNode->item = temp->item;
	new_list.firstNode->next = nullptr;
	Node* newlistTemp = new_list.firstNode;

	temp = temp->next;
	while (temp->next != nullptr){
		Node* newNode = new Node();
        newNode->item = temp->item;
        newNode->next = nullptr;
        newlistTemp->next = newNode;
        newlistTemp = newNode;
        temp = temp->next;
	}
	new_list.size = size;
}

// check the size of the list
int List::getLength() { return size; }

// display the items in the list
void List::display()
{
	Node* temp = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
	
}
