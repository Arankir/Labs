#ifndef COOK_H
#define COOK_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QLayout>
#include <cform1.h>
#include <cform2.h>
#include <cform3.h>
#include <cform4.h>

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

signals:
    void loginOpen();

private slots:
    void on_whatchDish_clicked();

    void on_whatchIngredients_clicked();

    void on_Hide_clicked();

    void on_createMenu_clicked();

    void on_prevMenu_clicked();

    void on_LogOut_clicked();


private:
    Ui::Cook* ui;
    QSqlDatabase* db;
    CForm1* cform1;
    CForm2* cform2;
    cForm3* cform3;
    CForm4* cform4;
};

#endif // COOK_H
