#include<string>
#include<iostream>
#include"List.h"
using namespace std;

int main(){
    List* nameList = new List;
    nameList->add("Annie");
    nameList->add("Jacky");
    nameList->add("Wendy");

    nameList->print();

    nameList->add(1,"Brenda");
    nameList->print();

    nameList->remove(2);
    nameList->print();

    nameList->remove(0);
    nameList->print();

    return 0;
}