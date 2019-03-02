#ifndef CFORM1_H
#define CFORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QVector>
#include <network.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
namespace Ui {
class CForm1;
}

class CForm1 : public QWidget
{
    Q_OBJECT

public:
    explicit CForm1(QWidget *parent = nullptr);
    ~CForm1();
    void setDB(QSqlDatabase *db);
private:
    Ui::CForm1 *ui;
    QSqlDatabase *db;
    QNetworkAccessManager *manager;
    QVector <QPair <QPair <QString,int>,QString>> ingredients;
    bool add =1;
private slots:
    void chbChange(int state);
    //void dishRequest(MyClient* dishReq);
    //void ingrRequest(MyClient* ingrReq);
    //void countRequest(MyClient* countReq);
};

#endif // CFORM1_H
