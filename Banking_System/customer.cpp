#include "customer.h"
#include<QDebug>

// default constructor

Customer::Customer(){};

Customer::Customer(std::string name, std::string email, std::string password, double checking_account_bal,
    double savings_account_bal, double interest_rate)
{
    this->set_name(name);
    this->set_email(email);
    this->set_password(password);
    this->checking_account.set_balance(checking_account_bal);
    this->savings_account.set_balance(savings_account_bal);
    this->savings_account.set_interest_rate(interest_rate);
}

Customer::Customer(std::string name, std::string email, std::string password) {
    this->set_name(name);
    this->set_email(email);
    this->set_password(password);
}

Customer::Customer(std::string email, std::string password) {
    this->set_email(email);
    this->set_password(password);
}


// getters
int Customer::get_id_number() { return id_number; }

// setters
void Customer::set_id_number(int id) {id_number = id;}


//
void Customer::show_details()
{
    qDebug() << "Customer name: "+  QString::fromStdString(get_name());
    qDebug() << "Customer id: " + QString::number(get_id_number());
    qDebug() << "Customer id: " + QString::number(this->checking_account.get_balance());
    qDebug() << "Customer id: " + QString::number(this->savings_account.get_balance());

}
