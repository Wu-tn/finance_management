#include "deletemember.h"
#include "ui_deletemember.h"

Deletmembere::Deletemember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Deletemember::~Deletemember
{
    delete ui;
}
