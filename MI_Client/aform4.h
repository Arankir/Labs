#ifndef AFORM4_H
#define AFORM4_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class AForm4;
}

class AForm4 : public QWidget
{
    Q_OBJECT

public:
    explicit AForm4(QWidget *parent = nullptr);
    ~AForm4();
    void setDB(QSqlDatabase *db);

private:
    Ui::AForm4 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // AFORM4_H
