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
    ui->A1TVUsers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A2TVIngredients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A3TVDish->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A4TVStocks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->A5TVStocks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A6TV->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    QStandardItemModel *A1T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Логин");
    hh.append("Пароль");
    hh.append("Права доступа");
    A1T1M->setHorizontalHeaderLabels(hh);
    ui->A1TVUsers->setModel(A1T1M);
    ui->A1TVUsers->resizeRowsToContents();
    ui->A1TVUsers->resizeColumnsToContents();
    Admin::on_Hide_clicked();
    ui->GBA1->setVisible(true);
    ui->Hide->setVisible(true);
}
void Admin::on_ABShow2_clicked()
{
    Network *admins2 = new Network;
    connect(admins2,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show2(Network *)));
    admins2->Get("http://"+IP+":5555/ingredientstable.json");
    QStandardItemModel *A2T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Идентификатор");
    hh.append("Название");
    hh.append("Необходимое кол-во");
    hh.append("Единицы измерения");
    A2T1M->setHorizontalHeaderLabels(hh);
    ui->A2TVIngredients->setModel(A2T1M);
    ui->A2TVIngredients->resizeRowsToContents();
    ui->A2TVIngredients->resizeColumnsToContents();
    Admin::on_Hide_clicked();
    ui->GBA2->setVisible(true);
    ui->Hide->setVisible(true);
}
void Admin::on_ABShow3_clicked()
{
    Network *admins3d = new Network;
    connect(admins3d,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show3_Dish(Network *)));
    admins3d->Get("http://"+IP+":5555/dishtable.json");
    Network *admins3i = new Network;
    connect(admins3i,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show3_Ingredients(Network *)));
    admins3i->Get("http://"+IP+":5555/ingredientstable.json");
    QStandardItemModel *Model = new QStandardItemModel;
    QStringList hh;
    hh.append("Название");
    ui->A3TVDish->setModel(Model);
    ui->A3TVDish->resizeRowsToContents();
    ui->A3TVDish->resizeColumnsToContents();
    Admin::on_Hide_clicked();
    ui->GBA3->setVisible(true);
    ui->Hide->setVisible(true);
}
void Admin::on_ABShow4_clicked()
{
    Network *admins4 = new Network;
    connect(admins4,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show4(Network *)));
    admins4->Get("http://"+IP+":5555/stocktable.json");
    QStandardItemModel *Model = new QStandardItemModel;
    QStringList hh;
    hh.append("Идентификатор");
    hh.append("Название");
    Model->setHorizontalHeaderLabels(hh);
    ui->A4TVStocks->setModel(Model);
    ui->A4TVStocks->resizeRowsToContents();
    ui->A4TVStocks->resizeColumnsToContents();
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
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6auth(Network *)));
    admins6->Get("http://"+IP+":5555/authtable.json");
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
            connect(chb,SIGNAL(stateChanged(int)),this,SLOT(on_A3chbIngredientPressed(int)));
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
        QJsonArray JsonA=admin4.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A4TVStocks->setModel(Model);
        ui->A4TVStocks->resizeRowsToContents();
        ui->A4TVStocks->resizeColumnsToContents();
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
                        post["needonstock"]=ui->A2LEneedonstock->text();
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
        connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show2(Network *)));
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
                        ingredient["title"]=LIngredients[i]->text().mid(0,LIngredients[i]->text().indexOf(" (",1));
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

void Admin::on_A4BApply_clicked(){
//url: /newstock.json
//формат: {"title":"name"}
        if(ui->A4LETitle->text()!=""){
            bool accept=true;
            for (int i=0;i<admin4.object().value("Data").toArray().size();i++) {
                if(admin4.object().value("Data").toArray().at(i).toObject().value("title").toString()==ui->A4LETitle->text()){
                    accept=false;
                    break;
                    }
                }
            if(accept){
                QJsonObject post;
                post["title"]=ui->A4LETitle->text();
                QJsonDocument doc;
                doc.setObject(post);
                qDebug() << doc;
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_NewStock(Network *)));
                net->Post("http://"+IP+":5555/newstock.json", doc);
            }else QMessageBox::warning(this,"Ошибка!","Такой склад уже существует!");
        }else QMessageBox::warning(this,"Ошибка!","Название склада не может быть пустым!");
}
void Admin::on_Result_Post_NewStock(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Новый склад добавлен!");
        Network *admins = new Network;
        connect(admins,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show4(Network *)));
        admins->Get("http://"+IP+":5555/stocktable.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить склад!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить склад! ("+a->GetAnswer()+")");
            }
        }
}

void Admin::on_Result_Show6auth(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Логин");
        hh.append("Пароль");
        hh.append("Идентификатор роли");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("login").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("password").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("id_role").toString()));
            Model->setItem(i,2,Item3);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6dish(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6guests(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Паспорт");
        hh.append("Фамилия");
        hh.append("Имя");
        hh.append("Отчество");
        hh.append("Телефон");
        hh.append("Дата заезда");
        hh.append("Дата выезда");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("pasport").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("second_name").toString()));
            Model->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("first_name").toString()));
            Model->setItem(i,3,Item4);
            QStandardItem *Item5;
            Item5 = new QStandardItem(QString(JsonA[i].toObject().value("patronymic").toString()));
            Model->setItem(i,4,Item5);
            QStandardItem *Item6;
            Item6 = new QStandardItem(QString(JsonA[i].toObject().value("telephone").toString()));
            Model->setItem(i,5,Item6);
            QStandardItem *Item7;
            Item7 = new QStandardItem(QString(JsonA[i].toObject().value("settlement_date").toString()));
            Model->setItem(i,6,Item7);
            QStandardItem *Item8;
            Item8 = new QStandardItem(QString(JsonA[i].toObject().value("eviction_date").toString()));
            Model->setItem(i,7,Item8);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6ingredients(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название");
        hh.append("Необходимое кол-во");
        hh.append("Единицы измерения");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("needonstock").toString()));
            Model->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("unit").toString()));
            Model->setItem(i,3,Item4);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6ingredients_dish(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер блюда");
        hh.append("Номер ингредиента");
        hh.append("Кол-во ингредиента");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id_dish").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("id_ingredient").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()));
            Model->setItem(i,2,Item3);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6ingredients_stock(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер склада");
        hh.append("Номер ингредиента");
        hh.append("Кол-во ингредиента");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id_stock").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("id_ingredient").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()));
            Model->setItem(i,2,Item3);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6invoice(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер накладной");
        hh.append("Дата накладной");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("date").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6invoice_stock(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер накладной");
        hh.append("Номер склада");
        hh.append("Номер продукта");
        hh.append("Кол-во продукта");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id_invoice").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("id_stock").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("id_ingredient").toString()));
            Model->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()));
            Model->setItem(i,3,Item4);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6menu(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер меню");
        hh.append("Номер типа меню");
        hh.append("Дата меню");
        hh.append("Кол-во блюд");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("id_type").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("date").toString()));
            Model->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()));
            Model->setItem(i,3,Item4);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6menu_dish(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Номер меню");
        hh.append("Номер блюда");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id_menu").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("id_dish").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6role(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор роли");
        hh.append("Название роли");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("role").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6stock(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название склада");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}
void Admin::on_Result_Show6type_menu(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin6=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin6.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название типа меню");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("title").toString()));
            Model->setItem(i,1,Item2);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        }
}

void Admin::on_A6RBauth_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6auth(Network *)));
    admins6->Get("http://"+IP+":5555/authtable.json");
    SelectedTable=1;
}
void Admin::on_A6RBdish_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6dish(Network *)));
    admins6->Get("http://"+IP+":5555/dishtable.json");
    SelectedTable=2;
}
void Admin::on_A6RBguests_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6guests(Network *)));
    admins6->Get("http://"+IP+":5555/gueststable.json");
    SelectedTable=3;
}
void Admin::on_A6RBingredients_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients(Network *)));
    admins6->Get("http://"+IP+":5555/ingredientstable.json");
    SelectedTable=4;
}
void Admin::on_A6RBingredients_dish_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_dish(Network *)));
    admins6->Get("http://"+IP+":5555/ingredients_dishtable.json");
    SelectedTable=5;
}
void Admin::on_A6RBingredients_stock_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_stock(Network *)));
    admins6->Get("http://"+IP+":5555/ingredients_stocktable.json");
    SelectedTable=6;
}
void Admin::on_A6RBinvoice_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice(Network *)));
    admins6->Get("http://"+IP+":5555/invoicetable.json");
    SelectedTable=7;
}
void Admin::on_A6RBinvoice_stock_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice_stock(Network *)));
    admins6->Get("http://"+IP+":5555/invoice_stocktable.json");
    SelectedTable=8;
}
void Admin::on_A6RBmenu_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu(Network *)));
    admins6->Get("http://"+IP+":5555/menutable.json");
    SelectedTable=9;
}
void Admin::on_A6RBmenu_dish_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu_dish(Network *)));
    admins6->Get("http://"+IP+":5555/menu_dishtable.json");
    SelectedTable=10;
}
void Admin::on_A6RBrole_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6role(Network *)));
    admins6->Get("http://"+IP+":5555/roletable.json");
    SelectedTable=11;
}
void Admin::on_A6RBstock_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6stock(Network *)));
    admins6->Get("http://"+IP+":5555/stocktable.json");
    SelectedTable=12;
}
void Admin::on_A6RBtype_menu_clicked()
{
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6type_menu(Network *)));
    admins6->Get("http://"+IP+":5555/type_menutable.json");
    SelectedTable=13;
}

void Admin::on_A6TV_clicked(const QModelIndex &index)
{
    ui->A6TV->selectRow(index.row());
    QModelIndex in=ui->A6TV->model()->index(index.row(),0);
    switch (SelectedTable) {
    case 1://auth
        ui->A6L1->setVisible(true);
        ui->A6LE1->setVisible(true);
        ui->A6L1->text()="Логин";
        ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),1);
        ui->A6L2->setVisible(true);
        ui->A6LE2->setVisible(true);
        ui->A6L2->text()="Пароль";
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),2);
        ui->A6L3->setVisible(true);
        ui->A6LE3->setVisible(true);
        ui->A6L3->text()="Роль";
        ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),3);
        ui->A6L4->setVisible(false);
        ui->A6LE4->setVisible(false);
        ui->A6L5->setVisible(false);
        ui->A6LE5->setVisible(false);
        ui->A6L6->setVisible(false);
        ui->A6LE6->setVisible(false);
        ui->A6L7->setVisible(false);
        ui->A6DE1->setVisible(false);
        ui->A6L8->setVisible(false);
        ui->A6DE2->setVisible(false);
        break;
    case 2://dish
        ui->A6L1->setVisible(true);
        ui->A6LE1->setVisible(true);
        ui->A6L1->text()="id";
        ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),1);
        ui->A6L2->setVisible(true);
        ui->A6LE2->setVisible(true);
        ui->A6L2->text()="Название";
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),2);
        ui->A6L3->setVisible(false);
        ui->A6LE3->setVisible(false);
        ui->A6L4->setVisible(false);
        ui->A6LE4->setVisible(false);
        ui->A6L5->setVisible(false);
        ui->A6LE5->setVisible(false);
        ui->A6L6->setVisible(false);
        ui->A6LE6->setVisible(false);
        ui->A6L7->setVisible(false);
        ui->A6DE1->setVisible(false);
        ui->A6L8->setVisible(false);
        ui->A6DE2->setVisible(false);
        break;
    case 3://guests
        ui->A6L1->setVisible(true);
        ui->A6LE1->setVisible(true);
        ui->A6L1->text()="id";
        ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),1);
        ui->A6L2->setVisible(true);
        ui->A6LE2->setVisible(true);
        ui->A6L2->text()="Паспорт";
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),2);
        ui->A6L3->setVisible(true);
        ui->A6LE3->setVisible(true);
        ui->A6L3->text()="Фамилия";
        ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),3);
        ui->A6L4->setVisible(true);
        ui->A6LE4->setVisible(true);
        ui->A6L4->text()="Имя";
        ui->A6LE4->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),4);
        ui->A6L5->setVisible(true);
        ui->A6LE5->setVisible(true);
        ui->A6L5->text()="Отчество";
        ui->A6LE5->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),5);
        ui->A6L6->setVisible(true);
        ui->A6LE6->setVisible(true);
        ui->A6L6->text()="Телефон";
        ui->A6LE6->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),6);
        ui->A6L7->setVisible(true);
        ui->A6DE1->setVisible(true);
        ui->A6L7->text()="Дата заезда";
        ui->A6DE1->setDate(ui->A6TV->model()->data(in).toDate());
        in=ui->A6TV->model()->index(index.row(),7);
        ui->A6L8->setVisible(true);
        ui->A6DE2->setVisible(true);
        ui->A6L8->text()="Дата выезда";
        ui->A6DE2->setDate(ui->A6TV->model()->data(in).toDate());
        break;
    case 4://ingredients
        ui->A6L1->setVisible(true);
        ui->A6LE1->setVisible(true);
        ui->A6L1->text()="id";
        ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),1);
        ui->A6L2->setVisible(true);
        ui->A6LE2->setVisible(true);
        ui->A6L2->text()="Название";
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),2);
        ui->A6L3->setVisible(true);
        ui->A6LE3->setVisible(true);
        ui->A6L3->text()="Необходимое кол-во";
        ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),3);
        ui->A6L4->setVisible(true);
        ui->A6LE4->setVisible(true);
        ui->A6L4->text()="Ед измерения";
        ui->A6LE4->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),4);
        ui->A6L5->setVisible(false);
        ui->A6LE5->setVisible(false);
        ui->A6L6->setVisible(false);
        ui->A6LE6->setVisible(false);
        ui->A6L7->setVisible(false);
        ui->A6DE1->setVisible(false);
        ui->A6L8->setVisible(false);
        ui->A6DE2->setVisible(false);
        break;
    case 5://ingredients-dish
        ui->A6L1->setVisible(true);
        ui->A6LE1->setVisible(true);
        ui->A6L1->text()="Номер блюда";
        ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),1);
        ui->A6L2->setVisible(true);
        ui->A6LE2->setVisible(true);
        ui->A6L2->text()="Номер ингредиента";
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),2);
        ui->A6L3->setVisible(true);
        ui->A6LE3->setVisible(true);
        ui->A6L3->text()="Кол-во ингредиента";
        ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
        in=ui->A6TV->model()->index(index.row(),3);
        ui->A6L4->setVisible(false);
        ui->A6LE4->setVisible(false);
        ui->A6L5->setVisible(false);
        ui->A6LE5->setVisible(false);
        ui->A6L6->setVisible(false);
        ui->A6LE6->setVisible(false);
        ui->A6L7->setVisible(false);
        ui->A6DE1->setVisible(false);
        ui->A6L8->setVisible(false);
        ui->A6DE2->setVisible(false);
        break;
    case 6://ingredients-stock

        break;
    case 7://invoice

        break;
    case 8://invoice-stock

        break;
    case 9://menu

        break;
    case 10://menu-dish

        break;
    case 11://role

        break;
    case 12://stock

        break;
    case 13://type_menu

        break;
    }
//    ui->A6LE1->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),1);
//    ui->P3LEPasport->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),2);
//    ui->P3LESecondName->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),3);
//    ui->P3LEFirstName->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),4);
//    ui->P3LEPatronymic->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),5);
//    ui->P3LETelephone->setText(ui->P3TVGuests->model()->data(in).toString());
//    in=ui->P3TVGuests->model()->index(index.row(),6);
//    ui->P3DESettlementDate->setDate(ui->P3TVGuests->model()->data(in).toDate());
//    in=ui->P3TVGuests->model()->index(index.row(),7);
//    ui->P3DEEvictionDate->setDate(ui->P3TVGuests->model()->data(in).toDate());
    }
