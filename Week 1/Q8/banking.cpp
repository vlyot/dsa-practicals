#include <iostream>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<Account*> Accounts;
    Accounts.push_back(new CheckingAccount(10000, 50));  // Initial balance: 10000, fee: 50
    Accounts.push_back(new SavingsAccount(10000, 0.05)); // Initial balance: 10000, interest rate: 5%

    for (Account* a : Accounts) {
        double amt;

        // Withdrawal
        cout << "Specify amount to withdraw from account: ";
        cin >> amt;
        a->debit(amt);  

        // Deposit
        double amt2;
        cout << "Specify amount to deposit into account: ";
        cin >> amt2;
        a->credit(amt2);  

        if (SavingsAccount* savings = dynamic_cast<SavingsAccount*>(a)) {
            double interest = savings->calculateInterest();
            savings->credit(interest);
            savings->getbalance();
            cout<<endl;
        }

        // Print updated balance
        a->getbalance();
        cout<<'\n'<<"=================================="<<endl;
    }

    // Clean up dynamically allocated memory
    for (Account* a : Accounts) {
        delete a;
    }

    return 0;
}
