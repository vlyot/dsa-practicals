#include<string>
#include "Dictionary.h"
#include<iostream>
using namespace std;
int main(){
    Dictionary* phoneBook = new Dictionary();
    phoneBook->add("Pamela", "64606722");
    phoneBook->add("PohSeng", "64608687");
    phoneBook->add("Wesley", "64607237");
    phoneBook->add("WeeChong", "64606854");
    phoneBook->print();
    cout<<"============================================="<<endl;
    phoneBook->add("Eugene", "64608256");
    phoneBook->add("Saiful", "64608206");
    phoneBook->print();
    cout<<"============================================="<<endl;
    phoneBook->add("PohSeng", "12345678");
    phoneBook->remove("Eugene");
    phoneBook->print();

    return 0;
}