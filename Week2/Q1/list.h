// List.h - - Specification of List ADT
#pragma once
#include <iostream>
using namespace std;
/*-	List phone numbers in the list 
-	Add a phone number to the list
-	Remove a phone number from the list
-	Index the list for a phone number
*/
const int MAX_SIZE = 100;
class List{
    private:
    string numbers[MAX_SIZE];
    int size;
    public:
        //default constructor
        List();

        //list phone numbers in the list
	    //pre: 0 < size
	    //post: all items in the list are displayed
	    void display();

        //add phone numbers to the list
	    // pre : size < MAX_SIZE
	    // post: item is added to the back of the list
	    //       size of list is increased by 1'
        bool add(string number);

	    // remove a number at a specified position in the list
	    // pre : 0 <= index < size
	    // post: item is removed the specified position in the list
	    //       size of list is decreased by 1
	    void remove(int index);

        //index the list for a phone numbeer
        //pre: 0 < size
        //post: index of phone number is displayed
        void search(int index);
};