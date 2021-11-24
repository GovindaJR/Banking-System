#include <QMessageBox>
#include "registerform.h"
#include "ui_registerform.h"
#include "customermenu.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}



void RegisterForm::on_register_button_clicked()
{
    QString email_form = ui->email_form->text();
    // use this same code to make variables for full name and password
    // also remember to set up password edit text to a password field.


    if (email_form == "") {
        QMessageBox::critical(this, "Incorrect Credentials", "Incorrect Info Entered. Please try again!");
        // handle error checking
    }
    else {
        close();
        CustomerMenu customer_menu;
        customer_menu.setModal(true);
        customer_menu.exec();
    }

}

