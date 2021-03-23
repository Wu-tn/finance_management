#ifndef INCOME_H
#define INCOME_H

#include <QWidget>

namespace Ui {
class Income;
}

class Income : public QWidget
{
    Q_OBJECT

public:
    static QString item[8];
    static QString income[8];
    explicit Income(QWidget *parent = nullptr);
    ~Income();

private slots:
    void on_exitbutton_clicked();

    void on_savebutton_clicked();

private:
    Ui::Income *ui;
};

#endif // INCOME_H
