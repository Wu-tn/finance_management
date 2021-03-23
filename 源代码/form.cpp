#include "form.h"
#include "ui_form.h"
#include<QMessageBox>
#include<mainwindow.h>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QMessageBox::information(this,"information","初始账号为20182131145，初始密码为123456");
}

Form::~Form()
{
  //  delete ui;
}

void Form::on_exitbutton_clicked()
{
    close();
}

void Form::on_loginbutton_clicked()
{
    QString id=ui->IDedit->text();
    QString password=ui->passwordedit->text();
    if(id==ID&&password==Password)
    {
        QMessageBox::information(this,"information","登录成功");
        this->getpass();
        close();
    }
    else
        QMessageBox::information(this,"information","wrong");
}
void Form::getpass()
{
    this->Getpass=true;
}
