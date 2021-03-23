#include "change.h"
#include "ui_change.h"
#include<dialog.h>
#include<QMessageBox>
#include<QFile>
bool Change::ispassed=false;
Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
    ispassed=false;
}

Change::~Change()
{
    delete ui;
}

void Change::on_pushButton_2_clicked()
{
    close();
}

void Change::on_pushButton_clicked()
{
    if(ispassed==true)
    {
        Dialog::A_ID=ui->IDedit->text();
        Dialog::A_Password=ui->passwordedit->text();
        QFile A_account("account.dat");
        A_account.open(QIODevice::WriteOnly);
        QDataStream acc(&A_account);
        acc<<Dialog::A_ID<<Dialog::A_Password;
        QMessageBox::information(this,"information","修改成功");
        A_account.close();
        close();
    }
    else if(ui->IDedit->text()==Dialog::A_ID&&ui->passwordedit->text()==Dialog::A_Password)
    {
        QMessageBox::information(this,"information","验证通过");
        ispassed=true;
        A_change();
    }
    else
    {
        QMessageBox::information(this,"information","ID or Password Wrong");
    }
}
void Change::A_change()
{
    ui->IDedit->clear();
    ui->passwordedit->clear();
    QMessageBox::information(this,"information","请输入你要修改的账号密码");
}
