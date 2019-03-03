#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{

    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    QGridLayout* cookL = new QGridLayout;
    QGridLayout* WhkL = new QGridLayout;


    cook= new Cook();
    cookL->addWidget(cook);
    //cook->setDB(db);
    connect(cook,SIGNAL(loginOpen()),this,SLOT(on_LogOut_clicked()));


    whk = new Warehousekeeper();
    WhkL->addWidget(whk);
    whk->setDB(db);
    connect(whk,SIGNAL(loginOpen()),this,SLOT(on_LogOut_clicked()));

    ui->Cook->setLayout(cookL);
    ui->Whk->setLayout(WhkL);

    QVBoxLayout *layout1 = new QVBoxLayout;
    aform1 = new AForm1;
    aform1->setDB(db);
    layout1->addWidget(aform1);
    ui->RegWid->setLayout(layout1);

    QVBoxLayout *layout2 = new QVBoxLayout;
    aform2 = new AForm2;
    aform2->setDB(db);
    layout2->addWidget(aform2);
    ui->AddIngWid->setLayout(layout2);

    QVBoxLayout *layout3 = new QVBoxLayout;
    aform3 = new AForm3;
    aform3->setDB(db);
    layout3->addWidget(aform3);
    ui->AddDishWid->setLayout(layout3);

    QVBoxLayout *layout4 = new QVBoxLayout;
    aform4 = new AForm4;
    aform4->setDB(db);
    layout4->addWidget(aform4);
    ui->AddStockWid->setLayout(layout4);

    Admin::on_hide_clicked();

//    QJsonObject dish;
//    dish["title"] = "СуперСуп";

//    QJsonArray arr_ing;
//    QJsonObject ing;
//    ing["title"]="Морковь";
//    ing["amount"]="5";
//    arr_ing.append(ing);
//    QJsonObject ing2;
//    ing2["title"]="Свекла";
//    ing2["amount"]="5";
//    arr_ing.append(ing2);

//    dish["ingredients"]=arr_ing;
//    QJsonDocument doc;
//    doc.setObject(dish);

//    QByteArray reqData;
//    reqData = QString(doc.toJson()).toLocal8Bit();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void Admin::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}

void Admin::on_hide_clicked()
{
    ui->BdWid->hide();
    ui->RegWid->hide();
    ui->AddDishWid->hide();
    ui->AddIngWid->hide();
    ui->AddStockWid->hide();
    ui->ChangeReqWid->hide();
}

void Admin::on_Reg_clicked()
{
    Admin::on_hide_clicked();
    ui->RegWid->show();
}


void Admin::on_AddIng_clicked()
{
    Admin::on_hide_clicked();
    ui->AddIngWid->show();
}

void Admin::on_AddDish_clicked()
{
    Admin::on_hide_clicked();
    ui->AddDishWid->show();
}

void Admin::on_AddStock_clicked()
{
    Admin::on_hide_clicked();
    ui->AddStockWid->show();
}
