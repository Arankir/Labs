#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QTcpSocket>
#include <QMessageBox>
#include <cook.h>

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


private slots:
    void on_Connect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
