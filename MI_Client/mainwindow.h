#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <cook.h>
#include <warehousekeeper.h>
#include <portie.h>
#include <admin.h>
#include <network.h>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Cook *cook;
    Warehousekeeper *whk;
    Portie *portie;
    Admin *admin;
    QLineEdit *IP();

signals:
    void sendip(QString);

private slots:
    void on_Connect_clicked();
    void logShow();
    void OnResult(Network *auth);
    void timertimeout();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QTimer *time = new QTimer;
    QString ip;
};

#endif // MAINWINDOW_H
