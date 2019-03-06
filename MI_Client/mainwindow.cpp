#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(time,SIGNAL(timeout()),this,SLOT(timertimeout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{
    Network *auth = new Network;
    connect(auth,SIGNAL(onReady(Network *)),this,SLOT(OnResult(Network *)));
    auth->Get("http://"+ui->IPEdit->text()+":5555/auth.json"); // /?Data=456456&Data2=123123
    time->setInterval(5000);
    time->start();
}

void MainWindow::logShow()
{
    this->show();
}



void MainWindow::OnResult(Network *auth){
qDebug() << auth->GetAnswer();
qDebug() << auth->GetError();
if(auth->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << auth->GetError();
    } else {
    QJsonDocument JsonD = QJsonDocument::fromJson(auth->GetAnswer().toUtf8());
    QJsonObject JsonO = JsonD.object();
    QJsonArray JsonA=JsonO.value("Users").toArray();
    for(int i=0;i<JsonA.size();i++) {
        if(JsonA[i].toObject().value("login")==ui->LoginEdit->text())
            if(JsonA[i].toObject().value("password")==ui->PaswordEdit->text()){
                if(JsonA[i].toObject().value("role")=="Админ"){
                    time->stop();
                    admin = new Admin(ui->IPEdit->text());
                    connect(admin,SIGNAL(loginOpen()),this,SLOT(logShow()));
                    admin->show();
                    this->hide();
                } else {
                    if(JsonA[i].toObject().value("role")=="Портье"){
                        time->stop();
                        //portie = new Portie(ui->IPEdit->text());
                        //connect(admin,SIGNAL(loginOpen()),this,SLOT(logShow()));
                        //admin->show();
                        this->hide();
                    } else {
                        if(JsonA[i].toObject().value("role")=="Повар"){
                            time->stop();
                            cook = new Cook(ui->IPEdit->text());
                            connect(cook,SIGNAL(loginOpen()),this,SLOT(logShow()));
                            cook->show();
                        } else {
                            if(JsonA[i].toObject().value("role")=="Складовщик"){
                                time->stop();
                                whk = new Warehousekeeper(ui->IPEdit->text());
                                connect(whk,SIGNAL(loginOpen()),this,SLOT(logShow()));
                                whk->show();
                            } else {
                                QMessageBox::warning(this,"Ошибка!","Неопознанные права доступа!");
                            }
                        }
                    }
                }
            } else {
                QMessageBox::warning(this,"Ошибка!","Неверный логин или пароль!");
            }
    }
    }
}

void MainWindow::timertimeout(){
    time->stop();
    QMessageBox::warning(this,"Ошибка!","Время ожидания ответа от сервера истекло");
}

QLineEdit *MainWindow::IP()
{
    return ui->IPEdit;
}

void Cook::reseveip()
{
    //QString text = MainWindow->IP()->toPlainText();
    // do something with the text
}
