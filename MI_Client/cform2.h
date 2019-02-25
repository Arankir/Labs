#ifndef CFORM2_H
#define CFORM2_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <myclient.h>
namespace Ui {
class CForm2;
}

class CForm2 : public QWidget
{
    Q_OBJECT

public:
    explicit CForm2(QWidget *parent = nullptr);
    ~CForm2();
    void setDB(QSqlDatabase *db);

private slots:
    void on_Search_clicked();
    void ingredientsRequest(MyClient* client);

private:
    Ui::CForm2 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // CFORM2_H
