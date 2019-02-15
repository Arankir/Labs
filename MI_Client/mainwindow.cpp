#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{
    if(ui->LoginEdit->text()=="root" && ui->PaswordEdit->text()=="1423"){
        cook = new Cook();
        cook->show(); // Делается не так, это временно. Потом через сигналы и слоты будет.
        this->hide();
    }
}
