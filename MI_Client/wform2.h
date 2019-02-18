#ifndef WFORM2_H
#define WFORM2_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class Wform2;
}

class Wform2 : public QWidget
{
    Q_OBJECT

public:
    explicit Wform2(QWidget *parent = nullptr);
    ~Wform2();
    void setDB(QSqlDatabase *db);

private:
    Ui::Wform2 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // WFORM2_H
