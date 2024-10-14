#pragma once
#define ACCOUNT_H
using namespace std;

class Account
{
protected:
    double balance;
public:
    Account(double b);
    double virtual credit(double amt);
    double virtual debit(double amt);
    double getbalance()const;
};



