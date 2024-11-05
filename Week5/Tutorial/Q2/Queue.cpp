#include<string>
#include<iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
	front = 0;
  	back = MAX_SIZE - 1; // back = -1 for non-circular array
  	isFull = false;
    count = 0;
} 

bool Queue::enqueue(ItemType item){

    if (count<MAX_SIZE){
      back = (back + 1) % MAX_SIZE; //  back++ for non-circular array
      items[back] = item;
      count++;
      cout<<"Item "<<item<<" added to queue";
      return true;         // enqueue the item
    }
    return false;   
    
}

bool Queue::dequeue(){
    if (count>0 ){
      front = (front + 1) % MAX_SIZE; // front++ for non-circular array;
      count--;
      return true;         // enqueue the item
    }
    return false;   
}
bool Queue::dequeue(ItemType &item){
    bool success = (count>0);
    if (success){
        item = items[front];
      front = (front + 1) % MAX_SIZE;
      count--;
      cout<<"Item "<<item<<" removed from queue";
      return success;
    }
    return success;

}

void Queue::getFront(ItemType &item){
    if (count > 0){
        item = items[front];
        cout<<"Item at front: "<<item<<"."<<endl;
    }
    
}
bool Queue::isEmpty(){
    if(count == 0){
        return true;
    }
    else return false;
}