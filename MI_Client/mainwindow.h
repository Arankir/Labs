#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QTcpSocket>
#include <QMessageBox>
#include <cook.h>
#include <warehousekeeper.h>
#include <admin.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <myclient.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Cook* cook;
    Warehousekeeper* whk;
    Admin *admin;

signals:
    void onReady();

private slots:
    void on_Connect_clicked();
    void logShow();
    void Login(MyClient* client);
    void getData();
    void OnResult(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
