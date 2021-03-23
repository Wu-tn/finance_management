#include "dialog.h"
#include "ui_dialog.h"
#include<QString>
#include<QMessageBox>
#include<mainwindow.h>
#include<QMessageBox>
#include<QFile>
#include<QDebug>
QString Dialog::A_ID="20182131145";
QString Dialog::A_Password="123456";
QString Dialog::normal_ID[10]={""};
QString Dialog::normal_Password[10]={""};
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    int count=0;
    ui->setupUi(this);
    QMessageBox::information(this,"information","初始账号为 20182131145，初始密码为 123456");
    QFile acc_in("account.dat");
    acc_in.open(QIODevice::ReadOnly);
    if(acc_in.isOpen())
    {
    QDataStream ac_in(&acc_in);
    ac_in>>A_ID;
    ac_in>>A_Password;
    acc_in.close();
    }
    QFile normalaccount_in("normalaccount.dat");
    normalaccount_in.open(QIODevice::ReadOnly);
    if(normalaccount_in.isOpen())
    {
        QDataStream normalacc_in(&normalaccount_in);
        while(!normalacc_in.atEnd()||count>=10)
        {
            normalacc_in>>normal_ID[count];
            normalacc_in>>normal_Password[count];
            count++;
        }
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_exitbutton_clicked()
{
    close();
}
bool Dialog::signin(QString str1,QString str2)
{
    for(int i=0;i<10;i++)
    {
        if(str1==normal_ID[i]&&str2==normal_Password[i])
            return true;
    }
    return false;
}
void Dialog::on_okbutton_clicked()
{
    QString id=ui->IDedit->text();
    QString password=ui->passwordedit->text();
    if(id==""||password=="")
        QMessageBox::warning(this,"Warning","请输入正确的账号密码");
    else if(id==A_ID&&password==A_Password)
    {
        QMessageBox::information(this,"information","以管理员身份登录成功");
        MainWindow *w=new MainWindow;
        w->show();
        close();
    }
    else if(signin(id,password))
    {
                QMessageBox::information(this,"information",tr("sign in as normal account"));
                MainWindow *w=new MainWindow;
                w->normalaccount();
                w->show();
                close();
    }
    else
        QMessageBox::information(this,"information","ID or Password wrong");
}
