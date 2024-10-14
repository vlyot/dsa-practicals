#pragma once
#define SAVINGSACCOUNT_H
using namespace std;
#include "Account.h"

class SavingsAccount : public Account{
private:
    double balance;
    double InterestRate;
public:
    SavingsAccount(double b, double IR);
    double calculateInterest(SavingsAccount a);
};