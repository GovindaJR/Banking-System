#include "database.h"
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>

/*
This class controls the functionality for the database object.
*/

Database::Database()
{

}


void Database::configure() {
    // sets driver and tests if it is available
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)) {

        // creates database
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        // sets database location
        db.setDatabaseName("../BankingSystem/customer.db");

        // checks if its open
        if (!db.open()) {
            qWarning() << "Could not connect to DB\n";
           }
    }

}

void Database::close() {
    this->db.close();
}

QSqlError Database::error() {
   return this->db.lastError();
}

// This function queries the database and gets customer attributes from the database
void Database::load_user(Customer &customer) {

    // query object
    QSqlQuery qry;

    // email casted to a QString to query
    QString qemail = QString::fromStdString(customer.get_email());


    // find customer using email, email is used because if they just registered,
    // program does not have access to ID yet.
    qry.prepare("SELECT * FROM customer WHERE email='"+qemail+"';");

    // if the user is not found, log error
    if(!qry.exec()) {
        qDebug() << this->error();
        qDebug() << "Could not find row";
    }



    while(qry.next()) {
        Customer loaded_customer(
                    // load the customer's name, email, and password
                    qry.value(1).toString().toStdString(),
                    qry.value(2).toString().toStdString(),
                    qry.value(3).toString().toStdString());

        // the following attributes are loaded seperately from the constructor because
        // of a type conversion issue.

        // load the id
        int i = qry.value(0).toInt();
        customer.set_id_number(i);

        double checking, savings, interest;

        // load checking balance
        checking = qry.value(4).toDouble();
        customer.checking_account.set_balance(checking);

        // load saving balance
        savings = qry.value(5).toDouble();
        customer.savings_account.set_balance(savings);

        // load interest rate
        interest = qry.value(6).toDouble();
        customer.savings_account.set_interest_rate(interest);



    }
}


bool Database::driver_available(){
    return db.isDriverAvailable("QSQLITE");
}
