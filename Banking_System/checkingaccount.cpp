#include "checkingaccount.h"

void CheckingAccount:: withdraw(long double amount) {
    long int new_balance = this->get_balance() - amount;
    this->set_balance(new_balance);
}

void CheckingAccount:: deposit(long double amount) {
    long int new_balance = this->get_balance() + amount;
    this->set_balance(new_balance);
}
