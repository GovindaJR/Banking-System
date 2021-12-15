#include "checkingaccount.h"

// default constructor
CheckingAccount::CheckingAccount() {
    set_balance(0);
}

// methods
void CheckingAccount:: withdraw(double amount) {
    double new_balance = this->get_balance() - amount;
    this->set_balance(new_balance);
}

void CheckingAccount:: deposit(double amount) {
    double new_balance = this->get_balance() + amount;
    this->set_balance(new_balance);
}
