#include "cook.h"
#include "ui_cook.h"

Cook::Cook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cook)
{
    ui->setupUi(this);
    ui->GBC1->move(170,50);
    ui->GBC2->move(170,50);
    ui->GBC3->move(170,50);
    ui->GBC4->move(170,50);
    Cook::on_Hide_clicked();
}

Cook::~Cook()
{
    delete ui;
}

void Cook::on_Hide_clicked()
{
    ui->GBC1->setVisible(false);
    ui->GBC2->setVisible(false);
    ui->GBC3->setVisible(false);
    ui->GBC4->setVisible(false);
    ui->Hide->setVisible(false);
}

void Cook::on_whatchDish_clicked()
{
    if(cook1.isEmpty()){
        Network *cooks1 = new Network;
        connect(cooks1,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook1(Network *)));
        cooks1->SetUrl("http://127.0.0.1:5555/dish.json");
    }
    Cook::on_Hide_clicked();
    ui->GBC1->setVisible(true);
    ui->Hide->setVisible(true);
}

void Cook::on_whatchIngredients_clicked()
{
    if(cook2.isEmpty()){
        Network *cook2 = new Network;
        connect(cook2,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook2(Network *)));
        cook2->SetUrl("http://127.0.0.1:5555/stock_ingredients.json");
        QStandardItemModel *C2T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Склад");
        hh.append("Ингредиент");
        hh.append("Кол-во");
        C2T1M->setHorizontalHeaderLabels(hh);
        ui->C2T1->setModel(C2T1M);
    }
    Cook::on_Hide_clicked();
    ui->GBC2->setVisible(true);
    ui->Hide->setVisible(true);
}

void Cook::on_createMenu_clicked()
{
    if(cook3.isEmpty()){
        Network *cook3 = new Network;
        connect(cook3,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook3(Network *)));
        cook3->SetUrl("http://127.0.0.1:5555/guests.json");
    }
    Cook::on_Hide_clicked();
    ui->GBC3->setVisible(true);
    ui->Hide->setVisible(true);
}

void Cook::on_prevMenu_clicked()
{
    if(cook4.isEmpty()){
        Network *cook4 = new Network;
        connect(cook4,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook4(Network *)));
        cook4->SetUrl("http://127.0.0.1:5555/menu.json");
    }
    Cook::on_Hide_clicked();
    ui->GBC4->setVisible(true);
    ui->Hide->setVisible(true);
}

void Cook::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}

void Cook::OnResultCook1(Network *cook){
    qDebug() << cook->GetAnswer();
    qDebug() << cook->GetError();
    if(cook->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << cook->GetError();
        } else {
        cook1=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
        QJsonArray JsonA=cook1.object().value("Dishs").toArray();
        QWidget* widget = new QWidget;
        QFormLayout *layout = new QFormLayout;
        for(int i=0;i<JsonA.size();i++){
            QRadioButton *rb = new QRadioButton(this);
            rb->setObjectName("rb"+JsonA[i].toObject().value("dish").toString());
            rb->setText(JsonA[i].toObject().value("dish").toString());
            layout->addWidget(rb);
            connect(rb,SIGNAL(pressed()),this,SLOT(rbCook1Change()));
        }
        widget->setLayout(layout);
        ui->C1SA1->setWidget(widget);
        }
}

void Cook::OnResultCook2(Network *cook){
qDebug() << cook->GetAnswer();
qDebug() << cook->GetError();
if(cook->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << cook->GetError();
    } else {
    cook2=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
    QJsonArray JsonA=cook2.object().value("ingredient_stock").toArray();
    QStandardItemModel *C2T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Склад");
    hh.append("Ингредиент");
    hh.append("Кол-во");
    C2T1M->setHorizontalHeaderLabels(hh);
    for(int i=0;i<JsonA.size();i++){
        QStandardItem *Item1;
        Item1 = new QStandardItem(QString(JsonA[i].toObject().value("stock_title").toString()));
        C2T1M->setItem(i,0,Item1);
        QStandardItem *Item2;
        Item2 = new QStandardItem(QString(JsonA[i].toObject().value("ingredient_title").toString()));
        C2T1M->setItem(i,1,Item2);
        QStandardItem *Item3;
        Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
        C2T1M->setItem(i,2,Item3);
    }
    JsonA=cook2.object().value("Ingredients").toArray();
    ui->C2CB1->addItem("");
    for(int i=0;i<JsonA.size();i++){
        ui->C2CB1->addItem(JsonA[i].toString());
    }
    JsonA=cook2.object().value("Stocks").toArray();
    ui->C2CB2->addItem("");
    for(int i=0;i<JsonA.size();i++){
        ui->C2CB2->addItem(JsonA[i].toString());
    }
    ui->C2T1->setModel(C2T1M);
    ui->C2T1->resizeRowsToContents();
    ui->C2T1->resizeColumnsToContents();
    }
}

void Cook::OnResultCook3(Network *cook){
qDebug() << cook->GetAnswer();
qDebug() << cook->GetError();
if(cook->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << cook->GetError();
    } else {
    cook3=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
    QJsonArray JsonA=cook3.object().value("Dishs").toArray();
    QWidget* widget = new QWidget;
    QFormLayout *layout = new QFormLayout;
    for(int i=0;i<JsonA.size();i++){
        QCheckBox *chb = new QCheckBox(this);
        chb->setText(JsonA[i].toObject().value("dish").toString());
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(Network *cook)),this,SLOT(chbChange(Network *cook)));
    }
    widget->setLayout(layout);
    ui->AllDish->setWidget(widget);
    }
}

void Cook::OnResultCook4(Network *cook){
qDebug() << cook->GetAnswer();
qDebug() << cook->GetError();
if(cook->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << cook->GetError();
    } else {
    cook4=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
    }
}

void Cook::rbCook1Change(){
    QRadioButton* rb = (QRadioButton*) sender();
    QWidget* widget2 = new QWidget;
    QFormLayout* layout = new QFormLayout;
    QJsonObject JO = cook1.object();
    QJsonArray JAI=JO.value("Dishs").toArray();
    QJsonArray JAU=JO.value("Ingredients").toArray();
    for (int j=0;j<JAI.size();j++) {
        if(JAI[j].toObject().value("dish")==rb->text()){
            for(int k=0;k<JAI[j].toObject().value("ingredients").toArray().size();k++){
                QLabel* lb1 = new QLabel;
                QString s;
                s=JAI[j].toObject().value("ingredients").toArray().at(k).toObject().value("title").toString()+" "+JAI[j].toObject().value("ingredients").toArray().at(k).toObject().value("amount").toString();
                for (int i=0;i<JAU.size();i++) {
                    if(JAU[i].toObject().value("title")==JAI[j].toObject().value("ingredients").toArray().at(k).toObject().value("title")){
                        s+=JAU[i].toObject().value("unit").toString();
                        break;
                     }
                }
                lb1->setText(s);
                layout->addWidget(lb1);
            }
            break;
        }
    }
    widget2->setLayout(layout);
    ui->C1SA2->setWidget(widget2);
}

void Cook::on_C2BSearch_clicked()
{
    QStandardItemModel *C2T1M = new QStandardItemModel;
    QStringList hh;
    QJsonArray JsonA=cook2.object().value("ingredient_stock").toArray();
    hh.append("Склад");
    hh.append("Ингредиент");
    hh.append("Кол-во");
    C2T1M->setHorizontalHeaderLabels(hh);
    QString Ing=ui->C2CB1->currentText();
    QString Stock=ui->C2CB2->currentText();
    int k=0;
    for(int i=0;i<JsonA.size();i++){
        if((Ing!="" ? JsonA[i].toObject().value("ingredient_title").toString()==Ing : JsonA[i].toObject().value("ingredient_title").toString()!="")&&(Stock!="" ? JsonA[i].toObject().value("stock_title").toString()==Stock : JsonA[i].toObject().value("stock_title").toString()!="")){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("stock_title").toString()));
            C2T1M->setItem(k,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("ingredient_title").toString()));
            C2T1M->setItem(k,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
            C2T1M->setItem(k,2,Item3);
            k++;
        }
    }
    //внести склады и ингредиенты
    ui->C2T1->setModel(C2T1M);
    ui->C2T1->resizeRowsToContents();
}

void Cook::on_C4BSearch_clicked()
{
    QString type;
    if(ui->C4RB1->isChecked())
        type="Завтрак";
    if(ui->C4RB2->isChecked())
        type="Обед";
    if(ui->C4RB3->isChecked())
        type="Ужин";
    if(ui->C4RB4->isChecked())
        type="Другое";

    QJsonArray JsonA=cook4.object().value("Menu").toArray();
    QWidget* widget = new QWidget;
    QFormLayout *layout = new QFormLayout;
    QString amo="0";
    for(int i=0;i<JsonA.size();i++){
        if((JsonA[i].toObject().value("type").toString()==type)&&(JsonA[i].toObject().value("date").toString()==ui->C4Calendar->selectedDate().toString("yyyy-MM-dd"))){
            for(int j=0;j<JsonA[i].toObject().value("dishs").toArray().size();j++){
                QLabel *lb = new QLabel;
                lb->setText(JsonA[i].toObject().value("dishs").toArray().at(j).toString());
                layout->addWidget(lb);
            }
        amo=JsonA[i].toObject().value("amount").toString();
        break;
        }
    }
    ui->C4LAmount->setText("Количество: "+amo);
    widget->setLayout(layout);
    ui->C4SA1->setWidget(widget);
}
