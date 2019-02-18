#ifndef WFORM1_H
#define WFORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>

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

private:
    Ui::Wform1 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // WFORM1_H
