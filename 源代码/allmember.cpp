#include "allmember.h"
#include "ui_allmember.h"
#include<QTableWidget>
#include<QHeaderView>
#include<memberdialog.h>
#include<QDebug>
#include<QMessageBox>
int Allmember::row=0;
int Allmember::column=0;
int Allmember::number=0;
Allmember::Allmember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Allmember)
{
    ui->setupUi(this);

}
void Allmember::Add()
{
    if(number>7)
    {
        QMessageBox::information(this,"information","人数已满");
        return;
    }
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::name));
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::birthday));
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::sex));
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::age));
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::height));
    ui->tableWidget->setItem(row++,column,new QTableWidgetItem(MemberDialog::weight));
    column++;
    number++;
    row=0;
}
Allmember::~Allmember()
{
    delete ui;
}
void Allmember::deletemember(int i)
{
    for(int j=0;j<6;j++) ui->tableWidget->item(j,i)->setText("");
    //ui->tableWidget->removeColumn(i);
    while(i<number-1)
    {
    for(int j=0;j<6;j++) ui->tableWidget->item(j,i)->setText(ui->tableWidget->item(j,i+1)->text());
    i++;
    }
    for(int j=0;j<6;j++) ui->tableWidget->item(j,i)->setText("");
    column--;
    number--;
    if(column<0) column=0;
}
