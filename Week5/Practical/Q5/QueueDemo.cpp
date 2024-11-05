#include<string>
#include<iostream>
#include "Queue.h"
using namespace std;

int main(){
    Queue *q = new Queue();
    q->enqueue('a');
    q->enqueue('b');
    char front;
    q->getFront(front);
    q->displayItems();
    q->dequeue();
    q->displayItems();

    return 0;
}