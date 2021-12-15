#ifndef SAVINGSMENU_H
#define SAVINGSMENU_H

#include <QDialog>
#include"customer.h"

namespace Ui {
class SavingsMenu;
}

class SavingsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SavingsMenu(Customer customer, QWidget *parent = nullptr);
    ~SavingsMenu();

private:
    Ui::SavingsMenu *ui;

public:
    Customer customer;
private slots:
    void on_deposit_button_clicked();
    void on_withdraw_button_clicked();
    void on_cancel_button_clicked();
};

#endif // SAVINGSMENU_H
