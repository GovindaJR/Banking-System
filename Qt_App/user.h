#pragma once
#include<iostream>

/**
Milestone 1:

Functional vs Object-Oriented Approach:

Functional programming is typically easier to write. It can be useful for simple/small applications
but it can get messy with big application. It involves writing functions for each
operation the program does that provides a case of each data variant. Functinal programming may lead to the repetition
of code more often and the data is often unsecure.

Object-oriented programming is centered around classes and objects. The main parts of the object-oriented
paradigm are encapulation, inheritance, and polymorphism. A class is created as a blueprint to which we
create objects from those blueprints. A class contains data known as fields and can do certain operations known as
methods. It is more complex than functional programming, but it is easier for maintainability and sustainability.
It can be easier to read and if you need to change something in a class, it is relatively simple as changing a field
or method. It makes code more reuseable and can make data more secure.

*/



// Parent class
class User
{
    // Private Fields
    private:
        std::string name;
        std::string email;
        std::string password;

    public:
        // getters
        std::string get_name();
        std::string get_email();
        std::string get_password();

        // setters
        void set_name(std::string person_name);
        void set_email(std::string person_email);
        void set_password(std::string person_password);
};
