#ifndef CFORM1_H
#define CFORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QCheckBox>
#include <QLayout>
#include <QLabel>
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
    QWidget* dish;
    QWidget* ingr;
    QGridLayout* ingLay;
private slots:
    void chbChange(int state);
};

#endif // CFORM1_H
