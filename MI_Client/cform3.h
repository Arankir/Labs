#ifndef CFORM3_H
#define CFORM3_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class cForm3;
}

class cForm3 : public QWidget
{
    Q_OBJECT

public:
    explicit cForm3(QWidget *parent = nullptr);
    ~cForm3();
    void setDB(QSqlDatabase *db);

private:
    Ui::cForm3 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // CFORM3_H
