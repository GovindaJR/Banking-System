#include "savingsaccount.h"

// default constructor
SavingsAccount::SavingsAccount()  {
    set_balance(0);
    // average savings rate used as default
    // source: https://smartasset.com/checking-account/average-savings-account-interest#:~:text=According%20to%20the%20FDIC%2C%20the,accounts%20stands%20at%200.06%25%20APY
    interest_rate_percentage = 0.06;
}



SavingsAccount::SavingsAccount(double amount)
{
    set_balance(amount);
}

// getter
double SavingsAccount::get_interest_rate() { return interest_rate_percentage; }

// setter
void SavingsAccount::set_interest_rate(double rate) { interest_rate_percentage = rate; }

// saving account methods
void SavingsAccount::withdraw(double amount) { this->set_balance(this->get_balance() - amount); }
void SavingsAccount::deposit(double amount) { this->set_balance(this->get_balance() + amount); };
