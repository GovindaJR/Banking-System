#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>

// This file only exists to demonstrate OOP Concepts for COP 3003 and does not affect the Banking System Program!

/**
Milestone 5:
An interface class is a class that has all pure virtual functions. Below is an implementation of an interface class.
Underneath the Interface class is a Derived class that has private members of that class.
*/


class Interface
{
public:
    virtual void method1() = 0;    // "= 0" part makes this method pure virtual, and
    virtual void method2() = 0;    // also makes this class abstract.
};

/**
Milestone 3 (LO3):
Dynamic dispatch is the process of selecting which implementation of a polymorphic method to call at run time.
To get dynamic dispatch one must declare a method as virtual using the "virtual" keyword. It tells the
program to go look and see if there are any more-derived versions of the function available, and runs
the most derived matching function.

Dynamic dispath is used in the Interface class, as seen from the use of the virtual keyword.
*/




class Derived : public Interface
{
    public:
    void method1() {std::cout<< "I can only get called because of the virtual keyword!\n";}
    void method2() {std::cout<< "I also can only get called because of the virtual keyword!\n";}
};

#endif // INTERFACE_H
