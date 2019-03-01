#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::OnResult);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{

    QJsonArray data_arr;
    QJsonObject arr_obj;
    arr_obj["login"]=ui->LoginEdit->text();
    arr_obj["password"]=ui->PaswordEdit->text();
    data_arr.append(arr_obj);
    QJsonObject obj;
    obj["type"]="select";
    obj["request"]="login";
    obj["data"]=data_arr;
    QJsonDocument doc;
    doc.setObject(obj);
    QString request = QString(doc.toJson()).toLocal8Bit();


    MyClient* client = new MyClient;
    connect(client,SIGNAL(ClientReady(MyClient*)),this,SLOT(Login(MyClient*)));
    client->setRequest(request);

}

void MainWindow::logShow()
{
    this->show();
}

void MainWindow::Login(MyClient *client)
{
    qDebug() << client->answer;


    if(client->answer!="NO"){
        QString str = client->answer;
        QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject obj = doc.object();
        qDebug() << obj["position"].toString();

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
    else {
        QMessageBox::warning(this,"Ошибка","Введен неверный логин или пароль");
    }

}

void MainWindow::getData(){
QUrl url("127.0.0.1:5555/auth.json");
QNetworkRequest request;
request.setUrl(url);
manager->get(request);
}

void MainWindow::OnResult(QNetworkReply *reply){
if(reply->error()){
    qDebug() <<"Error";
    qDebug() << reply->errorString();
    } else {
    //QJsonObject *q;
    //emit onReady();
    }
}
