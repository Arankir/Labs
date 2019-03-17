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
    ui->P1TVGuests->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->P3TVGuests->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        QStandardItemModel *P3T1M = new QStandardItemModel;
        QStringList hh2;
        hh2.append("id");
        hh2.append("Паспорт");
        hh2.append("Фамилия");
        hh2.append("Имя");
        hh2.append("Отчество");
        hh2.append("Телефон");
        hh2.append("Дата заезда");
        hh2.append("Дата отъезда");
        P3T1M->setHorizontalHeaderLabels(hh2);
        for(int i=0;i<JA.size();i++){
            QStandardItem *Item;
            Item = new QStandardItem(QString(JA[i].toObject().value("id").toString()));
            P3T1M->setItem(i,0,Item);
            QStandardItem *Item0;
            Item0 = new QStandardItem(QString(JA[i].toObject().value("pasport").toString()));
            P3T1M->setItem(i,1,Item0);
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JA[i].toObject().value("second_name").toString()));
            P3T1M->setItem(i,2,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JA[i].toObject().value("first_name").toString()));
            P3T1M->setItem(i,3,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JA[i].toObject().value("patronymic").toString()));
            P3T1M->setItem(i,4,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JA[i].toObject().value("telephone").toString()));
            P3T1M->setItem(i,5,Item4);
            QStandardItem *Item5;
            Item5 = new QStandardItem(QString(JA[i].toObject().value("settlement_date").toString()));
            P3T1M->setItem(i,6,Item5);
            QStandardItem *Item6;
            Item6 = new QStandardItem(QString(JA[i].toObject().value("eviction_date").toString()));
            P3T1M->setItem(i,7,Item6);
        }
        ui->P3TVGuests->setModel(P3T1M);
        ui->P3TVGuests->resizeRowsToContents();
        ui->P3TVGuests->resizeColumnsToContents();
        ui->P3Lid->setGeometry(30,415,ui->P3TVGuests->columnWidth(0),20);
        ui->P3LPasport->setGeometry(ui->P3Lid->x()+ui->P3Lid->width(),415,ui->P3TVGuests->columnWidth(1),20);
        ui->P3LSecondName->setGeometry(ui->P3LPasport->x()+ui->P3LPasport->width(),415,ui->P3TVGuests->columnWidth(2),20);
        ui->P3LFirstName->setGeometry(ui->P3LSecondName->x()+ui->P3LSecondName->width(),415,ui->P3TVGuests->columnWidth(3),20);
        ui->P3LPatronymic->setGeometry(ui->P3LFirstName->x()+ui->P3LFirstName->width(),415,ui->P3TVGuests->columnWidth(4),20);
        ui->P3LTelephone->setGeometry(ui->P3LPatronymic->x()+ui->P3LPatronymic->width(),415,ui->P3TVGuests->columnWidth(5),20);
        ui->P3LSettlementDate->setGeometry(ui->P3LTelephone->x()+ui->P3LPatronymic->width()-20,415,ui->P3TVGuests->columnWidth(6),20);
        ui->P3LEvictionDate->setGeometry(ui->P3LSettlementDate->x()+ui->P3LSettlementDate->width(),415,ui->P3TVGuests->columnWidth(7),20);
        ui->P3LEid->setGeometry(30,435,ui->P3TVGuests->columnWidth(0),20);
        ui->P3LEPasport->setGeometry(ui->P3LEid->x()+ui->P3LEid->width(),435,ui->P3TVGuests->columnWidth(1),20);
        ui->P3LESecondName->setGeometry(ui->P3LEPasport->x()+ui->P3LEPasport->width(),435,ui->P3TVGuests->columnWidth(2),20);
        ui->P3LEFirstName->setGeometry(ui->P3LESecondName->x()+ui->P3LESecondName->width(),435,ui->P3TVGuests->columnWidth(3),20);
        ui->P3LEPatronymic->setGeometry(ui->P3LEFirstName->x()+ui->P3LEFirstName->width(),435,ui->P3TVGuests->columnWidth(4),20);
        ui->P3LETelephone->setGeometry(ui->P3LEPatronymic->x()+ui->P3LEPatronymic->width(),435,ui->P3TVGuests->columnWidth(5),20);
        ui->P3DESettlementDate->setGeometry(ui->P3LETelephone->x()+ui->P3LEPatronymic->width()-20,435,ui->P3TVGuests->columnWidth(6),20);
        ui->P3DEEvictionDate->setGeometry(ui->P3DESettlementDate->x()+ui->P3DESettlementDate->width(),435,ui->P3TVGuests->columnWidth(7),20);

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
    if(ui->P2LEPasport->text()!=""){
        if(ui->P2LESecondName->text()!=""){
            if(ui->P2LEFirstName->text()!=""){
                if(ui->P2LEPatronymic->text()!=""){
                    if(ui->P2CWSettlementDate->selectedDate()<ui->P2CWEvictionDate->selectedDate()){
                        if(ui->P2CWSettlementDate->selectedDate()>=QDate::currentDate()){
                            QJsonObject post;
                            post["pasport"]=ui->P2LEPasport->text();
                            post["second_name"]=ui->P2LESecondName->text();
                            post["first_name"]=ui->P2LEFirstName->text();
                            post["patronymic"]=ui->P2LEPatronymic->text();
                            post["telephone"]=ui->P2LETelephone->text();
                            post["settlement_date"]=ui->P2CWSettlementDate->selectedDate().toString("yyyy-MM-dd");
                            post["eviction_date"]=ui->P2CWEvictionDate->selectedDate().toString("yyyy-MM-dd");
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_ResultNewGuest(Network *)));
                            net->Post("http://"+IP+":5555/newguest.json", doc);
                            } else QMessageBox::warning(this,"Ошибка!","Дата заселения не может быть раньше текущего дня!");
                        } else QMessageBox::warning(this,"Ошибка!","Дата заселения не может быть позже даты отъезда!");
                    } else QMessageBox::warning(this,"Ошибка!","Введите отчество!");
                } else QMessageBox::warning(this,"Ошибка!","Введите Имя!");
            } else QMessageBox::warning(this,"Ошибка!","Введите Фамилию!");
        } else QMessageBox::warning(this,"Ошибка!","Введите паспорт!");
}

void Portie::on_ResultNewGuest(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Новый посетитель добавлен!");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить посетителя!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить посетителя! ("+a->GetAnswer()+")");
            }
        }
}

void Portie::on_P3TVGuests_clicked(const QModelIndex &index)
{
    ui->P3TVGuests->selectRow(index.row());
    QModelIndex in=ui->P3TVGuests->model()->index(index.row(),0);
    ui->P3LEid->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),1);
    ui->P3LEPasport->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),2);
    ui->P3LESecondName->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),3);
    ui->P3LEFirstName->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),4);
    ui->P3LEPatronymic->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),5);
    ui->P3LETelephone->setText(ui->P3TVGuests->model()->data(in).toString());
    in=ui->P3TVGuests->model()->index(index.row(),6);
    ui->P3DESettlementDate->setDate(ui->P3TVGuests->model()->data(in).toDate());
    in=ui->P3TVGuests->model()->index(index.row(),7);
    ui->P3DEEvictionDate->setDate(ui->P3TVGuests->model()->data(in).toDate());
}

void Portie::on_pushButton_4_clicked()
{
    Portie::on_P3TVGuests_clicked(ui->P3TVGuests->currentIndex());
}

void Portie::on_pushButton_5_clicked()
{
    //url: /updateguest.json
    //формат: {"id":"id","pasport":" ","second_name":" ","first_name":" ","patronymic":" ","telephone":" ","settlement_date":" ","eviction_date":" "}
    if(ui->P3LEPasport->text()!=""){
        if(ui->P3LESecondName->text()!=""){
            if(ui->P3LEFirstName->text()!=""){
                if(ui->P3LEPatronymic->text()!=""){
                    if(QDate::fromString(ui->P3DESettlementDate->text(),"yyyy-MM-dd")<QDate::fromString(ui->P3DEEvictionDate->text(),"yyyy-MM-dd")){
                            QJsonObject post;
                            post["id"]=ui->P3LEid->text();
                            post["pasport"]=ui->P3LEPasport->text();
                            post["second_name"]=ui->P3LESecondName->text();
                            post["first_name"]=ui->P3LEFirstName->text();
                            post["patronymic"]=ui->P3LEPatronymic->text();
                            post["telephone"]=ui->P3LETelephone->text();
                            post["settlement_date"]=ui->P3DESettlementDate->text();
                            post["eviction_date"]=ui->P3DEEvictionDate->text();
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_ResultChangeGuest(Network *)));
                            qDebug() <<IP;
                            net->Post("http://"+IP+":5555/updateguest.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","Дата заселения не может быть позже даты отъезда!");
                    } else QMessageBox::warning(this,"Ошибка!","Отчество не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Имя не может быть пустым!");
            } else QMessageBox::warning(this,"Ошибка!","Фамилия не может быть пустой!");
        } else QMessageBox::warning(this,"Ошибка!","Паспорт не может быть пустым!");
}

void Portie::on_ResultChangeGuest(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Данные успешно изменены!");
        Network *por = new Network;
        connect(por,SIGNAL(onReady(Network *)),this,SLOT(on_Result_networkPortie(Network *)));
        por->Get("http://"+IP+":5555/gueststable.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось изменить данные!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось изменить данные! ("+a->GetAnswer()+")");
            }
        }
}
