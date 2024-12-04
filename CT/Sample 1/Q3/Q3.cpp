// Test1SampleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

void registerCustomer(Queue& serviceQueue, int& queueNumber)
{
	cout<<"Enter name: ";
	string name;
	cin>>name;
	cout<<endl;
	queueNumber + 1;

	Customer c = Customer(queueNumber, name);
	serviceQueue.enqueue(c);
}

void nextCustomer(Queue& serviceQueue)
{
	Customer c = serviceQueue.getFront();
	serviceQueue.dequeue(c);
	cout<<"Queue number: "<<c.getQueueNumber()<<endl;

}

void displayCount(Queue& serviceQueue)
{
	serviceQueue.count();
		
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	
	nextCustomer(serviceQueue);
	

	displayCount(serviceQueue);



}

