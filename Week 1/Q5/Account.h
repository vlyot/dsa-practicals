#pragma once
#define ACCOUNT_H
using namespace std;

class Account
{
private:
    double balance;
public:
    Account() {} 
    Account(double b) : balance(b) {}
    double credit(double amt, Account a);
    double debit(double amt,Account a);
    double getbalance(Account a);
};



