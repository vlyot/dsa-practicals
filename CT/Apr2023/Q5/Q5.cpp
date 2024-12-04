// Q5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
    Dictionary d;
    d.insert(80, "Jeremy");
    d.insert(65, "Thomas");
    d.insert(47, "Steven");
    d.insert(93, "Mary");

    cout<<d.hashFunction(52)<<endl;
}
