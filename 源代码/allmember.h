#ifndef ALLMEMBER_H
#define ALLMEMBER_H

#include <QDialog>

namespace Ui {
class Allmember;
}

class Allmember : public QDialog
{
    Q_OBJECT

public:
    static int row;
    static int column;
    static int number;
    void Add();
    explicit Allmember(QWidget *parent = nullptr);
    ~Allmember();
    void expend();
    void deletemember(int i);

public:
    Ui::Allmember *ui;
};

#endif // ALLMEMBER_H
