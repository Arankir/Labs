#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QTcpSocket>
#include <QMessageBox>
#include <cook.h>
#include <warehousekeeper.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //QTcpSocket* socket;
    //QByteArray data;
//public slots:
    //void sockReady();
    // sockDisc();
    Cook* cook;
    Warehousekeeper* whk;

private slots:
    void on_Connect_clicked();
    void logShow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
