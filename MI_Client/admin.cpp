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
    ui->A6SA->setVisible(false);
    ui->A6BI8->setVisible(false);
    ui->A6BI9->setVisible(false);
    ui->A1TVUsers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A2TVIngredients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A3TVDish->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A4TVStocks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A5TV->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->A6TV->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Admin::on_Hide_clicked();
    QRegExp expnumber("[1-9]{1}[0-9]{0,10}");
    QRegExp expengsimvol("[A-Z,a-z,0-9]{0,20}");
    QRegExp exprusimvol("[А-Я,а-я,\\s]{0,20}");
    QRegExp expunit("[а-я]{0,3}");

    ui->A1LELogin->setValidator(new QRegExpValidator(expengsimvol,this));
    ui->A1LEPassword->setValidator(new QRegExpValidator(expengsimvol,this));
    ui->A2LEtitle->setValidator(new QRegExpValidator(exprusimvol,this));
    ui->A2LEneedonstock->setValidator(new QRegExpValidator(expnumber,this));
    ui->A2LEunit->setValidator(new QRegExpValidator(expunit,this));
    ui->A3LETitle->setValidator(new QRegExpValidator(exprusimvol,this));
    ui->A4LETitle->setValidator(new QRegExpValidator(exprusimvol,this));
    ui->A5LEneedonstock->setValidator(new QRegExpValidator(expnumber,this));
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
    switch (SelectedTable) {
        case 1:
        admins6->Get("http://"+IP+":5555/authtable.json");
            break;
        case 2:
        admins6->Get("http://"+IP+":5555/dishtable.json");
            break;
        case 3:
        admins6->Get("http://"+IP+":5555/gueststable.json");
            break;
        case 4:
        admins6->Get("http://"+IP+":5555/ingredientstable.json");
            break;
        case 5:
        admins6->Get("http://"+IP+":5555/ingredients_dishtable.json");
            break;
        case 6:
        admins6->Get("http://"+IP+":5555/ingredients_stocktable.json");
            break;
        case 7:
        admins6->Get("http://"+IP+":5555/invoicetable.json");
            break;
        case 8:
        admins6->Get("http://"+IP+":5555/invoice_stocktable.json");
            break;
        case 9:
        admins6->Get("http://"+IP+":5555/menutable.json");
            break;
        case 10:
        admins6->Get("http://"+IP+":5555/menu_dishtable.json");
            break;
        case 11:
        admins6->Get("http://"+IP+":5555/roletable.json");
            break;
        case 12:
        admins6->Get("http://"+IP+":5555/stocktable.json");
            break;
        case 13:
        admins6->Get("http://"+IP+":5555/type_menutable.json");
    }
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
    a->deleteLater();
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
    a->deleteLater();
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
    a->deleteLater();
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
    a->deleteLater();
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
    a->deleteLater();
}
void Admin::on_Result_Show5(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        admin5=QJsonDocument::fromJson(a->GetAnswer().toUtf8());
        QJsonArray JsonA=admin5.object().value("Data").toArray();
        QStandardItemModel *Model = new QStandardItemModel;
        QStringList hh;
        hh.append("Идентификатор");
        hh.append("Название");
        hh.append("Необходимо на складе");
        hh.append("Ед измерения");
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
        ui->A5TV->setModel(Model);
        ui->A5TV->resizeRowsToContents();
        ui->A5TV->resizeColumnsToContents();
        }
    a->deleteLater();
}

void Admin::on_A1BApply_clicked(){
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
    a->deleteLater();
}

void Admin::on_A2BApply_clicked(){
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
    a->deleteLater();
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
    a->deleteLater();
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
    a->deleteLater();
}

void Admin::on_A5TV_clicked(const QModelIndex &index){
    ui->A5TV->selectRow(index.row());
    QModelIndex in=ui->A5TV->model()->index(index.row(),0);
    ui->A5LEid->setText(ui->A5TV->model()->data(in).toString());
    in=ui->A5TV->model()->index(in.row(),1);
    ui->A5LEtitle->setText(ui->A5TV->model()->data(in).toString());
    in=ui->A5TV->model()->index(in.row(),2);
    ui->A5LEneedonstock->setText(ui->A5TV->model()->data(in).toString());
    in=ui->A5TV->model()->index(in.row(),3);
    ui->A5LEunit->setText(ui->A5TV->model()->data(in).toString());
}
void Admin::on_A5BApply_clicked(){
//url: /updatebyid.json
//формат: {"table":"name","valUES":["val1","val2",...],"id":"1"}
    if(ui->A5LEneedonstock->text()!=""){
        QJsonObject post;
        post["table"]="ingredients";
        QJsonArray vals;
        vals.append(ui->A5LEid->text());
        vals.append(ui->A5LEtitle->text());
        vals.append(ui->A5LEneedonstock->text());
        vals.append(ui->A5LEunit->text());
        post["values"]=vals;
        post["id"]=ui->A5LEid->text();
        QJsonDocument doc;
        doc.setObject(post);
        qDebug() << doc;
        Network *net = new Network;
        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateNeedOnStock(Network *)));
        net->Post("http://"+IP+":5555/updatebyid.json", doc);
    } else QMessageBox::warning(this,"Ошибка!","Поле необходимого количества на складе не может быть пустым!");
}
void Admin::on_Result_Post_UpdateNeedOnStock(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Данные обновлены!");
        Network *admins1 = new Network;
        connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show5(Network *)));
        admins1->Get("http://"+IP+":5555/ingredientstable.json");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось обновить данные!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось обновить данные! ("+a->GetAnswer()+")");
            }
        }
    a->deleteLater();
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
        inn=ui->A6TV->model()->index(0,0);
        SelectedTable=1;
        }
    a->deleteLater();
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
        SelectedTable=2;
        }
    a->deleteLater();
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
        SelectedTable=3;
        }
    a->deleteLater();
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
        SelectedTable=4;
        }
    a->deleteLater();
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
        SelectedTable=5;
        }
    a->deleteLater();
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
        SelectedTable=6;
        }
    a->deleteLater();
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
        SelectedTable=7;
        }
    a->deleteLater();
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
        SelectedTable=8;
        }
    a->deleteLater();
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
        hh.append("Дата меню");
        hh.append("Номер типа меню");
        hh.append("Кол-во блюд");
        Model->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            Model->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("date").toString()));
            Model->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("id_type").toString()));
            Model->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()));
            Model->setItem(i,3,Item4);
            }
        ui->A6TV->setModel(Model);
        ui->A6TV->resizeRowsToContents();
        ui->A6TV->resizeColumnsToContents();
        SelectedTable=9;
        }
    a->deleteLater();
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
        SelectedTable=10;
        }
    a->deleteLater();
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
        SelectedTable=11;
        }
    a->deleteLater();
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
        SelectedTable=12;
        }
    a->deleteLater();
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
        SelectedTable=13;
        }
    a->deleteLater();
}

void Admin::DBTableEditing(bool lv1, bool le1, QString l1, bool lv2, QString l2, bool lv3, QString l3, bool lv4, QString l4, bool lv5, QString l5, bool lv6, QString l6, bool lv7, QString l7, bool lv8){
    ui->A6L1->setText(l1);
    ui->A6LE1->text().clear();
    ui->A6LE1->setEnabled(le1);
    ui->A6L1->setVisible(lv1);
    ui->A6LE1->setVisible(lv1);

    ui->A6L2->setText(l2);
    ui->A6L2->setVisible(lv2);
    ui->A6LE2->setVisible(lv2);

    ui->A6L3->setText(l3);
    ui->A6L3->setVisible(lv3);
    ui->A6LE3->setVisible(lv3);

    ui->A6L4->setText(l4);
    ui->A6L4->setVisible(lv4);
    ui->A6LE4->setVisible(lv4);

    ui->A6L5->setText(l5);
    ui->A6L5->setVisible(lv5);
    ui->A6LE5->setVisible(lv5);

    ui->A6L6->setText(l6);
    ui->A6L6->setVisible(lv6);
    ui->A6LE6->setVisible(lv6);

    ui->A6L7->setText(l7);
    ui->A6DE1->setDate(QDate::currentDate());
    ui->A6L7->setVisible(lv7);
    ui->A6DE1->setVisible(lv7);

    ui->A6DE2->setDate(QDate::currentDate());
    ui->A6L8->setVisible(lv8);
    ui->A6DE2->setVisible(lv8);

    ui->A6HSB->setValue(0);
    QModelIndex in=inn;
    in=ui->A6TV->model()->index(in.row(),0);
    ui->A6L1->setGeometry(10,0,ui->A6TV->columnWidth(0),20);
    ui->A6LE1->setGeometry(10,20,ui->A6TV->columnWidth(0),20);
    ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),1);
    if((lv2==false)&&(lv7)){
        ui->A6L7->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,0,ui->A6TV->columnWidth(1),20);
        ui->A6DE1->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,20,ui->A6TV->columnWidth(1),20);
        ui->A6DE1->setDate(QDate::fromString(ui->A6TV->model()->data(in).toString(),"yyyy-MM-dd"));
        ui->A6L3->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,0,ui->A6TV->columnWidth(2),20);
        ui->A6LE3->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,20,ui->A6TV->columnWidth(2),20);
    } else{
        ui->A6L2->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,0,ui->A6TV->columnWidth(1),20);
        ui->A6LE2->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,20,ui->A6TV->columnWidth(1),20);
        ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
        ui->A6L3->setGeometry(ui->A6LE2->x()+ui->A6LE2->width()+10,0,ui->A6TV->columnWidth(2),20);
        ui->A6LE3->setGeometry(ui->A6LE2->x()+ui->A6LE2->width()+10,20,ui->A6TV->columnWidth(2),20);
    }
    in=ui->A6TV->model()->index(in.row(),2);
    ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),3);
    ui->A6L4->setGeometry(ui->A6LE3->x()+ui->A6LE3->width()+10,0,ui->A6TV->columnWidth(3),20);
    ui->A6LE4->setGeometry(ui->A6LE3->x()+ui->A6LE3->width()+10,20,ui->A6TV->columnWidth(3),20);
    ui->A6LE4->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),4);
    ui->A6L5->setGeometry(ui->A6LE4->x()+ui->A6LE4->width()+10,0,ui->A6TV->columnWidth(4),20);
    ui->A6LE5->setGeometry(ui->A6LE4->x()+ui->A6LE4->width()+10,20,ui->A6TV->columnWidth(4),20);
    ui->A6LE5->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),5);
    ui->A6L6->setGeometry(ui->A6LE5->x()+ui->A6LE5->width()+10,0,ui->A6TV->columnWidth(5),20);
    ui->A6LE6->setGeometry(ui->A6LE5->x()+ui->A6LE5->width()+10,20,ui->A6TV->columnWidth(5),20);
    ui->A6LE6->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),6);
    if(!((lv2==false)&&(lv7))){
        ui->A6L7->setGeometry(ui->A6LE6->x()+ui->A6LE6->width()+10,0,ui->A6TV->columnWidth(6),20);
        ui->A6DE1->setGeometry(ui->A6LE6->x()+ui->A6LE6->width()+10,20,ui->A6TV->columnWidth(6),20);
        ui->A6DE1->setDate(QDate::fromString(ui->A6TV->model()->data(in).toString(),"yyyy-MM-dd"));
        in=ui->A6TV->model()->index(in.row(),7);
        ui->A6L8->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,0,ui->A6TV->columnWidth(7),20);
        ui->A6DE2->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,20,ui->A6TV->columnWidth(7),20);
        ui->A6DE2->setDate(QDate::fromString(ui->A6TV->model()->data(in).toString(),"yyyy-MM-dd"));
    }
    if(ui->A6DE2->x()>ui->A6LE6->x()){
        if(ui->A6DE2->x()+ui->A6DE2->width()-611<0){
            ui->A6HSB->setMaximum(0);
        } else ui->A6HSB->setMaximum(ui->A6DE2->x()+ui->A6DE2->width()-611);
    } else {
        if(ui->A6LE6->x()+ui->A6LE6->width()-611<0){
            ui->A6HSB->setMaximum(0);
        } else ui->A6HSB->setMaximum(ui->A6LE6->x()+ui->A6LE6->width()-611);
    }
    ui->A6GBTables->setEnabled(false);
    ui->A6SA->setVisible(true);
}
void Admin::DBTableCreate(bool s1, QString l1, bool s2, QString l2, bool s3, QString l3, bool s4, QString l4, bool s5, QString l5, bool s6, QString l6, bool s7, QString l7, bool s8){
    ui->A6L1->setText(l1);
    ui->A6L1->setVisible(s1);
    ui->A6L1->setGeometry(10,0,ui->A6TV->columnWidth(0),20);
    ui->A6LE1->setText("");
    ui->A6LE1->setEnabled(true);
    ui->A6LE1->setVisible(s1);
    ui->A6LE1->setGeometry(10,20,ui->A6TV->columnWidth(0),20);

    if((s2==false)&&(s7)){
        ui->A6L7->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,0,ui->A6TV->columnWidth(1),20);
        ui->A6DE1->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,20,ui->A6TV->columnWidth(1),20);
        ui->A6L3->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,0,ui->A6TV->columnWidth(2),20);
        ui->A6LE3->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,20,ui->A6TV->columnWidth(2),20);
    } else{
        ui->A6L2->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,0,ui->A6TV->columnWidth(1),20);
        ui->A6LE2->setGeometry(ui->A6LE1->x()+ui->A6LE1->width()+10,20,ui->A6TV->columnWidth(1),20);
        ui->A6L3->setGeometry(ui->A6LE2->x()+ui->A6LE2->width()+10,0,ui->A6TV->columnWidth(2),20);
        ui->A6LE3->setGeometry(ui->A6LE2->x()+ui->A6LE2->width()+10,20,ui->A6TV->columnWidth(2),20);
    }

    ui->A6L2->setText(l2);
    ui->A6L2->setVisible(s2);
    ui->A6LE2->setText("");
    ui->A6LE2->setVisible(s2);

    ui->A6L3->setText(l3);
    ui->A6L3->setVisible(s3);
    ui->A6LE3->setText("");
    ui->A6LE3->setVisible(s3);

    ui->A6L4->setText(l4);
    ui->A6L4->setVisible(s4);
    ui->A6L4->setGeometry(ui->A6LE3->x()+ui->A6LE3->width()+10,0,ui->A6TV->columnWidth(3),20);
    ui->A6LE4->setText("");
    ui->A6LE4->setVisible(s4);
    ui->A6LE4->setGeometry(ui->A6LE3->x()+ui->A6LE3->width()+10,20,ui->A6TV->columnWidth(3),20);

    ui->A6L5->setText(l5);
    ui->A6L5->setVisible(s5);
    ui->A6L5->setGeometry(ui->A6LE4->x()+ui->A6LE4->width()+10,0,ui->A6TV->columnWidth(4),20);
    ui->A6LE5->setText("");
    ui->A6LE5->setVisible(s5);
    ui->A6LE5->setGeometry(ui->A6LE4->x()+ui->A6LE4->width()+10,20,ui->A6TV->columnWidth(4),20);

    ui->A6L6->setText(l6);
    ui->A6L6->setVisible(s6);
    ui->A6L6->setGeometry(ui->A6LE5->x()+ui->A6LE5->width()+10,0,ui->A6TV->columnWidth(5),20);
    ui->A6LE6->setText("");
    ui->A6LE6->setVisible(s6);
    ui->A6LE6->setGeometry(ui->A6LE5->x()+ui->A6LE5->width()+10,20,ui->A6TV->columnWidth(5),20);

    if(!((s2==false)&&(s7))){
        ui->A6L7->setGeometry(ui->A6LE6->x()+ui->A6LE6->width()+10,0,ui->A6TV->columnWidth(6),20);
        ui->A6DE1->setGeometry(ui->A6LE6->x()+ui->A6LE6->width()+10,20,ui->A6TV->columnWidth(6),20);
        ui->A6L8->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,0,ui->A6TV->columnWidth(7),20);
        ui->A6DE2->setGeometry(ui->A6DE1->x()+ui->A6DE1->width()+10,20,ui->A6TV->columnWidth(7),20);
    }

    ui->A6L7->setText(l7);
    ui->A6L7->setVisible(s7);
    ui->A6DE1->setDate(QDate::currentDate());
    ui->A6DE1->setVisible(s7);

    ui->A6L8->setVisible(s8);
    ui->A6DE2->setDate(QDate::currentDate());
    ui->A6DE2->setVisible(s8);

    ui->A6HSB->setValue(0);

    if(ui->A6DE2->x()>ui->A6LE6->x()){
        if(ui->A6DE2->x()+ui->A6DE2->width()-611<0){
            ui->A6HSB->setMaximum(0);
        } else ui->A6HSB->setMaximum(ui->A6DE2->x()+ui->A6DE2->width()-611);
    } else {
        if(ui->A6LE6->x()+ui->A6LE6->width()-611<0){
            ui->A6HSB->setMaximum(0);
        } else ui->A6HSB->setMaximum(ui->A6LE6->x()+ui->A6LE6->width()-611);
    }
    ui->A6GBTables->setEnabled(false);
    ui->A6SA->setVisible(true);
}

void Admin::on_A6RBauth_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6auth(Network *)));
    admins6->Get("http://"+IP+":5555/authtable.json");
}
void Admin::on_A6RBdish_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6dish(Network *)));
    admins6->Get("http://"+IP+":5555/dishtable.json");
}
void Admin::on_A6RBguests_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6guests(Network *)));
    admins6->Get("http://"+IP+":5555/gueststable.json");
}
void Admin::on_A6RBingredients_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients(Network *)));
    admins6->Get("http://"+IP+":5555/ingredientstable.json");
}
void Admin::on_A6RBingredients_dish_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_dish(Network *)));
    admins6->Get("http://"+IP+":5555/ingredients_dishtable.json");
}
void Admin::on_A6RBingredients_stock_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_stock(Network *)));
    admins6->Get("http://"+IP+":5555/ingredients_stocktable.json");
}
void Admin::on_A6RBinvoice_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice(Network *)));
    admins6->Get("http://"+IP+":5555/invoicetable.json");
}
void Admin::on_A6RBinvoice_stock_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice_stock(Network *)));
    admins6->Get("http://"+IP+":5555/invoice_stocktable.json");
}
void Admin::on_A6RBmenu_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu(Network *)));
    admins6->Get("http://"+IP+":5555/menutable.json");
}
void Admin::on_A6RBmenu_dish_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu_dish(Network *)));
    admins6->Get("http://"+IP+":5555/menu_dishtable.json");
}
void Admin::on_A6RBrole_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6role(Network *)));
    admins6->Get("http://"+IP+":5555/roletable.json");
}
void Admin::on_A6RBstock_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6stock(Network *)));
    admins6->Get("http://"+IP+":5555/stocktable.json");
}
void Admin::on_A6RBtype_menu_clicked(){
    Network *admins6 = new Network;
    connect(admins6,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6type_menu(Network *)));
    admins6->Get("http://"+IP+":5555/type_menutable.json");
}

void Admin::on_A6TV_clicked(const QModelIndex &index){
if(!ui->A6SA->isVisible()){
    ui->A6TV->selectRow(index.row());
    inn=ui->A6TV->model()->index(index.row(),0);
    } else {
    QMessageBox::information(this,"Внимание!","Завершите редактирование!");
    }
}

void Admin::on_A6BI1_clicked(){
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(0,inn.column())));
}
void Admin::on_A6BI2_clicked(){
    if(inn.row()!=0)
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(inn.row()-1,inn.column())));
}
void Admin::on_A6BI3_clicked(){
    if(inn.data().isValid()){
        if(!ui->A6SA->isVisible()){
            ins=false;
            ui->A6BI8->setVisible(true);
            ui->A6BI9->setVisible(true);
            switch (SelectedTable) {
                case 1:
                    DBTableEditing(true,false,"Логин",true,"Пароль",true,"Идентификатор роли",false,"",false,"",false,"",false,"",false);
                    break;
                case 2:
                    DBTableEditing(true,false,"Идентификатор",true,"Название",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 3:
                    DBTableEditing(true,false,"Идентификатор",true,"Паспорт",true,"Фамилия",true,"Имя",true,"Отчество",true,"Телефон",true,"Дата заезда",true);
                    break;
                case 4:
                    DBTableEditing(true,false,"Идентификатор",true,"Название",true,"Необходимое кол-во",true,"Единицы измерения",false,"",false,"",false,"",false);
                    break;
                case 5:
                    DBTableEditing(true,true,"Номер блюда",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false,"",false);
                    break;
                case 6:
                    DBTableEditing(true,true,"Номер склада",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false,"",false);
                    break;
                case 7:
                    DBTableEditing(true,false,"Номер накладной",false,"",false,"",false,"",false,"",false,"",true,"Дата накладной",false);
                    break;
                case 8:
                    DBTableEditing(true,false,"Номер накладной",true,"Номер склада",true,"Номер продукта",true,"Кол-во продукта",false,"",false,"",false,"",false);
                    break;
                case 9:
                    DBTableEditing(true,false,"Номер меню",false,"",true,"Номер типа меню",true,"Кол-во блюд",false,"",false,"",true,"Дата меню",false);
                    break;
                case 10:
                    DBTableEditing(true,true,"Номер меню",true,"Номер блюда",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 11:
                    ui->A6BI8->setVisible(false);
                    ui->A6BI9->setVisible(false);
                    QMessageBox::information(this,"Внимание!","Эту таблицу нельзя редактировать!");
                    break;
                case 12:
                    DBTableEditing(true,true,"Идентификатор",true,"Название склада",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 13:
                    ui->A6BI8->setVisible(false);
                    ui->A6BI9->setVisible(false);
                    QMessageBox::information(this,"Внимание!","Эту таблицу нельзя редактировать!");
                }
        } else QMessageBox::warning(this,"Ошибка!","Завершите прошлое редактирование");
    } else QMessageBox::warning(this,"Ошибка!","Выберите строку!");
}
void Admin::on_A6BI4_clicked(){
    if(inn.row()!=ui->A6TV->model()->rowCount()-1)
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(inn.row()+1,inn.column())));
}
void Admin::on_A6BI5_clicked(){
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(ui->A6TV->model()->rowCount()-1,inn.column())));
}
void Admin::on_A6BI6_clicked(){
        if(!ui->A6SA->isVisible()){
            ins=true;
            ui->A6BI8->setVisible(true);
            ui->A6BI9->setVisible(true);
            switch (SelectedTable) {
                case 1:
                    DBTableCreate(true,"Логин",true,"Пароль",true,"Идентификатор роли",false,"",false,"",false,"",false,"",false);
                    break;
                case 2:
                    DBTableCreate(true,"Идентификатор",true,"Название",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 3:
                    DBTableCreate(true,"Идентификатор",true,"Паспорт",true,"Фамилия",true,"Имя",true,"Отчество",true,"Телефон",true,"Дата заезда",true);
                    break;
                case 4:
                    DBTableCreate(true,"Идентификатор",true,"Название",true,"Необходимое кол-во",true,"Единицы измерения",false,"",false,"",false,"",false);
                    break;
                case 5:
                    DBTableCreate(true,"Номер блюда",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false,"",false);
                    break;
                case 6:
                    DBTableCreate(true,"Номер склада",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false,"",false);
                    break;
                case 7:
                    DBTableCreate(true,"Номер накладной",false,"",false,"",false,"",false,"",false,"",true,"Дата накладной",false);
                    break;
                case 8:
                    DBTableCreate(true,"Номер накладной",true,"Номер склада",true,"Номер продукта",true,"Кол-во продукта",false,"",false,"",false,"",false);
                    break;
                case 9:
                    DBTableCreate(true,"Номер меню",false,"",true,"Номер типа меню",true,"Кол-во блюд",false,"",false,"",true,"Дата меню",false);
                    break;
                case 10:
                    DBTableCreate(true,"Номер меню",true,"Номер блюда",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 11:
                    ui->A6BI8->setVisible(false);
                    ui->A6BI9->setVisible(false);
                    QMessageBox::information(this,"Внимание!","Эту таблицу нельзя редактировать!");
                    break;
                case 12:
                    DBTableCreate(true,"Идентификатор",true,"Название склада",false,"",false,"",false,"",false,"",false,"",false);
                    break;
                case 13:
                    ui->A6BI8->setVisible(false);
                    ui->A6BI9->setVisible(false);
                    QMessageBox::information(this,"Внимание!","Эту таблицу нельзя редактировать!");
                }
        } else QMessageBox::warning(this,"Ошибка!","Завершите прошлое редактирование");
}
void Admin::on_A6BI7_clicked(){
QMessageBox::StandardButton btn=QMessageBox::question(this,"Внимание!","Вы уверены, что хотите удалить запись?",QMessageBox::Yes|QMessageBox::No);
if(btn==QMessageBox::Yes)
    switch (SelectedTable) {
        case 1:{
            QJsonObject post;
            post["table"]="auth";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///authtable.json
        case 2:{
            QJsonObject post;
            post["table"]="dish";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///dishtable.json
        case 3:{
            QJsonObject post;
            post["table"]="guests";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///gueststable.json
        case 4:{
            QJsonObject post;
            post["table"]="ingredients";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///ingredientstable.json
        case 5:{
            QJsonObject post;
            post["table"]="ingredients_dish";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(inn.row(),1);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebywhere.json", doc);
            break;
            }///ingredients_dishtable.json
        case 6:{
            QJsonObject post;
            post["table"]="ingredients_stock";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(inn.row(),1);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebywhere.json", doc);
            break;
            }///ingredients-stocktable.json
        case 7:{
            QJsonObject post;
            post["table"]="invoice";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///invoicetable.json
        case 8:{
            QJsonObject post;
            post["table"]="invoice_stock";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(inn.row(),2);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebywhere.json", doc);
            break;
            }///invoice_stocktable.json
        case 9:{
            QJsonObject post;
            post["table"]="menu";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///menutable.json
        case 10:{
            QJsonObject post;
            post["table"]="menu_dish";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(inn.row(),1);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebywhere.json", doc);
            break;
            }///menu_dishtable.json
        case 11:{
            QMessageBox::warning(this,"Ошибка!","Нельзя удалять данные из этой таблицы!");
            break;
            }///role.json
        case 12:{
            QJsonObject post;
            post["table"]="stock";
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["id"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBDelete(Network *)));
            net->Post("http://"+IP+":5555/deletebyid.json", doc);
            break;
            }///stocktable.json
        case 13:
            QMessageBox::warning(this,"Ошибка!","Нельзя удалять данные из этой таблицы!");
        }
}
void Admin::on_A6BI8_clicked(){
qDebug() << ins;
if(ins){
    switch (SelectedTable) {
        case 1:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("login").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    if(ui->A6LE2->text()!=""){
                        if((ui->A6LE3->text()=="1")||(ui->A6LE3->text()=="2")||(ui->A6LE3->text()=="3")||(ui->A6LE3->text()=="4")){
                            QJsonObject post;
                            post["table"]="auth";
                            QJsonArray vals;
                            vals.append(ui->A6LE1->text());
                            vals.append(ui->A6LE2->text());
                            vals.append(ui->A6LE3->text());
                            post["values"]=vals;
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                            net->Post("http://"+IP+":5555/insert.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","Идентификатор роли может принимать значения только 1,2,3 или 4!");
                    } else QMessageBox::warning(this,"Ошибка!","Пароль не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Такой логин уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Логин не может быть пустым!");
            break;
        case 2:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    if(ui->A6LE2->text()!=""){
                        bool accept=true;
                        for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                            if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                                accept=false;
                                break;
                            }
                        }
                        if(accept){
                            QJsonObject post;
                            post["table"]="dish";
                            QJsonArray vals;
                            vals.append(ui->A6LE1->text());
                            vals.append(ui->A6LE2->text());
                            post["values"]=vals;
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                            net->Post("http://"+IP+":5555/insert.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","Такое название уже есть!");
                    } else QMessageBox::warning(this,"Ошибка!","Название не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        case 3:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    QRegExpValidator valid(QRegExp("[0-9]+"));
                    int pos=0;
                    QString s;
                    s=ui->A6LE2->text();
                    if(valid.validate(s,pos)==QValidator::Acceptable){
                        if(ui->A6LE3->text()!=""){
                            if(ui->A6LE4->text()!=""){
                                if(ui->A6LE5->text()!=""){
                                    if(QDate::fromString(ui->A6DE1->text(),"yyyy-MM-dd")<QDate::fromString(ui->A6DE2->text(),"yyyy-MM-dd")){
                                        QJsonObject post;
                                        post["table"]="guests";
                                        QJsonArray vals;
                                        vals.append(ui->A6LE1->text());
                                        vals.append(ui->A6LE2->text());
                                        vals.append(ui->A6LE3->text());
                                        vals.append(ui->A6LE4->text());
                                        vals.append(ui->A6LE5->text());
                                        vals.append(ui->A6LE6->text());
                                        vals.append(ui->A6DE1->text());
                                        vals.append(ui->A6DE2->text());
                                        post["values"]=vals;
                                        QJsonDocument doc;
                                        doc.setObject(post);
                                        qDebug() << doc;
                                        Network *net = new Network;
                                        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                                        net->Post("http://"+IP+":5555/insert.json", doc);
                                    } else QMessageBox::warning(this,"Ошибка!","Дата отъезда должна быть позже даты заселения!");
                                } else QMessageBox::warning(this,"Ошибка!","Отчество не может быть пустым!");
                            } else QMessageBox::warning(this,"Ошибка!","Имя не может быть пустым!");
                        } else QMessageBox::warning(this,"Ошибка!","Фамилия не может быть пустой!");
                    } else QMessageBox::warning(this,"Ошибка!","Паспорт может состоять только из цифр!");
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        case 4:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    QRegExpValidator valid(QRegExp("[0-9]+"));
                    int pos=0;
                    QString s;
                    s=ui->A6LE3->text();
                    if(valid.validate(s,pos)==QValidator::Acceptable){
                        if(ui->A6LE2->text()!=""){
                            if(ui->A6LE4->text()!=""){
                                QJsonObject post;
                                post["table"]="ingredients";
                                QJsonArray vals;
                                vals.append(ui->A6LE1->text());
                                vals.append(ui->A6LE2->text());
                                vals.append(ui->A6LE3->text());
                                vals.append(ui->A6LE4->text());
                                post["values"]=vals;
                                QJsonDocument doc;
                                doc.setObject(post);
                                qDebug() << doc;
                                Network *net = new Network;
                                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                                net->Post("http://"+IP+":5555/insert.json", doc);
                            } else QMessageBox::warning(this,"Ошибка!","Единица измерения не может быть пустой!");
                        } else QMessageBox::warning(this,"Ошибка!","Название не может быть пустым!");
                    } else QMessageBox::warning(this,"Ошибка!","Необходимое кол-во на складе может состоять только из цифр!");
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        case 5:{
            QRegExpValidator valid(QRegExp("[0-9]+"));
            int pos=0;
            QString s;
            s=ui->A6LE3->text();
            if(valid.validate(s,pos)==QValidator::Acceptable){
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case5_1(Network *)));
                net->Get("http://"+IP+":5555/dishtable.json");
                } else QMessageBox::warning(this,"Ошибка!","Количество ингредиентов может состоять только из цифр!");
            }
            break;
        case 6:{
            QRegExpValidator valid(QRegExp("[0-9]+"));
            int pos=0;
            QString s;
            s=ui->A6LE3->text();
            if(valid.validate(s,pos)==QValidator::Acceptable){
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case6_1(Network *)));
                net->Get("http://"+IP+":5555/stocktable.json");
                } else QMessageBox::warning(this,"Ошибка!","Количество ингредиентов может состоять только из цифр!");
            }
            break;
        case 7:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    QJsonObject post;
                    post["table"]="invoice";
                    QJsonArray vals;
                    vals.append(ui->A6LE1->text());
                    vals.append(ui->A6DE1->text());
                    post["values"]=vals;
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                    net->Post("http://"+IP+":5555/insert.json", doc);
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        case 8:{
            QRegExpValidator valid(QRegExp("[0-9]+"));
            int pos=0;
            QString s;
            s=ui->A6LE4->text();
            if(valid.validate(s,pos)==QValidator::Acceptable){
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case8_1(Network *)));
                net->Get("http://"+IP+":5555/invoicetable.json");
                } else QMessageBox::warning(this,"Ошибка!","Количество ингредиентов может состоять только из цифр!");
            }
            break;
        case 9:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    QRegExpValidator valid(QRegExp("[0-9]+"));
                    int pos=0;
                    QString s;
                    s=ui->A6LE4->text();
                    if(valid.validate(s,pos)==QValidator::Acceptable){
                        if((ui->A6LE3->text()=="1")||(ui->A6LE3->text()=="2")||(ui->A6LE3->text()=="3")||(ui->A6LE3->text()=="4")){
                            QJsonObject post;
                            post["table"]="menu";
                            QJsonArray vals;
                            vals.append(ui->A6LE1->text());
                            vals.append(ui->A6DE1->text());
                            vals.append(ui->A6LE3->text());
                            vals.append(ui->A6LE4->text());
                            post["values"]=vals;
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                            net->Post("http://"+IP+":5555/insert.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","Идентификатор типа меню может принимать значения только 1,2,3 или 4!");
                    } else QMessageBox::warning(this,"Ошибка!","Количество порций может состоять только из цифр!");
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        case 10:{
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case10_1(Network *)));
            net->Get("http://"+IP+":5555/menutable.json");
            }
            break;
        case 12:
            if(ui->A6LE1->text()!=""){
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if(admin6.object().value("Data").toArray().at(i).toObject().value("id").toString()==ui->A6LE1->text()){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    if(ui->A6LE2->text()!=""){
                        QJsonObject post;
                        post["table"]="stock";
                        QJsonArray vals;
                        vals.append(ui->A6LE1->text());
                        vals.append(ui->A6LE2->text());
                        post["values"]=vals;
                        QJsonDocument doc;
                        doc.setObject(post);
                        qDebug() << doc;
                        Network *net = new Network;
                        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                        net->Post("http://"+IP+":5555/insert.json", doc);
                    } else QMessageBox::warning(this,"Ошибка!","Название склада не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Такой идентификатор уже есть!");
            } else QMessageBox::warning(this,"Ошибка!","Идентификатор не может быть пустым!");
            break;
        }
    } else {
    switch (SelectedTable) {
        case 1:///authtable.json
            if(ui->A6LE2->text()!=""){
                if((ui->A6LE3->text()=="1")||(ui->A6LE3->text()=="2")||(ui->A6LE3->text()=="3")||(ui->A6LE3->text()=="4")){
                    QJsonObject post;
                    post["table"]="auth";
                    QJsonArray vals;
                    vals.append(ui->A6LE1->text());
                    vals.append(ui->A6LE2->text());
                    vals.append(ui->A6LE3->text());
                    post["values"]=vals;
                    QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
                    post["where1"]=ui->A6TV->model()->data(in).toString();
                    in=ui->A6TV->model()->index(inn.row(),1);
                    post["where2"]=ui->A6TV->model()->data(in).toString();
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                    net->Post("http://"+IP+":5555/updatebywhere.json", doc);
                } else QMessageBox::warning(this,"Ошибка!","Идентификатор роли может принимать значения только 1,2,3 или 4!");
            } else QMessageBox::warning(this,"Ошибка!","Пароль не может быть пустым!");
            break;
        case 2:///dishtable.json
            if(ui->A6LE2->text()!=""){
                    QJsonObject post;
                    post["table"]="dish";
                    QJsonArray vals;
                    vals.append(ui->A6LE1->text());
                    vals.append(ui->A6LE2->text());
                    post["values"]=vals;
                    post["id"]=ui->A6LE1->text();
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                    net->Post("http://"+IP+":5555/updatebyid.json", doc);
            } else QMessageBox::warning(this,"Ошибка!","Название не может быть пустым!");
            break;
        case 3:///gueststable.json
            if(ui->A6LE2->text()!=""){
                if(ui->A6LE3->text()!=""){
                    if(ui->A6LE4->text()!=""){
                        if(ui->A6LE5->text()!=""){
                            if(QDate::fromString(ui->A6DE1->text(),"yyyy-MM-dd")<QDate::fromString(ui->A6DE2->text(),"yyyy-MM-dd")){
                                QRegExpValidator valid(QRegExp("[0-9]+"));
                                int pos=0;
                                QString s;
                                s=ui->A6LE6->text();
                                if((valid.validate(s,pos)==QValidator::Acceptable)||(ui->A6LE6->text()=="")){
                                    QJsonObject post;
                                    post["table"]="guests";
                                    QJsonArray vals;
                                    vals.append(ui->A6LE1->text());
                                    vals.append(ui->A6LE2->text());
                                    vals.append(ui->A6LE3->text());
                                    vals.append(ui->A6LE4->text());
                                    vals.append(ui->A6LE5->text());
                                    vals.append(ui->A6LE6->text());
                                    vals.append(ui->A6DE1->text());
                                    vals.append(ui->A6DE2->text());
                                    post["values"]=vals;
                                    post["id"]=ui->A6LE1->text();
                                    QJsonDocument doc;
                                    doc.setObject(post);
                                    qDebug() << doc;
                                    Network *net = new Network;
                                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                                    net->Post("http://"+IP+":5555/updatebyid.json", doc);
                                } else QMessageBox::warning(this,"Ошибка!","Телефон может состоять только из чисел!");
                            } else QMessageBox::warning(this,"Ошибка!","Дата заселения не может быть позже даты отъезда!");
                        } else QMessageBox::warning(this,"Ошибка!","Отчество не может быть пустым!");
                    } else QMessageBox::warning(this,"Ошибка!","Имя не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Фамилия не может быть пустой!");
            } else QMessageBox::warning(this,"Ошибка!","Паспорт не может быть пустым!");
            break;
        case 4:///ingredientstable.json
            if(ui->A6LE2->text()!=""){
                if(ui->A6LE3->text()!=""){
                    if(ui->A6LE4->text()!=""){
                        QRegExpValidator valid(QRegExp("[0-9]+"));
                        int pos=0;
                        QString s;
                        s=ui->A6LE3->text();
                        if(valid.validate(s,pos)==QValidator::Acceptable){
                            QJsonObject post;
                            post["table"]="ingredients";
                            QJsonArray vals;
                            vals.append(ui->A6LE1->text());
                            vals.append(ui->A6LE2->text());
                            vals.append(ui->A6LE3->text());
                            vals.append(ui->A6LE4->text());
                            post["values"]=vals;
                            post["id"]=ui->A6LE1->text();
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                            net->Post("http://"+IP+":5555/updatebyid.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","Телефон может состоять только из чисел!");
                    } else QMessageBox::warning(this,"Ошибка!","Единица измерения не может быть пустым!");
                } else QMessageBox::warning(this,"Ошибка!","Необходимое количество на складе не может быть пустой!");
            } else QMessageBox::warning(this,"Ошибка!","Название не может быть пустым!");
            break;
        case 5:///ingredients_dishtable.json
            if((ui->A6LE3->text()!="")||(ui->A6LE3->text()!="0")){
                    QRegExpValidator valid(QRegExp("[0-9]+"));
                    int pos=0;
                    QString s;
                    s=ui->A6LE3->text();
                    if(valid.validate(s,pos)==QValidator::Acceptable){
                        bool accept=true;
                        for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                            if((admin6.object().value("Data").toArray().at(i).toObject().value("id_dish").toString()==ui->A6LE1->text())&&(admin6.object().value("Data").toArray().at(i).toObject().value("id_ingredient").toString()==ui->A6LE2->text())&&(inn.row()!=i)){
                                accept=false;
                                break;
                            }
                        }
                        if(accept){
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case5_1(Network *)));
                            net->Get("http://"+IP+":5555/dishtable.json");
                        } else QMessageBox::warning(this,"Ошибка!","У этого блюда уже есть такой ингредиент!");
                    } else QMessageBox::warning(this,"Ошибка!","Количество продуктов может состоять только из чисел!");
            } else QMessageBox::warning(this,"Ошибка!","Количество продуктов не может быть пустым!");
            break;
        case 6:///ingredients-stocktable.json
            if((ui->A6LE3->text()!="")||(ui->A6LE3->text()!="0")){
                QRegExpValidator valid(QRegExp("[0-9]+"));
                int pos=0;
                QString s;
                s=ui->A6LE3->text();
                if(valid.validate(s,pos)==QValidator::Acceptable){
                    bool accept=true;
                    for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                        if((admin6.object().value("Data").toArray().at(i).toObject().value("id_stock").toString()==ui->A6LE1->text())&&(admin6.object().value("Data").toArray().at(i).toObject().value("id_ingredient").toString()==ui->A6LE2->text())&&(inn.row()!=i)){
                            accept=false;
                            break;
                        }
                    }
                    if(accept){
                        Network *net = new Network;
                        connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case6_1(Network *)));
                        net->Get("http://"+IP+":5555/stocktable.json");
                    } else QMessageBox::warning(this,"Ошибка!","На этом складе уже есть такой ингредиент!");
                } else QMessageBox::warning(this,"Ошибка!","Количество продуктов может состоять только из чисел!");
            } else QMessageBox::warning(this,"Ошибка!","Количество продуктов не может быть пустым!");
            break;
        case 7:///invoicetable.json
            {
                QJsonObject post;
                post["table"]="invoice";
                QJsonArray vals;
                vals.append(ui->A6LE1->text());
                vals.append(ui->A6DE1->text());
                post["values"]=vals;
                post["id"]=ui->A6LE1->text();
                QJsonDocument doc;
                doc.setObject(post);
                qDebug() << doc;
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                net->Post("http://"+IP+":5555/updatebyid.json", doc);
            }
            break;
        case 8:///invoice_stocktable.json
            if((ui->A6LE4->text()!="")||(ui->A6LE4->text()!="0")){
                QRegExpValidator valid(QRegExp("[0-9]+"));
                int pos=0;
                QString s;
                s=ui->A6LE4->text();
                if(valid.validate(s,pos)==QValidator::Acceptable){
                    QModelIndex in=ui->A6TV->model()->index(inn.row(),1);
                    if(ui->A6TV->model()->data(in).toString()==ui->A6LE2->text()){
                        bool accept=true;
                        for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                            if((admin6.object().value("Data").toArray().at(i).toObject().value("id_invoice").toString()==ui->A6LE1->text())&&(admin6.object().value("Data").toArray().at(i).toObject().value("id_ingredient").toString()==ui->A6LE3->text())&&(inn.row()!=i)){
                                accept=false;
                                break;
                            }
                        }
                        if(accept){
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case8_1(Network *)));
                            net->Get("http://"+IP+":5555/invoicetable.json");
                        } else QMessageBox::warning(this,"Ошибка!","В этой накладной уже есть такой ингредиент!");
                    } else QMessageBox::warning(this,"Ошибка!","В этой таблице нельзя изменять склад!");
                } else QMessageBox::warning(this,"Ошибка!","Количество продуктов может состоять только из чисел!");
            } else QMessageBox::warning(this,"Ошибка!","Количество продуктов не может быть пустым!");
            break;
        case 9:///menutable.json
            if((ui->A6LE3->text()=="1")||(ui->A6LE3->text()=="2")||(ui->A6LE3->text()=="3")||(ui->A6LE3->text()=="4")){
                    QRegExpValidator valid(QRegExp("[0-9]+"));
                    int pos=0;
                    QString s;
                    s=ui->A6LE4->text();
                    if(valid.validate(s,pos)==QValidator::Acceptable){
                        int i=0;
                        for(int j=0;j<admin6.object().value("Data").toArray().size();j++){
                            if((ui->A6DE1->text()==admin6.object().value("Data").toArray().at(j).toObject().value("date").toString())&&(ui->A6LE3->text()==admin6.object().value("Data").toArray().at(j).toObject().value("id_type").toString())){
                                i++;
                            }
                        }
                        if(i==0){
                            QJsonObject post;
                            post["table"]="menu";
                            QJsonArray vals;
                            vals.append(ui->A6LE1->text());
                            vals.append(ui->A6DE1->text());
                            vals.append(ui->A6LE3->text());
                            vals.append(ui->A6LE4->text());
                            post["values"]=vals;
                            post["id"]=ui->A6LE1->text();
                            QJsonDocument doc;
                            doc.setObject(post);
                            qDebug() << doc;
                            Network *net = new Network;
                            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                            net->Post("http://"+IP+":5555/updatebyid.json", doc);
                        } else QMessageBox::warning(this,"Ошибка!","В этот день уже есть меню с таким типом!");
                    } else QMessageBox::warning(this,"Ошибка!","Количество может состоять только из чисел!");
            } else QMessageBox::warning(this,"Ошибка!","Номер типа меню может принимать значения только 1,2,3 или 4!");
            break;
        case 10:///menu_dishtable.json
            {
                bool accept=true;
                for(int i=0;i<admin6.object().value("Data").toArray().size();i++){
                    if((admin6.object().value("Data").toArray().at(i).toObject().value("id_menu").toString()==ui->A6LE1->text())&&(admin6.object().value("Data").toArray().at(i).toObject().value("id_dish").toString()==ui->A6LE2->text())&&(inn.row()!=i)){
                        accept=false;
                        break;
                    }
                }
                if(accept){
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case10_1(Network *)));
                    net->Get("http://"+IP+":5555/menutable.json");
                } else QMessageBox::warning(this,"Ошибка!","В этом меню уже есть это блюдо!");
            }
            break;
        case 12:///stocktable.json
        if(ui->A6LE2->text()!=""){
                    QJsonObject post;
                    post["table"]="stock";
                    QJsonArray vals;
                    vals.append(ui->A6LE1->text());
                    vals.append(ui->A6LE2->text());
                    post["values"]=vals;
                    post["id"]=ui->A6LE1->text();
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                    net->Post("http://"+IP+":5555/updatebyid.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Название склада не может быть пустым!");
            }
    }
ins=false;
}
void Admin::on_A6BI9_clicked(){
    ui->A6SA->setVisible(false);
    ui->A6BI8->setVisible(false);
    ui->A6BI9->setVisible(false);
    ui->A6GBTables->setEnabled(true);
}

void Admin::on_Result_Post_UpdateDBEditing(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Данные обновлены!");
        Network *admins1 = new Network;
        ui->A6BI8->setVisible(false);
        ui->A6BI9->setVisible(false);
        ui->A6SA->setVisible(false);
        ui->A6GBTables->setEnabled(true);
        ins=false;
        switch(SelectedTable){
        case 1:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6auth(Network *)));
            admins1->Get("http://"+IP+":5555/authtable.json");
            break;
        case 2:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6dish(Network *)));
            admins1->Get("http://"+IP+":5555/dishtable.json");
            break;
        case 3:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6guests(Network *)));
            admins1->Get("http://"+IP+":5555/gueststable.json");
            break;
        case 4:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients(Network *)));
            admins1->Get("http://"+IP+":5555/ingredientstable.json");
            break;
        case 5:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_dish(Network *)));
            admins1->Get("http://"+IP+":5555/ingredients_dishtable.json");
            break;
        case 6:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_stock(Network *)));
            admins1->Get("http://"+IP+":5555/ingredients_stocktable.json");
            break;
        case 7:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice(Network *)));
            admins1->Get("http://"+IP+":5555/invoicetable.json");
            break;
        case 8:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice_stock(Network *)));
            admins1->Get("http://"+IP+":5555/invoice_stocktable.json");
            break;
        case 9:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu(Network *)));
            admins1->Get("http://"+IP+":5555/menutable.json");
            break;
        case 10:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu_dish(Network *)));
            admins1->Get("http://"+IP+":5555/menu_dishtable.json");
            break;
        case 11:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6role(Network *)));
            admins1->Get("http://"+IP+":5555/roletable.json");
            break;
        case 12:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6stock(Network *)));
            admins1->Get("http://"+IP+":5555/stocktable.json");
            break;
        case 13:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6type_menu(Network *)));
            admins1->Get("http://"+IP+":5555/type_menutable.json");
            }
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось обновить данные!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось обновить данные! ("+a->GetAnswer()+")");
            }
        }
    a->deleteLater();
}
void Admin::on_Result_Post_UpdateDBDelete(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        QMessageBox::information(this,"Успешно!","Запись удалена!");
        Network *admins1 = new Network;
        ui->A6SA->setVisible(false);
        ui->A6GBTables->setEnabled(true);
        switch(SelectedTable){
        case 1:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6auth(Network *)));
            admins1->Get("http://"+IP+":5555/authtable.json");
            break;
        case 2:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6dish(Network *)));
            admins1->Get("http://"+IP+":5555/dishtable.json");
            break;
        case 3:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6guests(Network *)));
            admins1->Get("http://"+IP+":5555/gueststable.json");
            break;
        case 4:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients(Network *)));
            admins1->Get("http://"+IP+":5555/ingredientstable.json");
            break;
        case 5:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_dish(Network *)));
            admins1->Get("http://"+IP+":5555/ingredients_dishtable.json");
            break;
        case 6:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6ingredients_stock(Network *)));
            admins1->Get("http://"+IP+":5555/ingredients_stocktable.json");
            break;
        case 7:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice(Network *)));
            admins1->Get("http://"+IP+":5555/invoicetable.json");
            break;
        case 8:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6invoice_stock(Network *)));
            admins1->Get("http://"+IP+":5555/invoice_stocktable.json");
            break;
        case 9:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu(Network *)));
            admins1->Get("http://"+IP+":5555/menutable.json");
            break;
        case 10:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6menu_dish(Network *)));
            admins1->Get("http://"+IP+":5555/menu_dishtable.json");
            break;
        case 11:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6role(Network *)));
            admins1->Get("http://"+IP+":5555/roletable.json");
            break;
        case 12:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6stock(Network *)));
            admins1->Get("http://"+IP+":5555/stocktable.json");
            break;
        case 13:
            connect(admins1,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Show6type_menu(Network *)));
            admins1->Get("http://"+IP+":5555/type_menutable.json");
            }
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось удалить запись!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось удалить запись! ("+a->GetAnswer()+")");
            }
        }
    a->deleteLater();
}
void Admin::on_A6HSB_sliderMoved(int position){
    int v=ui->A6HSB->value()-position;
    ui->A6L1->move(ui->A6L1->x()+v,0);
    ui->A6LE1->move(ui->A6LE1->x()+v,20);
    ui->A6L2->move(ui->A6L2->x()+v,0);
    ui->A6LE2->move(ui->A6LE2->x()+v,20);
    ui->A6L3->move(ui->A6L3->x()+v,0);
    ui->A6LE3->move(ui->A6LE3->x()+v,20);
    ui->A6L4->move(ui->A6L4->x()+v,0);
    ui->A6LE4->move(ui->A6LE4->x()+v,20);
    ui->A6L5->move(ui->A6L5->x()+v,0);
    ui->A6LE5->move(ui->A6LE5->x()+v,20);
    ui->A6L6->move(ui->A6L6->x()+v,0);
    ui->A6LE6->move(ui->A6LE6->x()+v,20);
    ui->A6L7->move(ui->A6L7->x()+v,0);
    ui->A6DE1->move(ui->A6DE1->x()+v,20);
    ui->A6L8->move(ui->A6L8->x()+v,0);
    ui->A6DE2->move(ui->A6DE2->x()+v,20);
    qDebug() << position ;
}

void Admin::on_Result_DBEditing_case5_1(Network *a){
        qDebug() << a->GetAnswer();
        if(a->GetAnswer()==""){
            qDebug() <<"Error";
            qDebug() << a->GetError();
            } else {
            QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
            bool accept=false;
            for(int i=0;i<JsonA.size();i++){
                if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                    accept=true;
                    break;
                }
            }
            if(accept){
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case5_2(Network *)));
                net->Get("http://"+IP+":5555/ingredientstable.json");
            } else QMessageBox::warning(this,"Ошибка!","Блюда с таким идентификатором не существует!");
        }
        a->deleteLater();
}
void Admin::on_Result_DBEditing_case5_2(Network *a){
        qDebug() << a->GetAnswer();
        if(a->GetAnswer()==""){
            qDebug() <<"Error";
            qDebug() << a->GetError();
            } else {
            QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
            bool accept=false;
            for(int i=0;i<JsonA.size();i++){
                if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                    accept=true;
                    break;
                }
            }
            if(accept){
                QJsonObject post;
                post["table"]="ingredients_dish";
                QJsonArray vals;
                vals.append(ui->A6LE1->text());
                vals.append(ui->A6LE2->text());
                vals.append(ui->A6LE3->text());
                post["values"]=vals;
                QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
                post["where1"]=ui->A6TV->model()->data(in).toString();
                in=ui->A6TV->model()->index(in.row(),1);
                post["where2"]=ui->A6TV->model()->data(in).toString();
                QJsonDocument doc;
                doc.setObject(post);
                qDebug() << doc;
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                net->Post("http://"+IP+":5555/updatebywhere.json", doc);
            } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
        }
        a->deleteLater();
}
void Admin::on_Result_DBEditing_case6_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case6_2(Network *)));
            net->Get("http://"+IP+":5555/ingredientstable.json");
        } else QMessageBox::warning(this,"Ошибка!","Подвала с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBEditing_case6_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="ingredients_stock";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE2->text());
            vals.append(ui->A6LE3->text());
            post["values"]=vals;
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(in.row(),1);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/updatebywhere.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBEditing_case8_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case8_2(Network *)));
            net->Get("http://"+IP+":5555/ingredientstable.json");
        } else QMessageBox::warning(this,"Ошибка!","Накладной с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBEditing_case8_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="invoice_stock";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE3->text());
            vals.append(ui->A6LE4->text());
            vals.append(ui->A6LE2->text());
            post["values"]=vals;
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(in.row(),2);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/updatebywhere.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBEditing_case10_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBEditing_case10_2(Network *)));
            net->Get("http://"+IP+":5555/dishtable.json");
        } else QMessageBox::warning(this,"Ошибка!","Меню с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBEditing_case10_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="menu_dish";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE2->text());
            post["values"]=vals;
            QModelIndex in=ui->A6TV->model()->index(inn.row(),0);
            post["where1"]=ui->A6TV->model()->data(in).toString();
            in=ui->A6TV->model()->index(inn.row(),1);
            post["where2"]=ui->A6TV->model()->data(in).toString();
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/updatebywhere.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Блюда с таким идентификатором не существует!");
    }
    a->deleteLater();
}

void Admin::on_A6Help_clicked(){
    QMessageBox::information(this,"Информация!","Внимание!\nЭта функция рекомендована для использования только опытными специалистами!\nНе рекомендуется ручное редактирование таблицы ingredients-stock\nПри удалении записей из таблиц, необходимо удалить все записи связанные с ней из других таблиц!");
}

void Admin::on_Result_DBCreate_case5_1(Network *a){
        qDebug() << a->GetAnswer();
        if(a->GetAnswer()==""){
            qDebug() <<"Error";
            qDebug() << a->GetError();
            } else {
            QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
            bool accept=false;
            for(int i=0;i<JsonA.size();i++){
                if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                    accept=true;
                    break;
                }
            }
            if(accept){
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case5_2(Network *)));
                net->Get("http://"+IP+":5555/ingredientstable.json");
            } else QMessageBox::warning(this,"Ошибка!","Блюда с таким идентификатором не существует!");
        }
        a->deleteLater();
}
void Admin::on_Result_DBCreate_case5_2(Network *a){
        qDebug() << a->GetAnswer();
        if(a->GetAnswer()==""){
            qDebug() <<"Error";
            qDebug() << a->GetError();
            } else {
            QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
            bool accept=false;
            for(int i=0;i<JsonA.size();i++){
                if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                    accept=true;
                    break;
                }
            }
            if(accept){
                QJsonObject post;
                post["table"]="ingredients_dish";
                QJsonArray vals;
                vals.append(ui->A6LE1->text());
                vals.append(ui->A6LE2->text());
                vals.append(ui->A6LE3->text());
                post["values"]=vals;
                QJsonDocument doc;
                doc.setObject(post);
                qDebug() << doc;
                Network *net = new Network;
                connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
                net->Post("http://"+IP+":5555/insert.json", doc);
            } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
        }
        a->deleteLater();
}
void Admin::on_Result_DBCreate_case6_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case6_2(Network *)));
            net->Get("http://"+IP+":5555/ingredientstable.json");
        } else QMessageBox::warning(this,"Ошибка!","Подвала с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case6_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="ingredients_stock";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE2->text());
            vals.append(ui->A6LE3->text());
            post["values"]=vals;
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/insert.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case8_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case8_2(Network *)));
            net->Get("http://"+IP+":5555/ingredientstable.json");
        } else QMessageBox::warning(this,"Ошибка!","Накладной с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case8_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE3->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case8_3(Network *)));
            net->Get("http://"+IP+":5555/stocktable.json");
        } else QMessageBox::warning(this,"Ошибка!","Ингредиента с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case8_3(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="invoice_stock";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE3->text());
            vals.append(ui->A6LE4->text());
            vals.append(ui->A6LE2->text());
            post["values"]=vals;
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/insert.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Склада с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case10_1(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE1->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_DBCreate_case10_2(Network *)));
            net->Get("http://"+IP+":5555/dishtable.json");
        } else QMessageBox::warning(this,"Ошибка!","Меню с таким идентификатором не существует!");
    }
    a->deleteLater();
}
void Admin::on_Result_DBCreate_case10_2(Network *a){
    qDebug() << a->GetAnswer();
    if(a->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << a->GetError();
        } else {
        QJsonArray JsonA=QJsonDocument::fromJson(a->GetAnswer().toUtf8()).object().value("Data").toArray();
        bool accept=false;
        for(int i=0;i<JsonA.size();i++){
            if(JsonA[i].toObject().value("id").toString()==ui->A6LE2->text()){
                accept=true;
                break;
            }
        }
        if(accept){
            QJsonObject post;
            post["table"]="menu_dish";
            QJsonArray vals;
            vals.append(ui->A6LE1->text());
            vals.append(ui->A6LE2->text());
            post["values"]=vals;
            QJsonDocument doc;
            doc.setObject(post);
            qDebug() << doc;
            Network *net = new Network;
            connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_Result_Post_UpdateDBEditing(Network *)));
            net->Post("http://"+IP+":5555/insert.json", doc);
        } else QMessageBox::warning(this,"Ошибка!","Блюда с таким идентификатором не существует!");
    }
    a->deleteLater();
}
