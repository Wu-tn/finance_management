#include "income.h"
#include "ui_income.h"
#include<QMessageBox>
#include<QDoubleValidator>
QString Income::item[8]={"","","","","","","",""};
QString Income::income[8]={"","","","","","","",""};
Income::Income(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Income)
{
    ui->setupUi(this);
    ui->costedit->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_2->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_3->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_4->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_5->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_6->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_7->setValidator(new QDoubleValidator(0,99999999.999,3,this));
    ui->costedit_8->setValidator(new QDoubleValidator(0,99999999.999,3,this));

    ui->objectedit->setText(item[0]);ui->costedit->setText(income[0]);
    ui->objectedit_2->setText(item[1]);ui->costedit_2->setText(income[1]);
    ui->objectedit_3->setText(item[2]);ui->costedit_3->setText(income[2]);
    ui->objectedit_4->setText(item[3]);ui->costedit_4->setText(income[3]);
    ui->objectedit_5->setText(item[4]);ui->costedit_5->setText(income[4]);
    ui->objectedit_6->setText(item[5]);ui->costedit_6->setText(income[5]);
    ui->objectedit_7->setText(item[6]);ui->costedit_7->setText(income[6]);
    ui->objectedit_8->setText(item[7]);ui->costedit_8->setText(income[7]);
}

Income::~Income()
{
    delete ui;
}

void Income::on_exitbutton_clicked()
{
    close();
}

void Income::on_savebutton_clicked()
{
    item[0]=ui->objectedit->text();income[0]=ui->costedit->text();
    item[1]=ui->objectedit_2->text();income[1]=ui->costedit_2->text();
    item[2]=ui->objectedit_3->text();income[2]=ui->costedit_3->text();
    item[3]=ui->objectedit_4->text();income[3]=ui->costedit_4->text();
    item[4]=ui->objectedit_5->text();income[4]=ui->costedit_5->text();
    item[5]=ui->objectedit_6->text();income[5]=ui->costedit_6->text();
    item[6]=ui->objectedit_7->text();income[6]=ui->costedit_7->text();
    item[7]=ui->objectedit_8->text();income[7]=ui->costedit_8->text();
    QMessageBox::information(this,"information","保存成功");
    close();
}
