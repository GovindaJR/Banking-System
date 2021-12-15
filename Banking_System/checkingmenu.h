#ifndef CHECKINGMENU_H
#define CHECKINGMENU_H

#include <QDialog>
#include"customer.h"

namespace Ui {
class CheckingMenu;
}

class CheckingMenu : public QDialog
{
    Q_OBJECT

public:
    // constructor takes a customer object to load.
    explicit CheckingMenu(Customer customer, QWidget *parent = nullptr);
    ~CheckingMenu();

private slots:
    // on click methods
    void on_deposit_button_clicked();

    void on_withdraw_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::CheckingMenu *ui;

public:
    Customer customer;
};

#endif // CHECKINGMENU_H
