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
#include <QStringRef>

namespace Ui {
class Cook;
}

class Cook : public QWidget
{
    Q_OBJECT

public:
    explicit Cook(QWidget *parent = nullptr);
    ~Cook();

signals:
    void loginOpen();
    void stateChanged(int state, Network *cook);

private:
   // QList <QRadioButton*> dishs;

private slots:
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

    void on_search_clicked();

private:
    Ui::Cook *ui;
    QJsonDocument cook1;
    QJsonDocument cook2;
    QJsonDocument cook3;
    QJsonDocument cook4;
};

#endif // COOK_H
