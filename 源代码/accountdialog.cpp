#include "accountdialog.h"
#include "ui_accountdialog.h"
QString accountdialog::normalID="";
QString accountdialog::normalpassword="";
#include<QMessageBox>
accountdialog::accountdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountdialog)
{
    ui->setupUi(this);
}

accountdialog::~accountdialog()
{
    delete ui;
}

void accountdialog::on_pushButton_2_clicked()
{
    close();
}

void accountdialog::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()=="")
        QMessageBox::warning(this,"Warning","ID or Password can not be empty!");
    else
    {
    normalID=ui->lineEdit->text();
    normalpassword=ui->lineEdit_2->text();
    }
}
