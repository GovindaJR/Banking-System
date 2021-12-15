#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "bankaccount.h"

class SavingsAccount : public BankAccount
{
private:
    // make this interest_rate_percentage
    double interest_rate_percentage = .006;

public:
    SavingsAccount();
    SavingsAccount(double amount);
    void withdraw(double amount);
    void deposit(double amount);
    double get_interest_rate();
    void set_interest_rate(double rate);
};

#endif // SAVINGSACCOUNT_H
