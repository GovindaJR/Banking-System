#include "bankaccount.h"
#include<cmath>

// default constructor
BankAccount::BankAccount()
{
    balance = 0;
}

// getter
double BankAccount::get_balance(){
    return balance;
}

// setter
void BankAccount::set_balance(double balance) {this->balance=balance;}
