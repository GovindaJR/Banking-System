#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


class BankAccount
{
private:
    // private member
    long double balance;
public:
    // default constructors
    BankAccount();

    // getter
    long double get_balance();

   // setter
    void set_balance(long double balance);
};

#endif // BANKACCOUNT_H
