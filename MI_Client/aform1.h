#ifndef AFORM1_H
#define AFORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class AForm1;
}

class AForm1 : public QWidget
{
    Q_OBJECT

public:
    explicit AForm1(QWidget *parent = nullptr);
    ~AForm1();
    void setDB(QSqlDatabase *db);

private slots:
    void on_Reg_clicked();

private:
    Ui::AForm1 *ui;
    QSqlDatabase* db;

};

#endif // AFORM1_H
