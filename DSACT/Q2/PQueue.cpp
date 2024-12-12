// PQueue.cpp - Implementation of PQueue ADT (Pointer-based)
#include "PQueue.h"

PQueue::PQueue()
{
	frontNode = NULL;
	backNode = NULL;
}

PQueue::~PQueue() { }
void PQueue::enqueue(ItemType anItem, PriorityType p) {
    Node* newNode = new Node();
    newNode->item = anItem;
    newNode->priority = p;
    newNode->next = nullptr;

    if (frontNode == nullptr || p > frontNode->priority) {
        newNode->next = frontNode;
        frontNode = newNode;
    } else {
        Node* current = frontNode;
        while (current->next != nullptr && current->next->priority >= p) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

bool PQueue::isEmpty() { return frontNode == NULL; }

void PQueue::print()
{
	Node* temp = frontNode;
	while (temp != NULL)
	{
		cout << "Item: " << temp->item << " Priority : " << temp->priority << endl;
		temp = temp->next;
	}
		
}

