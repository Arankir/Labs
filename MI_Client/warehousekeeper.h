#ifndef WAREHOUSEKEEPER_H
#define WAREHOUSEKEEPER_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QLayout>
#include <wform1.h>
#include <wform2.h>
#include <cform2.h>

namespace Ui {
class Warehousekeeper;
}

class Warehousekeeper : public QWidget
{
    Q_OBJECT

public:
    explicit Warehousekeeper(QWidget *parent = nullptr);
    ~Warehousekeeper();
    void setDB(QSqlDatabase *db);

signals:
    void loginOpen();

private slots:
    void on_LogOut_clicked();

    void on_Hide_clicked();

    void on_watchStock_clicked();

    void on_whatchStockChanges_clicked();

    void on_AddIngredients_clicked();

private:
    Ui::Warehousekeeper *ui;
    QSqlDatabase* db;
    CForm2* wform1;
    Wform1* wform2;
    Wform2* wform3;
};

#endif // WAREHOUSEKEEPER_H
