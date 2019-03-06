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
    auth->SetUrl("http://"+ui->IPEdit->text()+":5555/auth.json"); // /?Data=456456&Data2=123123
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
                    admin = new Admin();
                    connect(admin,SIGNAL(loginOpen()),this,SLOT(logShow()));
                    admin->show();
                    this->hide();
                } else {
                    if(JsonA[i].toObject().value("role")=="Портье"){
                        //portie = new Portie();
                        //connect(admin,SIGNAL(loginOpen()),this,SLOT(logShow()));
                        //admin->show();
                        this->hide();
                    } else {
                        if(JsonA[i].toObject().value("role")=="Повар"){
                            cook = new Cook();
                            connect(cook,SIGNAL(loginOpen()),this,SLOT(logShow()));
                            cook->show();
                        } else {
                            if(JsonA[i].toObject().value("role")=="Складовщик"){
                                whk = new Warehousekeeper();
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
    QMessageBox::warning(this,"Ошибка!","Время ожидания ответа от сервера истекло");
    time->stop();
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
