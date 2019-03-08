#ifndef COOK_H
#define COOK_H

#include <QWidget>
#include <QDebug>
#include <QLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QFormLayout>
#include <QLabel>
#include <QVector>
#include <QPair>
#include <QMessageBox>
#include <QDate>
#include <network.h>
#include "QStandardItemModel"
#include "QStandardItem"

namespace Ui {
class Cook;
}

class Cook : public QWidget
{
    Q_OBJECT

public:
    explicit Cook(QString ip, QWidget *parent = nullptr);
    ~Cook();

signals:
    void loginOpen();
    void stateChanged(int state, Network *cook);

private:
   // QList <QRadioButton*> dishs;

private slots:
    void reseveip();
    void on_whatchDish_clicked();
    void on_whatchIngredients_clicked();
    void on_Hide_clicked();
    void on_createMenu_clicked();
    void on_prevMenu_clicked();
    void on_LogOut_clicked();

    void OnResultCook1(Network *);
    void OnResultCook2(Network *);
    void OnResultCook3(Network *);
    void OnResultCook4(Network *);
    void rbCook1Change();
    void chbCook3Change(int);

    void on_C2BSearch_clicked();

    void on_C4BSearch_clicked();

    void on_C3Date_userDateChanged(const QDate &date);

    void on_breakfast_clicked();

    void on_lunch_clicked();

    void on_dinner_clicked();

    void on_other_clicked();

    void on_C3BCancel_clicked();

    void on_C3BApply_clicked();

    void OnResultCook3Menu(Network *);

    void OnResultAddMenu(Network *);

    void on_C1LE_textChanged(const QString &arg1);

private:
    Ui::Cook *ui;
    QJsonDocument cook1;
    QJsonDocument cook2;
    QJsonDocument cook3;
    QJsonDocument cook4;
    QString IP;
    QString Typemenu="Завтрак";
    QList <QCheckBox*> Ldishs;
    QVector <QPair <QString,int>> Vingredient_stocks;
    QVector <QPair <QString,int>> VError;
};

#endif // COOK_H
