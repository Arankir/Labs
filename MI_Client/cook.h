#ifndef COOK_H
#define COOK_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QLayout>
#include <cform1.h>

namespace Ui {
class Cook;
}

class Cook : public QWidget
{
    Q_OBJECT

public:
    explicit Cook(QWidget *parent = nullptr);
    ~Cook();
    void setDB(QSqlDatabase *db);


private slots:
    void on_whatchDish_clicked();

private:
    Ui::Cook* ui;
    QSqlDatabase* db;
    CForm1* cform1;
};

#endif // COOK_H
