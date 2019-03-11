#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <cook.h>
#include <warehousekeeper.h>
#include <portie.h>
#include <aform1.h>
#include <aform2.h>
#include <aform3.h>
#include <aform4.h>
namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QString ip, QWidget *parent = nullptr);
    ~Admin();
    void setDB(QSqlDatabase *db);

private slots:
    void on_LogOut_clicked();

    void on_Reg_clicked();

    void on_hide_clicked();

    void on_AddIng_clicked();

    void on_AddDish_clicked();

    void on_AddStock_clicked();

signals:
    void loginOpen();

private:
    Ui::Admin *ui;
    QSqlDatabase* db;
    Cook* cook;
    Warehousekeeper* whk;
    Portie* portie;
    QString IP;

    AForm1* aform1;
    AForm2* aform2;
    AForm3* aform3;
    AForm4* aform4;
};

#endif // ADMIN_H
