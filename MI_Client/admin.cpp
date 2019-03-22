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
        inn=ui->A6TV->model()->index(0,0);
        SelectedTable=1;
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
        SelectedTable=2;
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
        SelectedTable=3;
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
        SelectedTable=4;
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
        SelectedTable=5;
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
        SelectedTable=6;
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
        SelectedTable=7;
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
        SelectedTable=8;
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
        SelectedTable=9;
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
        SelectedTable=10;
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
        SelectedTable=11;
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
        SelectedTable=12;
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
        SelectedTable=13;
        }
}

void Admin::DBTableEditing(bool lv1, bool le1, QString l1, bool lv2, QString l2, bool lv3, QString l3, bool lv4, QString l4, bool lv5, QString l5, bool lv6, QString l6, bool lv7){
    ui->A6L1->text()=l1;
    ui->A6LE1->text().clear();
    ui->A6LE1->setEnabled(le1);
    ui->A6L1->setVisible(lv1);
    ui->A6LE1->setVisible(lv1);
    ui->A6L1->setText(l1);
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

    ui->A6DE1->setDate(QDate::currentDate());
    ui->A6L7->setVisible(lv7);
    ui->A6DE1->setVisible(lv7);

    ui->A6DE2->setDate(QDate::currentDate());
    ui->A6L8->setVisible(lv7);
    ui->A6DE2->setVisible(lv7);

    QModelIndex in=inn;
    ui->A6LE1->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),1);
    ui->A6LE2->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),2);
    ui->A6LE3->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),3);
    ui->A6LE4->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),4);
    ui->A6LE5->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),5);
    ui->A6LE6->setText(ui->A6TV->model()->data(in).toString());
    in=ui->A6TV->model()->index(in.row(),6);
    ui->A6DE1->setDate(ui->A6TV->model()->data(in).toDate());
    in=ui->A6TV->model()->index(in.row(),7);
    ui->A6DE2->setDate(ui->A6TV->model()->data(in).toDate());
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

void Admin::on_A6BI1_clicked()
{
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(0,inn.column())));
}
void Admin::on_A6BI2_clicked()
{
    if(inn.row()!=0)
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(inn.row()-1,inn.column())));
}
void Admin::on_A6BI3_clicked(){
    if(inn.data().isValid()){
        if(!ui->A6SA->isVisible()){
            ui->A6BI8->setVisible(true);
            ui->A6BI9->setVisible(true);
            switch (SelectedTable) {
                case 1:
                    DBTableEditing(true,false,"Логин",true,"Пароль",true,"Идентификатор роли",false,"",false,"",false,"",false);
                    break;
                case 2:
                    DBTableEditing(true,false,"Идентификатор",true,"Название",false,"",false,"",false,"",false,"",false);
                    break;
                case 3:
                    DBTableEditing(true,false,"Идентификатор",true,"Паспорт",true,"Фамилия",true,"Имя",true,"Отчество",true,"Телефон",true);
                    break;
                case 4:
                    DBTableEditing(true,false,"Идентификатор",true,"Название",true,"Необходимое кол-во",true,"Единицы измерения",false,"",false,"",false);
                    break;
                case 5:
                    DBTableEditing(true,true,"Номер блюда",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false);
                    break;
                case 6:
                    DBTableEditing(true,true,"Номер склада",true,"Номер ингредиента",true,"Кол-во ингредиента",false,"",false,"",false,"",false);
                    break;
                case 7:
                    DBTableEditing(true,false,"Номер накладной",true,"Дата накладной",false,"",false,"",false,"",false,"",false);
                    break;
                case 8:
                    DBTableEditing(true,false,"Номер накладной",true,"Номер склада",true,"Номер продукта",true,"Кол-во продукта",false,"",false,"",false);
                    break;
                case 9:
                    DBTableEditing(true,false,"Номер меню",true,"Номер типа меню",true,"Дата меню",true,"Кол-во блюд",false,"",false,"",false);
                    break;
                case 10:
                    DBTableEditing(true,true,"Номер меню",true,"Номер блюда",false,"",false,"",false,"",false,"",false);
                    break;
                case 11:
                    ui->A6BI8->setVisible(false);
                    ui->A6BI9->setVisible(false);
                    QMessageBox::information(this,"Внимание!","Эту таблицу нельзя редактировать!");
                    break;
                case 12:
                    DBTableEditing(true,true,"Идентификатор",true,"Название склада",false,"",false,"",false,"",false,"",false);
                    break;
                case 13:
                    DBTableEditing(true,true,"Идентификатор",true,"Название типа меню",false,"",false,"",false,"",false,"",false);
                }
        } else QMessageBox::warning(this,"Ошибка!","Завершите прошлое редактирование");
    } else QMessageBox::warning(this,"Ошибка!","Выберите строку!");
}
void Admin::on_A6BI4_clicked()
{
    if(inn.row()!=ui->A6TV->model()->rowCount()-1)
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(inn.row()+1,inn.column())));
}
void Admin::on_A6BI5_clicked()
{
    on_A6TV_clicked(QModelIndex(ui->A6TV->model()->index(ui->A6TV->model()->rowCount()-1,inn.column())));
}
void Admin::on_A6BI6_clicked()
{

}
void Admin::on_A6BI7_clicked()
{

}
void Admin::on_A6BI8_clicked()
{

    ui->A6BI8->setVisible(false);
    ui->A6BI9->setVisible(false);
}
void Admin::on_A6BI9_clicked()
{
    ui->A6SA->setVisible(false);
    ui->A6BI8->setVisible(false);
    ui->A6BI9->setVisible(false);
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
}
