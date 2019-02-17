#ifndef CFORM4_H
#define CFORM4_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QDate>
#include <QLayout>
#include <QLabel>
namespace Ui {
class CForm4;
}

class CForm4 : public QWidget
{
    Q_OBJECT

public:
    explicit CForm4(QWidget *parent = nullptr);
    ~CForm4();
    void setDB(QSqlDatabase *db);


private slots:
    void on_search_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::CForm4 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // CFORM4_H
