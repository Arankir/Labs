#ifndef WAREHOUSEKEEPER_H
#define WAREHOUSEKEEPER_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QSpacerItem>
#include <filterinvoice.h>

#include <network.h>
#include "QStandardItemModel"
#include "QStandardItem"

namespace Ui {
class Warehousekeeper;
}

class Warehousekeeper : public QWidget
{
    Q_OBJECT

private:
    typedef bool (Warehousekeeper::*Date) (int a, QString b);

public:
    explicit Warehousekeeper(QString ips, QWidget *parent = nullptr);
    ~Warehousekeeper();

signals:
    void loginOpen();

private slots:
    void on_LogOut_clicked();

    void on_Hide_clicked();

    void on_W1BSearch_clicked();

    void on_WhkButtonShowW1_clicked();
    void on_WhkButtonShowW2_clicked();
    void on_WhkButtonShowW3_clicked();
    void OnResultWhk1(Network *);
    void OnResultWhk2(Network *);
    void OnResultWhk3(Network *);

    void on_W2ButtonApply_clicked();

    void on_W2RBAllDate_clicked();

    void on_W2RBBeforeDate_clicked();

    void on_W2RBInDate_clicked();

    void on_W2RBAfterDate_clicked();

    void on_W2RBAllChanges_clicked();

    void on_W2RBIncChanges_clicked();

    void on_W2RBDecChanges_clicked();

    void on_W3chbPressed(int);

    void on_W3BApply_clicked();

    void on_ResultAddInvoice(Network *);

private:
    Ui::Warehousekeeper *ui;
    QJsonDocument whk1;
    QJsonDocument whk2;
    QJsonDocument whk3;
    QString IP;
    QList <QCheckBox*> LIngredients;
    typedef bool (FilterInvoice::*DateFunc)(QString a, QString b);
    DateFunc dat=&FilterInvoice::DateAll;
    typedef bool (FilterInvoice::*IngredientFunc)(int a);
    IngredientFunc ing=&FilterInvoice::IngredientAll;
    typedef bool (FilterInvoice::*IngTitleFunc)(QString a, QString b);
    IngTitleFunc tin=&FilterInvoice::IngredientEmpty;
    typedef bool (FilterInvoice::*InvoiceFunc)(QString a, QString b);
    InvoiceFunc inv=&FilterInvoice::InvoiceEmpty;
    typedef bool (FilterInvoice::*StockFunc)(QString a, QString b);
    StockFunc sto=&FilterInvoice::StockEmpty;
};

#endif // WAREHOUSEKEEPER_H
