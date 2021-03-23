#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QAction>
#include<QLineEdit>
#include<QDialog>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMessageBox>
#include<QDebug>
#include<memberdialog.h>
#include<payment.h>
#include<about.h>
#include<allmember.h>
#include<QFile>
#include "ui_allmember.h"
#include<change.h>
#include<income.h>
#include<dialog.h>
#include<QLabel>
#include<remove.h>
#include<accountdialog.h>
#include<searchpay.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
   // , ui(new Ui::MainWindow)
{
    QLineEdit *edit=new QLineEdit(this);
    edit->setText("欢迎来到家庭财务管理系统，详细功能请打开用户管理菜单栏！");
    QVBoxLayout *box=new QVBoxLayout(this);
    box->addWidget(edit);
    QWidget *center=new QWidget(this);
    this->setCentralWidget(center);
    center->setLayout(box);

    setWindowTitle(tr("家庭财务管理系统"));
    this->setFixedSize(500,400);

    saveAction = new QAction(tr("&Save"),this);
    saveAction->setShortcut(tr("ctrl+s"));
    saveAction->setStatusTip(tr("保存该财务管理表"));
   // saveAction->setStatusTip(tr("save changes"));
    connect(saveAction,&QAction::triggered,this,&MainWindow::save);

    loadAction=new QAction(tr("&Load"),this);
    loadAction->setShortcut(tr("ctrl+l"));
   // loadAction->setStatusTip(tr("读取财务管理表"));
    loadAction->setStatusTip(tr("load management"));
    connect(loadAction,&QAction::triggered,this,&MainWindow::load);

    addmemberAction=new QAction(tr("添加家庭成员"),this);
    addmemberAction->setStatusTip(tr("add new family member"));
    //addmemberAction->setStatusTip(tr("添加新家庭成员"));
    connect(addmemberAction,&QAction::triggered,this,&MainWindow::addmember);

    addpaymentAction=new QAction(tr("添加支出项目"));
    addpaymentAction->setStatusTip(tr("add payment items"));
   // addpaymentAction->setStatusTip(tr("添加支出项目"));
    connect(addpaymentAction,&QAction::triggered,this,&MainWindow::addpayment);

    showpayAction=new QAction(tr("打印收支"));
    showpayAction->setStatusTip(tr("show income and outcome"));
    connect(showpayAction,&QAction::triggered,this,&MainWindow::showpay);

    addincomeAction=new QAction(tr("添加收入项目"));
    addincomeAction->setStatusTip(tr("Add income item"));
    connect(addincomeAction,&QAction::triggered,this,&MainWindow::addincome);

    aboutAction=new QAction(tr("关于"));
    aboutAction->setStatusTip(tr("about the application"));
    connect(aboutAction,&QAction::triggered,this,&MainWindow::gethelp);

    showmemberAction=new QAction(tr("显示家庭成员"));
    showmemberAction->setStatusTip(tr("show all family members"));
    connect(showmemberAction,&QAction::triggered,this,&MainWindow::showmember);

    addnormalaccountAction=new QAction(tr("Add normal account"));
    addnormalaccountAction->setStatusTip(tr("add normal account"));
    connect(addnormalaccountAction,&QAction::triggered,this,&MainWindow::addaccount);

    deletememberAction=new QAction(tr("删除成员"));
    deletememberAction->setStatusTip(tr("delete a member"));
    connect(deletememberAction,&QAction::triggered,this,&MainWindow::Delete);

    changeIDAction=new QAction(tr("修改管理账号"));
    changeIDAction->setStatusTip("change administrator's ID or password");
    connect(changeIDAction,&QAction::triggered,this,&MainWindow::change);

    QMenu *filemenu=menuBar()->addMenu(tr("文件"));
    filemenu->addAction(saveAction);
    filemenu->addAction(loadAction);

    QMenu *managementmenu=menuBar()->addMenu(tr("用户管理"));
    managementmenu->addAction(addmemberAction);
    managementmenu->addAction(showmemberAction);
    managementmenu->addAction(deletememberAction);

    QMenu *paymentmenu=menuBar()->addMenu(tr("收支管理"));
    paymentmenu->addAction(addpaymentAction);
    paymentmenu->addAction(addincomeAction);
    paymentmenu->addAction(showpayAction);

    QMenu *accountmenu=menuBar()->addMenu(tr("账户管理"));
    accountmenu->addAction(changeIDAction);
    accountmenu->addAction(addnormalaccountAction);

    QMenu *helpmenu=menuBar()->addMenu(tr("帮助"));
    helpmenu->addAction(aboutAction);


    statusBar();
}
void MainWindow::load()
{
    int number;
    QString str1,str2,str3;
    QFile inFile("file.dat");
    inFile.open(QIODevice::ReadOnly);
    QDataStream in(&inFile);
    for(int i=0;i<8;i++)
    {
        in>>str1;
        in>>str2;
        Payment::Object[i]=str1;
        Payment::Pay[i]=str2;
    }

    QFile inFile2("file2.dat");
    inFile2.open(QIODevice::ReadOnly);
    QDataStream in2(&inFile2);
    in2>>number;
    for(int i=0;i<number;i++)
        for(int j=0;j<6;j++)
        {
            in2>>str3;
            allmember->ui->tableWidget->setItem(j,i,new QTableWidgetItem(str3));
            allmember->column=number;
            allmember->number=number;
        }

    QFile inFile3("file3.dat");
    inFile3.open(QIODevice::ReadOnly);
    QDataStream in3(&inFile3);
    Payment *temp2=new Payment;
    for(int i=0;i<3;i++) in3>>temp2->pa1->o1[i]>>temp2->pa1->c1[i];
    for(int i=0;i<3;i++) in3>>temp2->pa2->o2[i]>>temp2->pa2->c2[i];
    for(int i=0;i<3;i++) in3>>temp2->pa3->o3[i]>>temp2->pa3->c3[i];
    for(int i=0;i<3;i++) in3>>temp2->pa4->o4[i]>>temp2->pa4->c4[i];
    for(int i=0;i<3;i++) in3>>temp2->pa5->o5[i]>>temp2->pa5->c5[i];
    for(int i=0;i<3;i++) in3>>temp2->pa6->o6[i]>>temp2->pa6->c6[i];
    for(int i=0;i<3;i++) in3>>temp2->pa7->o7[i]>>temp2->pa7->c7[i];
    for(int i=0;i<3;i++) in3>>temp2->pa8->o8[i]>>temp2->pa8->c8[i];

    QFile inFile4("file4.dat");
    inFile4.open(QIODevice::ReadOnly);
    QDataStream in4(&inFile4);
    Income *income=new Income;
    for(int i=0;i<8;i++) in4>>income->item[i]>>income->income[i];

    inFile.close();
    inFile2.close();
    inFile3.close();
    inFile4.close();
}
void MainWindow::save()
{
    QString str;
    QFile outFile("file.dat");
    outFile.open(QIODevice::WriteOnly);
    QDataStream out(&outFile);
    for(int i=0;i<8;i++)
        out<<Payment::Object[i]<<Payment::Pay[i];

    QFile outFile2("file2.dat");
    outFile2.open(QIODevice::WriteOnly);
    QDataStream out2(&outFile2);
    out2<<allmember->number;
    for(int i=0;i<allmember->number;i++)
        for(int j=0;j<6;j++)
        {
            str=allmember->ui->tableWidget->item(j,i)->text();
            out2<<str;
        }

    QFile outFile3("file3.dat");
    outFile3.open(QIODevice::WriteOnly);
    QDataStream out3(&outFile3);
    Payment *temp=new Payment;
    for(int i=0;i<3;i++) out3<<temp->pa1->o1[i]<<temp->pa1->c1[i];
    for(int i=0;i<3;i++) out3<<temp->pa2->o2[i]<<temp->pa2->c2[i];
    for(int i=0;i<3;i++) out3<<temp->pa3->o3[i]<<temp->pa3->c3[i];
    for(int i=0;i<3;i++) out3<<temp->pa4->o4[i]<<temp->pa4->c4[i];
    for(int i=0;i<3;i++) out3<<temp->pa5->o5[i]<<temp->pa5->c5[i];
    for(int i=0;i<3;i++) out3<<temp->pa6->o6[i]<<temp->pa6->c6[i];
    for(int i=0;i<3;i++) out3<<temp->pa7->o7[i]<<temp->pa7->c7[i];
    for(int i=0;i<3;i++) out3<<temp->pa8->o8[i]<<temp->pa8->c8[i];

    QFile outFile4("file4.dat");
    outFile4.open(QIODevice::WriteOnly);
    QDataStream out4(&outFile4);
    Income *income=new Income;
    for(int i=0;i<8;i++) out4<<income->item[i]<<income->income[i];

    outFile.close();
    outFile2.close();
    outFile3.close();
    outFile4.close();
}
void MainWindow::addmember()
{
    MemberDialog *m=new MemberDialog;
    m->exec();
    if(MemberDialog::is_write==true)
        allmember->Add();

}
void MainWindow::showmember()
{
    allmember->show();

}
void MainWindow::Delete()
{
    Remove *r=new Remove;
    r->exec();
    allmember->deletemember(Remove::col);
}
void MainWindow::addpayment()
{
    Payment *p=new Payment;
    p->show();
}
void MainWindow::addincome()
{
    Income *i=new Income;
    i->show();
}
void MainWindow::showpay()
{
    QDialog *d=new QDialog;
    QPushButton *p1=new QPushButton(d);
    QPushButton *p2=new QPushButton(d);
    QPushButton *p3=new QPushButton(d);
    p1->setText(tr("收入情况"));
    p2->setText(tr("搜索支出"));
    p3->setText(tr("支出情况"));
    connect(p1,&QPushButton::clicked,this,&MainWindow::showincome);
    connect(p2,&QPushButton::clicked,this,&MainWindow::searchforpay);
    connect(p3,&QPushButton::clicked,this,&MainWindow::showallpay);
    QHBoxLayout *layout2=new QHBoxLayout(d);
    layout2->addWidget(p1);
    layout2->addWidget(p2);
    layout2->addWidget(p3);
    d->setLayout(layout2);
    d->exec();
}
MainWindow::~MainWindow()
{
   // delete ui;
}
void MainWindow::gethelp()
{
    About *help=new About;
    help->show();

}
void MainWindow::change()
{
    Change *c=new Change;
    c->show();

}
void MainWindow::addaccount()
{
    /*QPushButton *addaccountbutton_ok=new QPushButton("确定");
    QPushButton *addaccountbutton_exit=new QPushButton("返回");
    QDialog *addaccountdialog=new QDialog;
    QLabel *addaccountlabel=new QLabel("账号");
    QLabel *addpassword=new QLabel("密码");
    QLineEdit *addaccountedit=new QLineEdit;
    QLineEdit *addpasswordedit=new QLineEdit;
    QHBoxLayout *addaccountlayout=new QHBoxLayout;
    QHBoxLayout *addaccountlayout2=new QHBoxLayout;
    addaccountlayout->addWidget(addaccountlabel);
    addaccountlayout->addWidget(addaccountedit);
    addaccountlayout->addWidget(addaccountbutton_ok);
    addaccountlayout2->addWidget(addpassword);
    addaccountlayout2->addWidget(addpasswordedit);
    addaccountlayout2->addWidget(addaccountbutton_exit);
    QVBoxLayout *addaccountlayout3=new QVBoxLayout;
    addaccountlayout3->addLayout(addaccountlayout);
    addaccountlayout3->addLayout(addaccountlayout2);
    addaccountdialog->setLayout(addaccountlayout3);
    connect(addaccountbutton_ok,&QPushButton::clicked,this,&MainWindow::getaccount);
    addaccountdialog->exec();
    accountdialog *addaccountdialog=new accountdialog;
    addaccountdialog->exec();*/
    accountdialog *addaccountdialog=new accountdialog;
    addaccountdialog->exec();
    QFile accountfile("normalaccount.dat");
    accountfile.open(QIODevice::WriteOnly);
    QDataStream normalaccount(&accountfile);
    normalaccount<<accountdialog::normalID<<accountdialog::normalpassword;
    accountfile.close();
    addaccountdialog->close();
}
void MainWindow::showincome()
{
    double d=0;
    QString str;
    QDialog *allincome=new QDialog;
    QLabel *label=new QLabel;
    label->setText("所有收入总额");
    QLabel *in=new QLabel;
    Income *In=new Income;
    for(int i=0;i<8;i++) d+=In->income[i].toDouble();
    str=QString::number(d);
    in->setText(str);
    QLabel *l=new QLabel("yuan");
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(in);
    layout->addWidget(l);
    allincome->setLayout(layout);
    allincome->exec();
}
void MainWindow::searchforpay()
{
    Searchpay *searchdialog=new Searchpay;
    searchdialog->exec();
    Payment *searchpayment=new Payment;
    QLabel *resultlabel=new QLabel;
    QLabel *resultpayment=new QLabel;
    QHBoxLayout *searchlayout=new QHBoxLayout;
    QDialog *searchresult=new QDialog;
    QString str,str2;
    str=Searchpay::search;
    resultlabel->setText(Searchpay::search);
    for(int i=0;i<8;i++)
        if(str==Payment::Object[i])
        {
            str2=Payment::Pay[i];
        }
        for(int j=0;j<3;j++)
        {
        if(str==searchpayment->pa1->o1[j])
            str2=searchpayment->pa1->c1[j];
        }

        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa2->o2[j])
                str2=searchpayment->pa2->c2[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa3->o3[j])
                str2=searchpayment->pa3->c3[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa4->o4[j])
                str2=searchpayment->pa4->c4[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa5->o5[j])
                str2=searchpayment->pa5->c5[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa6->o6[j])
                str2=searchpayment->pa6->c6[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa6->o6[j])
                str2=searchpayment->pa6->c6[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa7->o7[j])
                str2=searchpayment->pa7->c7[j];
        }
        for(int j=0;j<3;j++)
        {
            if(str==searchpayment->pa8->o8[j])
                str2=searchpayment->pa8->c8[j];
        }
         resultpayment->setText(str2);
         searchlayout->addWidget(resultlabel);
         searchlayout->addWidget(resultpayment);
         searchresult->setLayout(searchlayout);
         searchresult->exec();
}
void MainWindow::showallpay()
{
    QDialog *showallpaydialog=new QDialog;
    double d=0;
    QString str;
    Payment *p2=new Payment;
    for(int i=0;i<8;i++) d+=p2->Pay[i].toDouble();
    str=QString::number(d);
    QLabel *allpaylabel=new QLabel;
    allpaylabel->setText("所有收入总额");
    QLabel *allpay=new QLabel;
    allpay->setText(str);
    QLabel *l2=new QLabel("yuan");
    QHBoxLayout *allpaylayout=new QHBoxLayout;
    allpaylayout->addWidget(allpaylabel);
    allpaylayout->addWidget(allpay);
    allpaylayout->addWidget(l2);
    showallpaydialog->setLayout(allpaylayout);
    showallpaydialog->exec();
}
void MainWindow::normalaccount()
{
    this->addmemberAction->setEnabled(false);
    this->showmemberAction->setEnabled(false);
    this->deletememberAction->setEnabled(false);
    this->changeIDAction->setEnabled(false);
    this->addnormalaccountAction->setEnabled(false);
}
