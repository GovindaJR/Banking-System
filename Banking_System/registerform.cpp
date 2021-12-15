#include <QMessageBox>
#include<QDebug>
#include "registerform.h"
#include "ui_registerform.h"
#include "customermenu.h"
#include"database.h"
#include"loginform.h"

/*
This file creates the register window that is allows the user to make a new account.
*/

RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);

}

// Destructor
RegisterForm::~RegisterForm()
{
    delete ui;
}

// This function is called when the user clicks "Register". It validates the form input and registers the user.

void RegisterForm::on_register_button_clicked()
{
    // Gets the text data entered in the forms as QString objects.
    QString email_form = ui->email_form->text();
    QString full_name_form = ui->full_name_form->text();
    QString password_form = ui->password_form->text();

    // create database object and configure the database
    Database db;
    db.configure();


    // creates query object
    QSqlQuery qry;


    // if there are incorrect inputs in the forms
    if (email_form == "" || full_name_form == "" || password_form == "" ) {
        QMessageBox::critical(this, "Incorrect Credentials", "Incorrect Info Entered. Please try again!");
        // handle error checking
    }

    // if there are valid inputs in the register form
    else {

        // adds user to database
        qry.prepare("INSERT INTO customer(name, email, password) VALUES(?, ?, ?)");
        qry.addBindValue(full_name_form);
        qry.addBindValue(email_form);
        qry.addBindValue(password_form);

        // runs if the user can't be added
        if(!qry.exec()) {
            qWarning() << "Table Insertion Failed\n";
        }


        // creates customer object
        Customer customer(full_name_form.toStdString(), email_form.toStdString(), password_form.toStdString());


        // closes current window and opens the customer main menu window
        QMessageBox::information(this, "Registration Sucessful", "You have successfully created an account!");
        this->close();

        // customer object is passed to the new window
        CustomerMenu customer_menu(customer);
        customer_menu.setModal(true);
        customer_menu.exec();
    }

}

// Closes current window and opens the Login page.
void RegisterForm::on_go_to_login_clicked()
{
    close();
    LoginForm login;
    login.setModal(true);
    login.exec();
}

