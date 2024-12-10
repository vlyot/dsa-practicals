// Test1SampleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

void registerCustomer(Queue& serviceQueue, int& queueNumber)
{
	string n;
	cout<<"Enter customer name: ";
	cin>>n;
	queueNumber++;
	Customer c(queueNumber, n);
	serviceQueue.enqueue(c);

}

void nextCustomer(Queue& serviceQueue)
{
	Customer p;
	serviceQueue.getFront(p);
	serviceQueue.dequeue();
	cout<<p.getName()<<" 's queue number: "<<p.getQueueNumber()<<endl;

}

void displayCount(Queue& serviceQueue)
{
	int count = 0;
	Queue q = serviceQueue;
	while (!q.isEmpty()){
		count++;
		q.dequeue();
	}
	cout<<"Customer count: "<<count<<endl;
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	
	nextCustomer(serviceQueue);
	

	displayCount(serviceQueue);



}

