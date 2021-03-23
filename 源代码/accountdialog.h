#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class accountdialog;
}

class accountdialog : public QDialog
{
    Q_OBJECT

public:
    static QString normalID;
    static QString normalpassword;
    explicit accountdialog(QWidget *parent = nullptr);
    ~accountdialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::accountdialog *ui;
};

#endif // ACCOUNTDIALOG_H
