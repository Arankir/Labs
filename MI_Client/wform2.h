#ifndef WFORM2_H
#define WFORM2_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QCheckBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QMessageBox>

namespace Ui {
class Wform2;
}

class Wform2 : public QWidget
{
    Q_OBJECT

public:
    explicit Wform2(QWidget *parent = nullptr);
    ~Wform2();
    void setDB(QSqlDatabase *db);

private:
    Ui::Wform2 *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
    QList <QCheckBox*> ingredients;

private slots:
    void chbChange(int state);
    void on_pushButton_clicked();
};

#endif // WFORM2_H
