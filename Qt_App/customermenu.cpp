#include "customermenu.h"
#include "ui_customermenu.h"

CustomerMenu::CustomerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerMenu)
{
    ui->setupUi(this);
}

CustomerMenu::~CustomerMenu()
{
    delete ui;
}
