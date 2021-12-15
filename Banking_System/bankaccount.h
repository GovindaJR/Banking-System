#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

/*
This class bank account class that holds a balance attribute with a getter and setter. It is a
parent class for SavingsAccount and CheckingAccount.
*/
class BankAccount
{
private:
    // private member
    double balance;
public:
    // default constructors
    BankAccount();

    // getter
    double get_balance();

   // setter
    void set_balance(double balance);
};

#endif // BANKACCOUNT_H
