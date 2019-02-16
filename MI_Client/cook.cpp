#include "cook.h"
#include "ui_cook.h"

Cook::Cook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cook)
{
    ui->setupUi(this);
}



Cook::~Cook()
{
    delete ui;
}



void Cook::setDB(QSqlDatabase *db){
    this->db = db;
}

void Cook::on_Hide_clicked()
{
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
}

void Cook::on_whatchDish_clicked()
{
    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
    QVBoxLayout *layout = new QVBoxLayout;
    cform1 = new CForm1;
    cform1->setDB(db);
    layout->addWidget(cform1);
    ui->widget->setLayout(layout);
    ui->widget->show();
}


void Cook::on_whatchIngredients_clicked()
{
    ui->widget->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
    QVBoxLayout *layout = new QVBoxLayout;
    cform2 = new CForm2;
    cform2->setDB(db);
    layout->addWidget(cform2);
    ui->widget_2->setLayout(layout);
    ui->widget_2->show();
}



void Cook::on_createMenu_clicked()
{
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_4->hide();
    QVBoxLayout *layout = new QVBoxLayout;
    cform3 = new cForm3;
    cform3->setDB(db);
    layout->addWidget(cform3);
    ui->widget_3->setLayout(layout);
    ui->widget_3->show();
}

void Cook::on_prevMenu_clicked()
{
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_3->hide();
    QVBoxLayout *layout = new QVBoxLayout;
    cform4 = new CForm4;
    cform4->setDB(db);
    layout->addWidget(cform4);
    ui->widget_4->setLayout(layout);
    ui->widget_4->show();
}

void Cook::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}
