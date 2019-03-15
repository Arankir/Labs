#include "portie.h"
#include "ui_portie.h"

Portie::Portie(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Portie)
{
    IP=ips;
    ui->setupUi(this);
    ui->P1DESettlementDate->setDate(QDate::currentDate());
    ui->P1DEEvictionDate->setDate(QDate::currentDate());
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
    hh.append("Паспорт");
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
        QJsonArray JA=portie.object().value("Data").toArray();
        QStandardItemModel *P1T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Паспорт");
        hh.append("Фамилия");
        hh.append("Имя");
        hh.append("Отчество");
        hh.append("Телефон");
        hh.append("Дата заезда");
        hh.append("Дата отъезда");
        P1T1M->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JA.size();i++){
            QStandardItem *Item0;
            Item0 = new QStandardItem(QString(JA[i].toObject().value("pasport").toString()));
            P1T1M->setItem(i,0,Item0);
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JA[i].toObject().value("second_name").toString()));
            P1T1M->setItem(i,1,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JA[i].toObject().value("first_name").toString()));
            P1T1M->setItem(i,2,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JA[i].toObject().value("patronymic").toString()));
            P1T1M->setItem(i,3,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JA[i].toObject().value("telephone").toString()));
            P1T1M->setItem(i,4,Item4);
            QStandardItem *Item5;
            Item5 = new QStandardItem(QString(JA[i].toObject().value("settlement_date").toString()));
            P1T1M->setItem(i,5,Item5);
            QStandardItem *Item6;
            Item6 = new QStandardItem(QString(JA[i].toObject().value("eviction_date").toString()));
            P1T1M->setItem(i,6,Item6);
        }
        ui->P1TVGuests->setModel(P1T1M);
        ui->P1TVGuests->resizeRowsToContents();
        ui->P1TVGuests->resizeColumnsToContents();
    }
}

void Portie::on_P1ButtonAccept_clicked()
{

    TitleFunc FPasport=&FilterInvoice::IngredientEmpty;
    TitleFunc FSName=&FilterInvoice::IngredientEmpty;
    TitleFunc FFName=&FilterInvoice::IngredientEmpty;
    TitleFunc FPatron=&FilterInvoice::IngredientEmpty;
    TitleFunc FTelephone=&FilterInvoice::IngredientEmpty;
    DateFunc FSDate=&FilterInvoice::DateAll;
    DateFunc FEDate=&FilterInvoice::DateAll;
    FilterInvoice FI;
    if(ui->P1LEPasport->text()!="")
        FPasport=&FilterInvoice::IngredientTitle;
    if(ui->P1LESecondName->text()!="")
        FSName=&FilterInvoice::IngredientTitle;
    if(ui->P1LEFirstName->text()!="")
        FFName=&FilterInvoice::IngredientTitle;
    if(ui->P1LEPatronymic->text()!="")
        FPatron=&FilterInvoice::IngredientTitle;
    if(ui->P1LETelephone->text()!="")
        FTelephone=&FilterInvoice::IngredientTitle;
    if(ui->P1RBSettlementDateBefore->isChecked())
        FSDate=&FilterInvoice::DateBefore; else
        if(ui->P1RBSettlementDateIn->isChecked())
            FSDate=&FilterInvoice::DateIn; else
            if(ui->P1RBSettlementDateAfter->isChecked())
                FSDate=&FilterInvoice::DateAfter;
    if(ui->P1RBEvictionDateBefore->isChecked())
        FEDate=&FilterInvoice::DateBefore; else
        if(ui->P1RBEvictionDateIn->isChecked())
            FEDate=&FilterInvoice::DateIn; else
            if(ui->P1RBEvictionDateAfter->isChecked())
                FEDate=&FilterInvoice::DateAfter;


    QJsonArray JA=portie.object().value("Data").toArray();
    QStandardItemModel *P1T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Паспорт");
    hh.append("Фамилия");
    hh.append("Имя");
    hh.append("Отчество");
    hh.append("Телефон");
    hh.append("Дата заезда");
    hh.append("Дата отъезда");
    P1T1M->setHorizontalHeaderLabels(hh);
    int k=0;
    for(int i=0;i<JA.size();i++){
        if((FI.*FPasport)(JA[i].toObject().value("pasport").toString(),ui->P1LEPasport->text())&&(FI.*FSName)(JA[i].toObject().value("second_name").toString(),ui->P1LESecondName->text())&&(FI.*FFName)(JA[i].toObject().value("first_name").toString(),ui->P1LEFirstName->text())&&(FI.*FPatron)(JA[i].toObject().value("patronymic").toString(),ui->P1LEPatronymic->text())&&(FI.*FTelephone)(JA[i].toObject().value("telephone").toString(),ui->P1LETelephone->text())&&(FI.*FSDate)(JA[i].toObject().value("settlement_date").toString(),ui->P1DESettlementDate->text())&&(FI.*FEDate)(JA[i].toObject().value("eviction_date").toString(),ui->P1DEEvictionDate->text())){
        QStandardItem *Item0;
        Item0 = new QStandardItem(QString(JA[i].toObject().value("pasport").toString()));
        P1T1M->setItem(k,0,Item0);
        QStandardItem *Item1;
        Item1 = new QStandardItem(QString(JA[i].toObject().value("second_name").toString()));
        P1T1M->setItem(k,1,Item1);
        QStandardItem *Item2;
        Item2 = new QStandardItem(QString(JA[i].toObject().value("first_name").toString()));
        P1T1M->setItem(k,2,Item2);
        QStandardItem *Item3;
        Item3 = new QStandardItem(QString(JA[i].toObject().value("patronymic").toString()));
        P1T1M->setItem(k,3,Item3);
        QStandardItem *Item4;
        Item4 = new QStandardItem(QString(JA[i].toObject().value("telephone").toString()));
        P1T1M->setItem(k,4,Item4);
        QStandardItem *Item5;
        Item5 = new QStandardItem(QString(JA[i].toObject().value("settlement_date").toString()));
        P1T1M->setItem(k,5,Item5);
        QStandardItem *Item6;
        Item6 = new QStandardItem(QString(JA[i].toObject().value("eviction_date").toString()));
        P1T1M->setItem(k,6,Item6);
        k++;
    }
    ui->P1TVGuests->setModel(P1T1M);
    ui->P1TVGuests->resizeRowsToContents();
    ui->P1TVGuests->resizeColumnsToContents();
}
}

void Portie::on_P2ButtonApply_clicked()
{
    //url: /newguest.json
    //формат: {"pasport":" " , "second_name":" ", "first_name":" ", "patronymic":" " , "telephone":" ", "settlement_date":" ", "eviction_date":" "}
        if(ui->W3LEInvoice->text()!=""){
            bool accept=true;
            for (int i=0;i<JAInv.size();i++) {
                if(JAInv[i].toObject().value("id").toString()==ui->W3LEInvoice->text()){
                    accept=false;
                    break;
                    }
                }
            if(accept){
                if(LIngredients.size()!=0){
                    for (int i=0;i<LIngredients.size();i++) {
                        if(findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text()=="")
                            accept=false;
                        }
                    if(accept){
                        QJsonObject post;
                        post["date"]=ui->W3DEDate->text();
                        post["stock"]=ui->W3CBStocks->currentText();
                        post["id"]=ui->W3LEInvoice->text();
                        QJsonArray ingredients;
                        for (int i=0;i<LIngredients.size();i++) {
                            QJsonObject ingredient;
                            ingredient["title"]=LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5);
                            ingredient["amount"]=findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text().toInt();
                            ingredients.append(ingredient);
                        }
                        post["ingredients"]=ingredients;
                        QJsonDocument doc;
                        doc.setObject(post);
                        qDebug() << doc;
                        Network *net = new Network;
                        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_ResultAddInvoice(Network *)));
                        net->Post("http://"+IP+":5555/addinvoice.json", doc);
                    } else
                        QMessageBox::warning(this,"Ошибка!","Поля с количеством ингредиентов не могут быть пустыми!");
                } else
                    QMessageBox::warning(this,"Ошибка!","Выберите продукты!");
            } else
                QMessageBox::warning(this,"Ошибка!","Накладная с таким номером уже существует!");
        } else
            QMessageBox::warning(this,"Ошибка!","Введите номер накладной!");
}
