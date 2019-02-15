#ifndef COOK_H
#define COOK_H

#include <QWidget>

#include <QSqlDatabase>
#include <q123.h>
#include <QLayout>

namespace Ui {
class Cook;
}

class Cook : public QWidget
{
    Q_OBJECT

public:
    explicit Cook(QWidget *parent = nullptr);
    ~Cook();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Cook *ui;
    q123 *Form3;

};

#endif // COOK_H
