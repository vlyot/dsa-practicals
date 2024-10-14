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


double Account::credit(double amt){
    balance+=amt;
    cout<<"$"<<amt<<" added to balance"<<endl;
    return this->balance;
};
double Account::debit(double amt){
    if(amt < balance){
        balance-=amt;
        cout<<"$"<<amt<<" removed from balance"<<endl;
    }
    else{
        cout<<"Debit amount exceeded account balance"<<endl;
    }
return this->balance;
};
double Account::getbalance()const{
    cout<<"Current balance: "<<balance<<endl;
    return this->balance;
};