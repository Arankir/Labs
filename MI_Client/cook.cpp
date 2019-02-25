#include "cook.h"
#include "ui_cook.h"

Cook::Cook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cook)
{
    ui->setupUi(this);
    QVBoxLayout *layout1 = new QVBoxLayout;
    cform1 = new CForm1;
    cform1->setDB(db);
    layout1->addWidget(cform1);
    ui->widget->setLayout(layout1);

    QVBoxLayout *layout2 = new QVBoxLayout;
    cform2 = new CForm2;
    cform2->setDB(db);
    layout2->addWidget(cform2);
    ui->widget_2->setLayout(layout2);

    QVBoxLayout *layout3 = new QVBoxLayout;
    cform3 = new cForm3;
    cform3->setDB(db);
    layout3->addWidget(cform3);
    ui->widget_3->setLayout(layout3);

    QVBoxLayout *layout4 = new QVBoxLayout;
    cform4 = new CForm4;
    cform4->setDB(db);
    layout4->addWidget(cform4);
    ui->widget_4->setLayout(layout4);

    Cook::on_Hide_clicked();
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
    Cook::on_Hide_clicked();
    ui->widget->show();
}


void Cook::on_whatchIngredients_clicked()
{
    Cook::on_Hide_clicked();
    ui->widget_2->show();
}



void Cook::on_createMenu_clicked()
{
    Cook::on_Hide_clicked();
    ui->widget_3->show();
}

void Cook::on_prevMenu_clicked()
{
    Cook::on_Hide_clicked();
    ui->widget_4->show();
}

void Cook::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}
