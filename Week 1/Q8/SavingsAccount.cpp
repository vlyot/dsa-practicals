#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include <string>
using namespace std;

SavingsAccount::SavingsAccount(double b, double IR): Account(b){
    this->balance = b;
    this->InterestRate = IR;
}

double SavingsAccount::calculateInterest(SavingsAccount a){
    return (a.balance*a.InterestRate);
}