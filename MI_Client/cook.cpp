#include "cook.h"
#include "ui_cook.h"

Cook::Cook(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cook)
{
    IP=ips;
    ui->setupUi(this);
    ui->C3Date->setDate(QDate::currentDate());
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
        cooks1->Get("http://"+IP+":5555/dish.json");
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
        cook2->Get("http://"+IP+":5555/stock_ingredients.json");
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
    if((cook3.isEmpty())||(cook1.isEmpty())){
        Network *cook3 = new Network;
        connect(cook3,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook3(Network *)));
        cook3->Get("http://"+IP+":5555/countguests.json?date="+ui->C3Date->text());
        Network *cooks1 = new Network;
        connect(cooks1,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook1(Network *)));
        cooks1->Get("http://"+IP+":5555/dish.json");
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
        cook4->Get("http://"+IP+":5555/menu.json");
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
    if(cook->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << cook->GetError();
        } else {
        cook1=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
        QJsonArray JsonA=cook1.object().value("Dishs").toArray();
        QWidget* widget1 = new QWidget;
        QWidget* widget2 = new QWidget;
        QFormLayout *layout1 = new QFormLayout;
        QFormLayout *layout2 = new QFormLayout;
        for(int i=0;i<JsonA.size();i++){
            QRadioButton *rb1 = new QRadioButton(this);
            rb1->setObjectName("C1rb"+JsonA[i].toObject().value("dish").toString());
            rb1->setText(JsonA[i].toObject().value("dish").toString());
            layout1->addWidget(rb1);
            connect(rb1,SIGNAL(pressed()),this,SLOT(rbCook1Change()));
            QCheckBox *rb2 = new QCheckBox(this);
            rb2->setObjectName("C3rb"+JsonA[i].toObject().value("dish").toString());
            rb2->setText(JsonA[i].toObject().value("dish").toString());
            layout2->addWidget(rb2);
            connect(rb2,SIGNAL(stateChanged(int)),this,SLOT(chbCook3Change(int)));
        }
        widget1->setLayout(layout1);
        ui->C1SA1->setWidget(widget1);
        widget2->setLayout(layout2);
        ui->C3SA1->setWidget(widget2);
        }
}

void Cook::OnResultCook2(Network *cook){
qDebug() << cook->GetAnswer();
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
if(cook->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << cook->GetError();
    } else {
    cook3=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
    ui->C3CBGuests->setText("на количество отдыхающих ("+cook3.object().value("count").toString()+" чел)");
    }
}

void Cook::OnResultCook4(Network *cook){
qDebug() << cook->GetAnswer();
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

void Cook::chbCook3Change(int stat){
QCheckBox* chb = (QCheckBox*) sender();
if(stat == 2){
    Ldishs.push_back(chb);
    } else {
    for(int i=0; i<Ldishs.size();i++){
        if (Ldishs[i] == chb){
            Ldishs.takeAt(i);
        }
    }
}
QWidget* widget = new QWidget;
QFormLayout* layout = new QFormLayout;
for(int i=0; i<Ldishs.size();i++){
    QLabel* lb = new QLabel;
    lb->setText(Ldishs[i]->text());
    layout->addWidget(lb);
    }
widget->setLayout(layout);
ui->C3SA2->setWidget(widget);
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

void Cook::on_C3Date_userDateChanged(const QDate &date)
{
    Network *cook3 = new Network;
    connect(cook3,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook3(Network *)));
    cook3->Get("http://"+IP+":5555/countguests.json?date="+ui->C3Date->text());
}

void Cook::on_breakfast_clicked()
{
    Typemenu="Завтрак";
}

void Cook::on_lunch_clicked()
{
    Typemenu="Обед";
}

void Cook::on_dinner_clicked()
{
    Typemenu="Ужин";
}

void Cook::on_other_clicked()
{
    Typemenu="Другое";
}

void Cook::on_C3BCancel_clicked()
{
for (int i=Ldishs.size();i>0;i--) {
    Ldishs.first()->setChecked(false);
    }
}

void Cook::on_C3BApply_clicked()
{
Network *cooks4 = new Network;
connect(cooks4,SIGNAL(onReady(Network *)),this,SLOT(OnResultCook3Menu(Network *)));
cooks4->Get("http://"+IP+":5555/menu.json");
}

void Cook::OnResultCook3Menu(Network *cook){
QJsonDocument co;
qDebug() << cook->GetAnswer();
if(cook->GetAnswer()==""){
    qDebug() <<"Error";
    qDebug() << cook->GetError();
    } else {
    co=QJsonDocument::fromJson(cook->GetAnswer().toUtf8());
    bool accept=true;
    for (int i=0;i<co.object().value("Menu").toArray().size();i++) {
        if(co.object().value("Menu").toArray().at(i).toObject().value("date").toString()==ui->C3Date->text())
            if(co.object().value("Menu").toArray().at(i).toObject().value("type").toString()==Typemenu)
                accept=false;
    }
    if(accept){
        int am;
        if(ui->C3CBGuests->isChecked()){
            am=cook3.object().value("count").toInt();
        } else
            am=ui->C3LEGuests->text().toInt();
        if(am>0){
            QJsonObject post;
            post["date"]=ui->C3Date->text();
            post["type"]=Typemenu;
            post["amount"]=am;
            QJsonArray dishs;
            for (int i=0;i<Ldishs.size();i++) {
                dishs.append(Ldishs[i]->text());
            }
            post["dishs"]=dishs;
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(OnResultAddMenu(Network *)));
            net->Post("http://"+IP+":5555/addmenu.json", doc);
        } else
        QMessageBox::warning(this,"Ошибка!","Количество людей должно быть положительным числом!");
    } else {
    QMessageBox::warning(this,"Ошибка!","Такое меню уже есть!");
    }
    }
}

void Cook::OnResultAddMenu(Network *a){
qDebug() << a->GetAnswer();
qDebug() << a->GetError();
if(a->GetAnswer()=="YES"){
    QMessageBox::information(this,"Успешно!","Новое меню добавлено!");
    } else {
    if(a->GetAnswer()=="NO"){
        QMessageBox::warning(this,"Ошибка!","Не удалось добавить меню!");
        } else {
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить меню! ("+a->GetAnswer()+")");
        }
    }
}
