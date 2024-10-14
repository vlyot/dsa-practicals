#pragma once
#define CHECKINGACCOUNT_H
#include "Account.h"
using namespace std;

class CheckingAccount : public Account{
protected:
    double Charge;
public:
    CheckingAccount(double b, double c);
    double credit(double amt) override;  
    double debit(double amt) override; 
};