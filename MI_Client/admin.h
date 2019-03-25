#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <cook.h>
#include <warehousekeeper.h>
#include <portie.h>
#include <QLineEdit>
#include <QTimer>

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

    void on_A4BApply_clicked();
    void on_Result_Post_NewStock(Network *);

    void on_A5TV_clicked(const QModelIndex &index);
    void on_A5BApply_clicked();
    void on_Result_Post_UpdateNeedOnStock(Network *);

    void on_Result_Show6auth(Network *);
    void on_Result_Show6dish(Network *);
    void on_Result_Show6guests(Network *);
    void on_Result_Show6ingredients(Network *);
    void on_Result_Show6ingredients_dish(Network *);
    void on_Result_Show6ingredients_stock(Network *);
    void on_Result_Show6invoice(Network *);
    void on_Result_Show6invoice_stock(Network *);
    void on_Result_Show6menu(Network *);
    void on_Result_Show6menu_dish(Network *);
    void on_Result_Show6role(Network *);
    void on_Result_Show6stock(Network *);
    void on_Result_Show6type_menu(Network *);

    void DBTableEditing(bool,bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool);
    void DBTableCreate(bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool,QString,bool);

    void on_A6RBauth_clicked();
    void on_A6RBdish_clicked();
    void on_A6RBguests_clicked();
    void on_A6RBingredients_clicked();
    void on_A6RBingredients_dish_clicked();
    void on_A6RBingredients_stock_clicked();
    void on_A6RBinvoice_clicked();
    void on_A6RBinvoice_stock_clicked();
    void on_A6RBmenu_clicked();
    void on_A6RBmenu_dish_clicked();
    void on_A6RBrole_clicked();
    void on_A6RBstock_clicked();
    void on_A6RBtype_menu_clicked();

    void on_A6TV_clicked(const QModelIndex &index);

    void on_A6BI1_clicked();
    void on_A6BI2_clicked();
    void on_A6BI3_clicked();
    void on_A6BI4_clicked();
    void on_A6BI5_clicked();
    void on_A6BI6_clicked();
    void on_A6BI7_clicked();
    void on_A6BI8_clicked();
    void on_A6BI9_clicked();

    void on_Result_Post_UpdateDBEditing(Network *);
    void on_Result_Post_UpdateDBDelete(Network *);

    void on_A6HSB_sliderMoved(int position);

    void on_Result_DBEditing_case5_1(Network *);
    void on_Result_DBEditing_case5_2(Network *);
    void on_Result_DBEditing_case6_1(Network *);
    void on_Result_DBEditing_case6_2(Network *);
    void on_Result_DBEditing_case8_1(Network *);
    void on_Result_DBEditing_case8_2(Network *);
    void on_Result_DBEditing_case10_1(Network *);
    void on_Result_DBEditing_case10_2(Network *);

    void on_A6Help_clicked();

    void on_Result_DBCreate_case5_1(Network *);
    void on_Result_DBCreate_case5_2(Network *);
    void on_Result_DBCreate_case6_1(Network *);
    void on_Result_DBCreate_case6_2(Network *);
    void on_Result_DBCreate_case8_1(Network *);
    void on_Result_DBCreate_case8_2(Network *);
    void on_Result_DBCreate_case8_3(Network *);
    void on_Result_DBCreate_case10_1(Network *);
    void on_Result_DBCreate_case10_2(Network *);

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
    int SelectedTable=1;
    QModelIndex inn;
    bool ins=false;
};

#endif // ADMIN_H
