#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerform.h"
#include "loginform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_new_user_button_clicked()
{

    close();
    RegisterForm register_form;
    register_form.setModal(true);
    register_form.exec();



}




void MainWindow::on_existing_user_button_clicked()
{
    close();
    LoginForm login_form;
    login_form.setModal(true);
    login_form.exec();

}

