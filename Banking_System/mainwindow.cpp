#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerform.h"
#include "loginform.h"

/*
This file creates the main window that is called at the beginning of the application.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// This is a destructor, an instance member function which is invoked when an object is going to be destroyed.
MainWindow::~MainWindow()
{
    delete ui;
}



// This function is called when the user clicks the "New User" button.
// It directs them to the register page.

void MainWindow::on_new_user_button_clicked()
{

    // close current window
    close();

    // create register_form object and execute it.
    RegisterForm register_form;
    register_form.setModal(true);
    register_form.exec();

}


// This function is called when the user clicks the "Existing User" button.
// It directs them to the login page.

void MainWindow::on_existing_user_button_clicked()
{
    // close current window
    close();

    // create register_form object and execute it.
    LoginForm login_form;
    login_form.setModal(true);
    login_form.exec();

}

