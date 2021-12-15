#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include "loginform.h"
#include "ui_loginform.h"
#include"database.h"
#include"customermenu.h"

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

}

// Destructor
LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_login_button_clicked()
{
   QString email_form =  ui->email_form->text();
   QString password_form = ui->password_form->text();

   Database db;
   db.configure();

   QSqlQuery qry;

   qry.prepare("SELECT * FROM customer WHERE email='"+email_form+"' and password='"+password_form + "';");

   if(!qry.exec()) {
       qDebug() << db.error();
       qDebug() << "Could not find user to login";
   }

   int count = 0;
   while(qry.next()) {
        count++;
    }
   if (count==1){
        QMessageBox::information(this, "Successful Login", "You have successfully logged in.");
        Customer customer(email_form.toStdString(), password_form.toStdString());
        this->close();

        // customer object is passed to the new window
        CustomerMenu customer_menu(customer);
        customer_menu.setModal(true);
        customer_menu.exec();

   }
   else {
       QMessageBox::critical(this, "Login Unsucessful", "Your login attempt was unsucessful. Please try again.");
   }

}





void LoginForm::on_pushButton_2_clicked()
{
    // close window
    close();

    // create register_form object and execute it.
    RegisterForm register_form;
    register_form.setModal(true);
    register_form.exec();

}

