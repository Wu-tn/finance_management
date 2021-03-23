#ifndef DELETE_H
#define DELETE_H

#include <QWidget>

namespace Ui {
class Deletemember;
}

class Deletemember : public QWidget
{
    Q_OBJECT

public:
    explicit Deletemember(QWidget *parent = nullptr);
    ~Delete();

private:
    Ui::Deletemember *ui;
};

#endif // DELETE_H
