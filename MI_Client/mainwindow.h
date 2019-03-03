#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <cook.h>
#include <warehousekeeper.h>
#include <admin.h>
#include <network.h>

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

private slots:
    void on_Connect_clicked();
    void logShow();
    void OnResult(Network *auth);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
