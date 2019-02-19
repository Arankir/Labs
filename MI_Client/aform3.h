#ifndef AFORM3_H
#define AFORM3_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
namespace Ui {
class AForm3;
}

class AForm3 : public QWidget
{
    Q_OBJECT

public:
    explicit AForm3(QWidget *parent = nullptr);
    ~AForm3();
    void setDB(QSqlDatabase *db);
    void Refresh();

private slots:
    void on_Apply_clicked();

private:
    Ui::AForm3 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
};

#endif // AFORM3_H
