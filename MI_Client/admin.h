#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <cook.h>
#include <warehousekeeper.h>
#include <portie.h>

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
    void on_Result_Show3_Dish(Network *);
    void on_Result_Show3_Ingredients(Network *);
    void on_Result_Show4(Network *);
    void on_Result_Show5(Network *);

    void on_A1BApply_clicked();

    void on_Result_Post_NewUser(Network *);

    void on_A2BApply_clicked();

    void on_Result_Post_NewIngredient(Network *);

    void on_A3chbIngredientPressed(int);

    void on_A3BApply_clicked();

    void on_Result_Post_NewDish(Network *);

signals:
    void loginOpen();

private:
    Ui::Admin *ui;
    Cook* cook;
    Warehousekeeper* whk;
    Portie* portie;
    QString IP;
    QList <QCheckBox*> LIngredients;

    QJsonDocument admin1;
    QJsonDocument admin2;
    QJsonDocument admin3dish;
    QJsonDocument admin3ingredient;
    QJsonDocument admin4;
    QJsonDocument admin5;
    QJsonDocument admin6;
};

#endif // ADMIN_H
