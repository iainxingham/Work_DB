#include "home.h"
#include "./ui_home.h"

Home::Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}


void Home::on_actionExit_triggered()
{
    qApp->quit();
}


void Home::on_actionDVLA_invoice_triggered()
{

}

