#include "mainwindow.h"
#include"dialog.h"
#include <QApplication>
#include<QMessageBox>
#include<QDebug>
#include<payment.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    //MainWindow w;
    d.exec();
   // w.show();
    return a.exec();
}
