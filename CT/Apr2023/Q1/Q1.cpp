// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void reverse(List& charList)
{
    cout<<"Reversed list: ";
	int k = charList.getLength();
    for (int i = k; i >= 0; i--){
        cout<<charList.get(i)<<" ";
    }
    cout<<endl;
}

int main()
{
    List list;
    cout<<"Enter a string: ";
    string m;
    cin>>m;
    for (char c : m){
        list.add(c);
    }     
    reverse(list);
}

