#ifndef CFORM3_H
#define CFORM3_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QPair>
#include <QLabel>
#include <QCheckBox>
#include <QFormLayout>
#include <QMessageBox>
#include <myclient.h>
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
    QVector <QPair<QString,int>> dishs;
    QVector <QCheckBox*> checks;
    QVector <QLabel*> menu;
    int id=0;
private slots:
    void chbChange(int state);
    void on_Cancel_clicked();
    void on_Applay_clicked();
    void dishRequest(MyClient* client);
    void idRequest(MyClient* client);
    void insertRequest(MyClient* client);
};

#endif // CFORM3_H
