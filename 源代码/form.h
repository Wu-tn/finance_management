#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    bool Getpass;
    QString ID="20182131145";
    QString Password="123456";
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_exitbutton_clicked();

    void on_loginbutton_clicked();

private:
    Ui::Form *ui;
    void getpass();
};

#endif // FORM_H
