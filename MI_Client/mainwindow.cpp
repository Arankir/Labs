#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("1423");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{
    QString position;
    if(db.open()){
        QString req = "SELECT position FROM pass WHERE login = '"+ui->LoginEdit->text()+"' AND password = '"+ui->PaswordEdit->text()+"'";
        QSqlQuery *qry = new QSqlQuery(db);
        qry->prepare(req);
        qry->exec();
        while(qry->next()){
             position = qry->record().value(0).toString();

        }
    }

    if(1/*position == "cook"*/){
        cook = new Cook();
        cook->show(); // Делается не так, это временно. Потом через сигналы и слоты будет.
        this->hide();
    }
}
