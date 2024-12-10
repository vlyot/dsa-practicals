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
	ItemType item;
	bool success = !s1.isEmpty();
	if (success){
		s1.getTop(item);
		s2.push(item);
		s1.pop();
		return true;
	}
	else{
		cout<<"queue is empty"<<endl;
		return false;
	}
}

void Queue::getFront(ItemType& item)
{
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            ItemType temp;
            s1.getTop(temp);
            s1.pop();
            s2.push(temp);
        }
    }

    if (!s2.isEmpty()) {
        s2.getTop(item);
    } else {
        cout << "Queue is empty" << endl;
    }
}


bool Queue::isEmpty() 
{ 
	return s1.isEmpty() && s2.isEmpty();
}
