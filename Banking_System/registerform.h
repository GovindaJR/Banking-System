#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include<QMainWindow>
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include<customer.h>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlDriver>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();



private slots:
    // on click methods
    void on_register_button_clicked();

    void on_go_to_login_clicked();

private:
    Ui::RegisterForm *ui;
};

#endif // REGISTERFORM_H
