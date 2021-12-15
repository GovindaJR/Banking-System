#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include <string>
#include "savingsmenu.h"
#include "ui_savingsmenu.h"
#include"database.h"
#include"customermenu.h"

/*
This window opens the savings menu, that allows the user to view the interest rate on the account,
and withdraw or deposit money into the account.
*/

SavingsMenu::SavingsMenu(Customer customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SavingsMenu)
{
    ui->setupUi(this);
    Database db;
    // load current user's information from database
    db.load_user(customer);
    this->customer = customer;

    qDebug() << "Interest Rate is: " + QString::number(customer.savings_account.get_interest_rate());

    // loads current balance on screen during window setup; The balance is displayed with two decimals places.
    ui->balance_label->setText("Balance: $" + QString::number(customer.savings_account.get_balance(), 'f', 2));
    ui->interest_rate_label->setText("Interest Rate: " + QString::number(customer.savings_account.get_interest_rate(), 'f', 3) + "%");

}

SavingsMenu::~SavingsMenu()
{
    delete ui;
}

// This method is called when the user clicks "deposit" it deposits the entered value into the user's account.
void SavingsMenu::on_deposit_button_clicked()
{
    // gets the data from the spin box and deposits the entered amount.
    double entered_value = ui->doubleSpinBox->value();
    customer.savings_account.deposit(entered_value);


    Database db;

    QSqlQuery qry;

    QString id = QString::number(customer.get_id_number());

    // Updates the new balance in the database
    qry.prepare("UPDATE customer SET savings_balance='"+QString::number(customer.savings_account.get_balance())+"' WHERE PrimaryKey='"+id+"';");

    // Runs if the balance cannot be updated and logs error.
    if(!qry.exec()) {
        qDebug() << db.error();
        qDebug() << "Could not find user";
    }

    QMessageBox::information(this, "Successful Deposit", "You have sucessfully deposited $" +
                             QString::number(entered_value) + " into your Savings Account!");

    // closes window and returns to customer menu.
    close();

    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();
}


// This method is called when the user clicks "withdraws" it deposits the entered value into the
// user's checking account.
void SavingsMenu::on_withdraw_button_clicked()
{
    // gets the data from the spin box and withdraws the entered amount.
    double entered_value = ui->doubleSpinBox->value();
    customer.savings_account.withdraw(entered_value);

    Database db;

    QSqlQuery qry;

    QString id = QString::number(customer.get_id_number());

    // Updates the new balance in the database
    qry.prepare("UPDATE customer SET savings_balance='"+QString::number(customer.savings_account.get_balance())+"' WHERE PrimaryKey='"+id+"';");

    // Runs if update failed and logs the error.
    if(!qry.exec()) {
        qDebug() << db.error();
        qDebug() << "Could not find user";
    }


    QMessageBox::information(this, "Successful Withdrawl", "You have sucessfully withdrawn $" +
                             QString::number(entered_value) + " from your Savings Account!");

    // closes window and returns to customer menu.
    close();

    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();
}


void SavingsMenu::on_cancel_button_clicked()
{
    // closes window
    close();
    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();
}

