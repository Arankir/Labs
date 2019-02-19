#ifndef AFORM2_H
#define AFORM2_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
namespace Ui {
class AForm2;
}

class AForm2 : public QWidget
{
    Q_OBJECT

public:
    explicit AForm2(QWidget *parent = nullptr);
    ~AForm2();
    void setDB(QSqlDatabase *db);
    void Refresh();

private slots:
    void on_Apply_clicked();

private:
    Ui::AForm2 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // AFORM2_H
