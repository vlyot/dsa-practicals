#include <iostream>
#include "Account.h"
#include <string>
using namespace std;

Account::Account(double b){
    if (b > 0)
    {
        this->balance = b;
    }
    else{
        cout<<"error: initial balance invalid"<<endl;
    }
}

double Account::credit(double amt, Account a){
    a.balance+=amt;
    cout<<"$"<<amt<<" added to balance"<<endl;
};
double Account::debit(double amt,Account a){
    if(amt < a.balance){
        a.balance-=amt;
        cout<<"$"<<amt<<" removed from balance"<<endl;
    }
    else{
        cout<<"Debit amount exceeded account balance"<<endl;
    }
};
double Account::getbalance(Account a){
    cout<<"Current balance: "<<a.balance<<endl;
};