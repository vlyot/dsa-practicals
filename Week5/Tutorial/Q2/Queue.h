// Queue.h - Specification of Queue ADT (implemented using Circular Array)

#pragma once
#include<string>
#include<iostream>
#define MAX_SIZE 100
using namespace std;

typedef int ItemType;

class Queue
{
  private:
    ItemType items[MAX_SIZE];
    int  front;
    int  back;
    int count;
    bool isFull;

  public:
	// constructor
	Queue();
	// enqueue (add) item at back of the queue
	bool enqueue(ItemType item);
	// dequeue (remove) item from front of the queue
	bool dequeue();
      // retrieve (get) and dequeue item from front of the queue
	bool dequeue(ItemType& item);
	// retrieve (get) item from front of queue
	void getFront(ItemType& item); 
	// check if the queue is empty
	bool isEmpty(); 
}; 
