#pragma once
#include "user.h"
#include <iostream>


/**
Milestone 2:
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

class Customer : public User
{
    private:
        // fields
        int id_number;
        // checking account
        // saving account


    public:
        // constructrs:
        // default constructor
        Customer();
        // properties constructor
        Customer(int id);

        // getters
        int get_id_number();

        // setters
        void set_id_employee(int id);

        void show_details();
};
