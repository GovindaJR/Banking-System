#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include"customer.h"

/*
This class holds the member and methods of the database class. A database object can be created and configured.
The database can open and close the connection, log errors, and load users.
*/

class Database
{
public:
    // members
    QSqlDatabase db;

    // default constructor
    Database();

    // class methods
    void configure();
    void close();
    QSqlError error();
    void load_user(Customer &customer);
    bool driver_available();
};


#endif // DATABASE_H
