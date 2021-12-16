#include<QSqlError>
#include<QMessageBox>
#include <string>
#include "customermenu.h"
#include "ui_customermenu.h"
#include"database.h"
#include"checkingmenu.h"
#include"savingsmenu.h"
#include"loginform.h"



CustomerMenu::CustomerMenu(Customer customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerMenu)
{
    ui->setupUi(this);

    Database db;

    // loads user from database
    db.load_user(customer);

    this->customer = customer;



    db.close();
    // Welcome label
    ui->welcome_label->setText("Welcome " + QString::fromStdString(customer.get_name()));

}

// Destructor
CustomerMenu::~CustomerMenu()
{
    delete ui;
}

// on click method that opens the checking account window
void CustomerMenu::on_checking_account_button_clicked()
{


    close();
    CheckingMenu checking_menu(customer);
    checking_menu.setModal(true);
    checking_menu.exec();



}


// on click method that opens the savings account window
void CustomerMenu::on_savings_account_button_clicked()
{
    close();
    SavingsMenu savings_menu(customer);
    savings_menu.setModal(true);
    savings_menu.exec();
}


// on click method that logs the user out
void CustomerMenu::on_logout_button_clicked()
{
    QMessageBox::information(this, "Successful Logout", "You have successfully logged out.");
    close();
    LoginForm login;
    login.setModal(true);
    login.exec();
}

