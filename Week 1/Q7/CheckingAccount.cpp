#include <iostream>
#include "Account.h"
#include "CheckingAccount.h"
#include <string>
using namespace std;

CheckingAccount::CheckingAccount(double b, double c):Account(b){
    this->balance = b;
    this->Charge = c;
}

double CheckingAccount::credit(double amt, Account a) {
    balance += amt;
    balance -= Charge;  
    return balance;
}
double CheckingAccount::debit(double amt, Account a){
    if (amt + Charge > balance) {
    cout << "Debit amount plus charge exceeded account balance." << endl;
    return balance;
    }
    balance -= amt;
    balance -= Charge;  
    return balance;
};