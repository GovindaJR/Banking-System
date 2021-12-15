#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_login_button_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
