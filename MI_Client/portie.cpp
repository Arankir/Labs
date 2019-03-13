#include "portie.h"
#include "ui_portie.h"

Portie::Portie(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Portie)
{
    IP=ips;
    ui->setupUi(this);
    //ui->C3Date->setDate(QDate::currentDate());
    ui->GBP1->move(170,50);
    ui->GBP2->move(170,50);
    ui->GBP3->move(170,50);
    Portie::on_Hide_clicked();
}

Portie::~Portie()
{
    delete ui;
}

void Portie::on_Hide_clicked()
{
    ui->GBP1->setVisible(false);
    ui->GBP2->setVisible(false);
    ui->GBP3->setVisible(false);
    ui->Hide->setVisible(false);
}

void Portie::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}

void Portie::on_pushButton_2_clicked()
{
    QStandardItemModel *P1T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Фамилия");
    hh.append("Имя");
    hh.append("Отчество");
    hh.append("Телефон");
    hh.append("Дата заезда");
    hh.append("Дата отъезда");
    P1T1M->setHorizontalHeaderLabels(hh);
    ui->P1TVGuests->setModel(P1T1M);
    ui->P1TVGuests->resizeRowsToContents();
    Network *porties1 = new Network;
    connect(porties1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_networkPortie(Network *)));
    porties1->Get("http://"+IP+":5555/gueststable.json");
    Portie::on_Hide_clicked();
    ui->GBP1->setVisible(true);
    ui->Hide->setVisible(true);
}

void Portie::on_pushButton_3_clicked()
{
    Network *porties2 = new Network;
    connect(porties2,SIGNAL(onReady(Network *)),this,SLOT(on_Result_networkPortie(Network *)));
    porties2->Get("http://"+IP+":5555/gueststable.json");
    Portie::on_Hide_clicked();
    ui->GBP2->setVisible(true);
    ui->Hide->setVisible(true);
}

void Portie::on_pushButton_clicked()
{
    Network *porties3 = new Network;
    connect(porties3,SIGNAL(onReady(Network *)),this,SLOT(on_Result_networkPortie(Network *)));
    porties3->Get("http://"+IP+":5555/gueststable.json");
    Portie::on_Hide_clicked();
    ui->GBP3->setVisible(true);
    ui->Hide->setVisible(true);
}

void Portie::on_Result_networkPortie(Network *porties){
    qDebug() << porties->GetAnswer();
    if(porties->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << porties->GetError();
        } else {
        portie=QJsonDocument::fromJson(porties->GetAnswer().toUtf8());
        QJsonDocument JD=portie;
        QJsonArray JA=portie.array();
        QStandardItemModel *P1T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Фамилия");
        hh.append("Имя");
        hh.append("Отчество");
        hh.append("Телефон");
        hh.append("Дата заезда");
        hh.append("Дата отъезда");
        P1T1M->setHorizontalHeaderLabels(hh);
        QString Ing=ui->W1CB1->currentText();
        QString Stock=ui->W1CB2->currentText();
        int k=0;
        for(int i=0;i<JsonA.size();i++){
            if((Ing!="Не выбрано" ? JsonA[i].toObject().value("ingredient_title").toString()==Ing : JsonA[i].toObject().value("ingredient_title").toString()!="")&&(Stock!="Не выбрано" ? JsonA[i].toObject().value("stock_title").toString()==Stock : JsonA[i].toObject().value("stock_title").toString()!="")){
                QStandardItem *Item1;
                Item1 = new QStandardItem(QString(JsonA[i].toObject().value("stock_title").toString()));
                W1T1M->setItem(k,0,Item1);
                QStandardItem *Item2;
                Item2 = new QStandardItem(QString(JsonA[i].toObject().value("ingredient_title").toString()));
                W1T1M->setItem(k,1,Item2);
                QStandardItem *Item3;
                Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
                W1T1M->setItem(k,2,Item3);
                k++;
            }
        }
        ui->W1T1->setModel(W1T1M);
        ui->W1T1->resizeRowsToContents();
}
