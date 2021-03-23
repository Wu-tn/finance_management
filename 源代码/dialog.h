#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    static QString A_ID;
    static QString A_Password;
    static QString normal_ID[10];
    static QString normal_Password[10];
    bool signin(QString str1,QString str2);
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_exitbutton_clicked();

    void on_okbutton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
