#pragma once
#include "user.h"
#include <iostream>
#include"savingsaccount.h"
#include"checkingaccount.h"
#include <QString>
#include <QMetaType>


/**
Milestone 2 (LO2a):
Inheritance models an is-a relationship between classes. It involves a hierarchy where there is a base class with one
or more derived classes(and even those classes could become base classes). Objects created by derived classes can
acquire the attributes and behaviors from its base class. Inheritance allows us to avoid redefining the information
from the base class in our derived classes, and it makes it easier to modify all the derived classes by modifying
the base class.

The accessibility a derived class can have to the fields and methods of a base class is based on its visibility mode.
There are three possible modes: public, protected, and private. If not specified when creating a derived class, it is
public by default.

Public visibility mode means that the the public members and protected members of the base class
will  be inherited as public members and protected members respectively of the derived class.

Protected visibility mode means the public and protected members of the base class all become protected in the
derived class.

Private visibility mode means all public and protected members of the base class become private in the derived class.

*/

// LO2 & LO1a

class Customer : public User
{
private:
    // fields
    int id_number;


public:
    SavingsAccount savings_account;
    CheckingAccount checking_account;
    // constructers:
    // default constructor
    Customer();
    // properties constructor

    // LO1b
    Customer(int id);
    Customer(std::string  name, std::string email, std::string password, double savings_account_bal,
        double checking_account_bal, double interest_rate);

    Customer(std::string name, std::string email, std::string password);
    Customer(std::string email,std::string password );

    // getters
    int get_id_number();

    // setters
    void set_id_number(int id);

    void show_details();
};


