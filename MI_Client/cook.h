#ifndef COOK_H
#define COOK_H

#include <QWidget>

namespace Ui {
class Cook;
}

class Cook : public QWidget
{
    Q_OBJECT

public:
    explicit Cook(QWidget *parent = nullptr);
    ~Cook();

private:
    Ui::Cook *ui;
};

#endif // COOK_H
