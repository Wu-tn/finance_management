#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = nullptr);
    static bool ispassed;
    ~Change();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Change *ui;
    void A_change();
};

#endif // CHANGE_H
