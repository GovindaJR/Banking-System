#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>
#include "checkingmenu.h"
#include "ui_checkingmenu.h"
#include"database.h"
#include"customermenu.h"

CheckingMenu::CheckingMenu(Customer customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckingMenu)
{
    ui->setupUi(this);
    Database db;
    //db.configure();
    db.load_user(customer);
    this->customer = customer;

    ui->balance_label->setText("Balance: $" + QString::number(customer.checking_account.get_balance(), 'f', 2));

}


// Destructor
CheckingMenu::~CheckingMenu()
{
    delete ui;
}

void CheckingMenu::on_deposit_button_clicked()
{

    double entered_value = ui->doubleSpinBox->value();
    customer.checking_account.deposit(entered_value);



    Database db;
    //db.configure();

    QSqlQuery qry;

    QString id = QString::number(customer.get_id_number());


    qry.prepare("UPDATE customer SET checking_balance='"+QString::number(customer.checking_account.get_balance())+"' WHERE PrimaryKey='"+id+"';");

    if(!qry.exec()) {
        qDebug() << db.error();
        qDebug() << "Could not find user";
    }

    db.close();

    QMessageBox::information(this, "Successful Deposit", "You have successfully deposited $" +
                             QString::number(entered_value) + " into your Checking Account!");


    close();

    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();

}


void CheckingMenu::on_withdraw_button_clicked()
{
    double entered_value = ui->doubleSpinBox->value();
    customer.checking_account.withdraw(entered_value);



    Database db;
    //db.configure();

    QSqlQuery qry;

    QString id = QString::number(customer.get_id_number());


    qry.prepare("UPDATE customer SET checking_balance='"+QString::number(customer.checking_account.get_balance())+"' WHERE PrimaryKey='"+id+"';");

    if(!qry.exec()) {
        qDebug() << db.error();
        qDebug() << "Could not find user";
    }

    qry.prepare("INSERT INTO transactions(id, account, action, amount) VALUES(?, ?, ?, ?)");
    qry.addBindValue(QString::number(customer.get_id_number()));
    qry.addBindValue(QString::fromStdString("checking"));
    qry.addBindValue(QString::fromStdString("withdraw"));
    qry.addBindValue(QString::number(entered_value));

    if(!qry.exec()) {
        qDebug() << db.error();
        qDebug() << "Could not add transaction";
    }

    //db.close();

    QMessageBox::information(this, "Successful Withdrawl", "You have successfully withdrawn $" +
                             QString::number(entered_value) + " from your Checking Account!");

    close();

    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();
}


void CheckingMenu::on_cancel_button_clicked()
{
    close();
    CustomerMenu customermenu(customer);
    customermenu.setModal(true);
    customermenu.exec();
}

