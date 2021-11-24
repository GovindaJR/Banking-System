#include "bankaccount.h"

// default constructor
BankAccount::BankAccount()
{
    balance = 0;
}

// getter
long double BankAccount::get_balance(){return balance;}

// setter
void BankAccount::set_balance(long double balance) {this->balance=balance;}
