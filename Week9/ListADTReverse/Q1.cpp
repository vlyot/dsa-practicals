// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void reverse(List& charList)
{
	List list;
    for (int i = charList.getLength(); i >= 0; i-- ){
        list.add(charList.get(i));
    }
    charList = list;
}

int main()
{
    List list;
    string m;
    cout<<"Enter a string : ";
    cin>>m;

    for (char c : m){
        list.add(c);
    }

    reverse(list);
    list.display();   
}

