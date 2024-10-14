#pragma once
#define ACCOUNT_H
using namespace std;

class Account
{
private:
    double balance;
public:
    Account(double b);
    double credit(double amt, Account a);
    double debit(double amt,Account a);
    double getbalance(Account a);
};



