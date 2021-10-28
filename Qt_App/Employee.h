#pragma once
#include "User.h"
#include <iostream>


/**
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

class Employee : public User
{
    private:
        // fields
        int id_employee;
        std::string job_position;
        int yearly_salary;

    public:
        // constructrs:
        // default constructor
        Employee();
        // properties constructor
        Employee(int id, std::string position, int wage);

        // getters
        int get_id_employee();
        std::string get_job_position();
        int get_yearly_salary();

        // setters
        void set_id_employee(int id);
        void set_job_position(std::string position);
        void set_yearly_salary(int salary);

        void show_details();
};



