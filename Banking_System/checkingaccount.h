#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankaccount.h"

/**
Milestone 4:
Inheritance and subtyping are two important concepts in Object-Oriented Programming. Through inheritance,
classes can share code and override functions from the base class. The concept of subtyping is related to polymorphism
and is another way we can extend a class. A subtype can be created to be used in a context that expects a supertype. For
instance, lets say we have a base class called Automobile. Subtypes of this class could be truck, bus, or car,
where they can be used in a context where an automobile is neccessary. These subtypes can be related to
Automobile would be through inheritance, as these classes can be depicted as derived classes from Automobile.
*/


class CheckingAccount : public BankAccount
{
public:
    CheckingAccount();
    void withdraw(long double amount);
    void deposit(long double amount);
};

#endif // CHECKINGACCOUNT_H
