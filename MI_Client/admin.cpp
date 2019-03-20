#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    IP=ips;
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    QGridLayout* cookL = new QGridLayout;
    cook= new Cook(IP);
    cookL->addWidget(cook);
    connect(cook,SIGNAL(loginOpen()),this,SLOT(on_LogOut_clicked()));
    ui->Cook->setLayout(cookL);

    QGridLayout* WhkL = new QGridLayout;
    whk = new Warehousekeeper(IP);
    WhkL->addWidget(whk);
    connect(whk,SIGNAL(loginOpen()),this,SLOT(on_LogOut_clicked()));
    ui->Whk->setLayout(WhkL);

    QGridLayout* PortieL = new QGridLayout;
    portie = new Portie(IP);
    PortieL->addWidget(portie);
    connect(portie,SIGNAL(loginOpen()),this,SLOT(on_LogOut_clicked()));
    ui->Stocker->setLayout(PortieL);

    //ui->C3Date->setDate(QDate::currentDate());
    ui->GBA1->move(215,50);
    ui->GBA2->move(215,50);
    ui->GBA3->move(215,50);
    ui->GBA4->move(215,50);
    ui->GBA5->move(215,50);
    ui->GBA6->move(215,50);
//    QStringList hh;
//    hh.append("Ингредиент");
//    hh.append("Требуется");
//    hh.append("На складе");
//    QStandardItemModel *M = new QStandardItemModel;
//    M->setHorizontalHeaderLabels(hh);
//    ui->C1TVIngredients->setModel(M);
//    ui->C1TVIngredients->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->C2T1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Admin::on_Hide_clicked();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}

void Admin::on_Hide_clicked()
{
    ui->GBA1->setVisible(false);
    ui->GBA2->setVisible(false);
    ui->GBA3->setVisible(false);
    ui->GBA4->setVisible(false);
    ui->GBA5->setVisible(false);
    ui->GBA6->setVisible(false);
    ui->Hide->setVisible(false);
}

void Admin::on_ABShow1_clicked()
{
    Network *admins1 = new Network;
    connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show1(Network *)));
    admins1->Get("http://"+IP+":5555/auth.json");
    Admin::on_Hide_clicked();
    ui->GBA1->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_ABShow2_clicked()
{
    Network *admins2 = new Network;
    connect(admins2,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show2(Network *)));
    admins2->Get("http://"+IP+":5555/ingredientstable.json");
    Admin::on_Hide_clicked();
    ui->GBA2->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_ABShow3_clicked()
{
    Network *admins3 = new Network;
    connect(admins3,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show3(Network *)));
    admins3->Get("http://"+IP+":5555/dishtable.json");
    Admin::on_Hide_clicked();
    ui->GBA3->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_ABShow4_clicked()
{
    Network *admins4 = new Network;
    connect(admins4,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show4(Network *)));
    admins4->Get("http://"+IP+":5555/stocktable.json");
    Admin::on_Hide_clicked();
    ui->GBA4->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_ABShow5_clicked()
{
    Network *admins5 = new Network;
    connect(admins5,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show5(Network *)));
    admins5->Get("http://"+IP+":5555/ingredientstable.json");
    Admin::on_Hide_clicked();
    ui->GBA5->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_ABShow6_clicked()
{
    Admin::on_Hide_clicked();
    ui->GBA6->setVisible(true);
    ui->Hide->setVisible(true);
}

void Admin::on_Result_Show1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin1=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin1.object().value("Users").toArray();
        QStandardItemModel *A1T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Логин");
        hh.append("Пароль");
        hh.append("Права доступа");
        A1T1M->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("login").toString()));
            A1T1M->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("password").toString()));
            A1T1M->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("role").toString()));
            A1T1M->setItem(i,2,Item3);
            }
        ui->A1TVUsers->setModel(A1T1M);
        ui->A1TVUsers->resizeRowsToContents();
        ui->A1TVUsers->resizeColumnsToContents();
        }
}

void Admin::on_Result_Show2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin2=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin2.object().value("Data").toArray();
        QStandardItemModel *A2T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название");
        hh.append("Необходимое кол-во");
        hh.append("Единицы измерения");
        A2T1M->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            A2T1M->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            A2T1M->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("needonstock").toString()));
            A2T1M->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("unit").toString()));
            A2T1M->setItem(i,3,Item4);
            }
        ui->A2TVIngredients->setModel(A2T1M);
        ui->A2TVIngredients->resizeRowsToContents();
        ui->A2TVIngredients->resizeColumnsToContents();
        }
}

void Admin::on_Result_Show3_Dish(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin3dish=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin3dish.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Название");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,0,Item1);
            }
        ui->A3TVDish->setModel(Model);
        ui->A3TVDish->resizeRowsToContents();
        ui->A3TVDish->resizeColumnsToContents();
        }
}

void Admin::on_Result_Show3_Ingredients(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin3ingredient=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JAIng=admin3ingredient.object().value("Data").toArray();
        QWidget* widget = new QWidget;
        QFormLayout *layout = new QFormLayout;
        for(int i=0;i<JAIng.size();i++){
            QCheckBox *chb = new QCheckBox(this);
            chb->setObjectName("A3chb"+JAIng[i].toObject().value("title").toString());
            chb->setText(JAIng[i].toObject().value("title").toString()+" ("+JAIng[i].toObject().value("unit").toString()+")");
            layout->addWidget(chb);
            connect(chb,SIGNAL(stateChanged(int)),this,SLOT(on_W3chbIngredientPressed(int)));
            }
        LIngredients.clear();
        widget->setLayout(layout);
        ui->A3SAAllIngredients->setWidget(widget);
        }
}

void Admin::on_Result_Show4(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin4=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        }
}

void Admin::on_Result_Show5(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin5=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        }
}

void Admin::on_A1BApply_clicked()
{
//url: /register.json
//формат: {"login":"log","password":"pass","role":"Админ"}
    if(ui->A1LELogin->text()!=""){
        if(ui->A1LEPassword->text()!=""){
            bool accept=true;
            for (int i=0;i<admin1.object().value("Users").toArray().size();i++) {
                if(admin1.object().value("Users").toArray().at(i).toObject().value("login").toString()==ui->A1LELogin->text()){
                    accept=false;
                    break;
                    }
                }
            if(accept){
                QJsonObject post;
                post["login"]=ui->A1LELogin->text();
                post["password"]=ui->A1LEPassword->text();
                post["role"]=ui->A1CBRole->currentText();
                QJsonDocument doc;
                doc.setObject(post);
                qDebug() << doc;
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_NewUser(Network *)));
                net->Post("http://"+IP+":5555/register.json", doc);
            } else QMessageBox::warning(this,"Ошибка!","Такой логин уже существует!");
        } else QMessageBox::warning(this,"Ошибка!","Пароль не может быть пустым!");
    } else QMessageBox::warning(this,"Ошибка!","Логин не может быть пустым!");
}

void Admin::on_Result_Post_NewUser(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Новый пользователь добавлен!");
        Network *admins1 = new Network;
        connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show1(Network *)));
        admins1->Get("http://"+IP+":5555/auth.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить пользователя!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить пользователя! ("+a->GetAnswer()+")");
            }
        }
}

void Admin::on_A2BApply_clicked()
{
//url: /newingredient.json
//формат: {"title":"name","unit":"кг"}
        if(ui->A2LEtitle->text()!=""){
            if(ui->A2LEneedonstock->text()!=""){
                bool accept=true;
                for (int i=0;i<admin2.object().value("Data").toArray().size();i++) {
                    if(admin2.object().value("Data").toArray().at(i).toObject().value("title").toString()==ui->A2LEtitle->text()){
                        accept=false;
                        break;
                        }
                    }
                if(accept){
                    if(ui->A2LEunit->text()!=""){
                        QJsonObject post;
                        post["title"]=ui->A2LEtitle->text();
                        post["qweqweqweqweqweqweqweqweqweqweqweqweqweqweqweqwe"]=ui->A2LEneedonstock->text();
                        post["unit"]=ui->A2LEunit->text();
                        QJsonDocument doc;
                        doc.setObject(post);
                        qDebug() << doc;
                        Network *net = new Network;
                        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_NewIngredient(Network *)));
                        net->Post("http://"+IP+":5555/newingredient.json", doc);
                    } else QMessageBox::warning(this,"Ошибка!","Необходимо указать единицы измерения для ингредиента");
                } else QMessageBox::warning(this,"Ошибка!","Такой ингредиент уже существует!");
            } else QMessageBox::warning(this,"Ошибка!","Необходимое количество на складе не может быть пустым!");
        } else QMessageBox::warning(this,"Ошибка!","Название ингредиента не может быть пустым!");
}

void Admin::on_Result_Post_NewIngredient(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Новый ингредиент добавлен!");
        Network *admins1 = new Network;
        connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show1(Network *)));
        admins1->Get("http://"+IP+":5555/ingredientstable.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить ингредиент!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить ингредиент! ("+a->GetAnswer()+")");
            }
        }
}

void Admin::on_A3chbIngredientPressed(int state){
    QCheckBox* chb = (QCheckBox*) sender();
    QRegExp exp("[1-9]{1}[0-9]{0,10}");
    if(state == 2){
        LIngredients.push_back(chb);
        } else {
        for(int i=0; i<LIngredients.size();i++){
            if (LIngredients[i] == chb)
                LIngredients.takeAt(i);
            }
        }
    QFormLayout* layout = new QFormLayout;
    QWidget* widget = new QWidget;
    for(int i=0; i<LIngredients.size();i++){
        QLineEdit* LiEd = new QLineEdit();
        LiEd->setObjectName(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5));
        LiEd->setValidator(new QRegExpValidator(exp,this));
        QLabel *lb = new QLabel(LIngredients[i]->text());
        lb->setObjectName("A3Lb"+LIngredients[i]->text());
        layout->addRow(lb,LiEd);
        }
    widget->setLayout(layout);
    ui->A3SASelectedIngredients->setWidget(widget);
}

void Admin::on_A3BApply_clicked(){
//url: /newdish.json
//формат: {"title":"name_dish","ingredients": [
//{"title":"name_ing","amount":"30"},
    if(ui->A3LETitle->text()!=""){
        bool accept=true;
        for (int i=0;i<admin3dish.object().value("Data").toArray().size();i++) {
            if(admin3dish.object().value("Data").toArray().at(i).toObject().value("title").toString()==ui->A3LETitle->text()){
                accept=false;
                break;
                }
            }
        if(accept){
            if(LIngredients.size()){
                for (int i=0;i<LIngredients.size();i++) {
                    if(findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text()=="")
                        accept=false;
                    }
                if(accept){
                    QJsonObject post;
                    post["title"]=ui->A3LETitle->text();
                    QJsonArray ingredients;
                    for (int i=0;i<LIngredients.size();i++) {
                        QJsonObject ingredient;
                        ingredient["title"]=findChild<QLabel*>("A3Lb"+LIngredients[i]->text())->text();
                        ingredient["amount"]=findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text();
                        ingredients.append(ingredient);
                        }
                    post["ingredients"]=ingredients;
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_NewDish(Network *)));
                    net->Post("http://"+IP+":5555/newdish.json", doc);
                }else QMessageBox::warning(this,"Ошибка!","Введите количество ингредиентов, необходимое для блюда!");
            }else QMessageBox::warning(this,"Ошибка!","Выберите продукты для блюда!");
        }else QMessageBox::warning(this,"Ошибка!","Такое блюдо уже существует!");
    }else QMessageBox::warning(this,"Ошибка!","Название продукта не может быть пустым!");
}

void Admin::on_Result_Post_NewDish(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Новое блюдо добавлено!");
        Network *admins = new Network;
        connect(admins,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show3_Dish(Network *)));
        admins->Get("http://"+IP+":5555/dishtable.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить блюдо!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить блюдо! ("+a->GetAnswer()+")");
            }
        }
}
