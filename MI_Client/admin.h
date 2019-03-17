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

private slots:
    void on_LogOut_clicked();

    void on_Hide_clicked();

    void on_ABShow1_clicked();

    void on_ABShow2_clicked();

    void on_ABShow3_clicked();

    void on_ABShow4_clicked();

    void on_ABShow5_clicked();

    void on_ABShow6_clicked();

    void on_Result_Show1(Network *);
    void on_Result_Show2(Network *);
    void on_Result_Show3(Network *);
    void on_Result_Show4(Network *);
    void on_Result_Show5(Network *);

    void on_A1BApply_clicked();

    void on_Result_Post_NewUser(Network *);

    void on_A2BApply_clicked();

    void on_Result_Post_NewIngredient(Network *);

signals:
    void loginOpen();

private:
    Ui::Admin *ui;
    Cook* cook;
    Warehousekeeper* whk;
    Portie* portie;
    QString IP;

    QJsonDocument admin1;
    QJsonDocument admin2;
    QJsonDocument admin3;
    QJsonDocument admin4;
    QJsonDocument admin5;
    QJsonDocument admin6;
};

#endif // ADMIN_H
