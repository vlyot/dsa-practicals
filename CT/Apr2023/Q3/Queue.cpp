// Queue.cpp - Implementation of Queue ADT (Pointer-based)
#include "Queue.h"

Queue::Queue()
{
	s1 = Stack(); // always empty, ready for enqueue
	s2 = Stack(); // has items in reverse order, ready for dequeue
}

Queue::~Queue() { }

bool Queue::enqueue(const ItemType item)
{
	s1.push(item);
	return true;
}

bool Queue::dequeue()
{
	if (s2.isEmpty()){
		while (!s1.isEmpty()){
			s2.push(s1.getTop());
			s1.pop();
		}
	}
	if (s2.isEmpty()) {
        // Both stacks are empty, nothing to dequeue
        return false; 
    }

    // Pop from s2 (constant time operation)
    s2.pop();
    return true;
}

void Queue::getFront(ItemType& item)
{
    if (s2.isEmpty()) {
        // Transfer elements from s1 to s2 to access the front element
        while (!s1.isEmpty()) {
            ItemType topItem;
            s1.getTop(topItem);
            s2.push(topItem);
            s1.pop();
        }
    }

    if (!s2.isEmpty()) {
        // Get the front item from s2
        s2.getTop(item);
    }
    else {
        throw runtime_error("Queue is empty");
    }
}


bool Queue::isEmpty() 
{ 
	return s2.isEmpty() && s1.isEmpty();
}
