#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("sanatorii");
    db.setUserName("root");
    db.setPassword("12345");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{
    MyClient client;

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

//    if(1){
//        cook = new Cook();
//        connect(cook,SIGNAL(loginOpen()),this,SLOT(logShow()));
//        cook->setDB(&db);
//        cook->show();
//        this->hide();
//    }
//    if(1){
//        whk = new Warehousekeeper();
//        connect(whk,SIGNAL(loginOpen()),this,SLOT(logShow()));
//        whk->setDB(&db);
//        whk->show();
//        this->hide();
//    }
    if(1){
        admin = new Admin();
        connect(admin,SIGNAL(loginOpen()),this,SLOT(logShow()));
        admin->setDB(&db);
        admin->show();
        this->hide();
    }
}

void MainWindow::logShow()
{
    this->show();
}
