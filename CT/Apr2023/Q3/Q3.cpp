// Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Queue.h"

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.dequeue();
    q.dequeue();
    q.enqueue(13);
    q.enqueue(14);
}