#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H
#include <QDialog>
#include "customer.h"
#include"registerform.h"

namespace Ui {
class CustomerMenu;
}

class CustomerMenu : public QDialog
{
    Q_OBJECT


public:
    // takes customer object in its constructor to recieve customer data
    explicit CustomerMenu(Customer customer, QWidget *parent = nullptr);
    ~CustomerMenu();

private slots:
    // on click methods
    void on_checking_account_button_clicked();

    void on_savings_account_button_clicked();

    void on_logout_button_clicked();

private:
    Ui::CustomerMenu *ui;

public:
    Customer customer;

};

#endif // CUSTOMERMENU_H
