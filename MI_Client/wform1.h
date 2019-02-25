#ifndef WFORM1_H
#define WFORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class Wform1;
}

class Wform1 : public QWidget
{
    Q_OBJECT

public:
    explicit Wform1(QWidget *parent = nullptr);
    ~Wform1();
    void setDB(QSqlDatabase *db);

private slots:
    void on_ApplyStockChangeFilter_clicked();

    void on_RBAllDate_clicked();

    void on_RBBDate_clicked();

    void on_RBInDate_clicked();

    void on_RBADate_clicked();

    void on_RBAll_clicked();

    void on_RBInc_clicked();

    void on_RBDec_clicked();

private:
    Ui::Wform1 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
    int Date=1;
    int Ingr=1;
};

#endif // WFORM1_H
