#include "warehousekeeper.h"
#include "ui_warehousekeeper.h"

Warehousekeeper::Warehousekeeper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warehousekeeper)
{
    ui->setupUi(this);
    QVBoxLayout *layout1 = new QVBoxLayout;
    wform1 = new CForm2;
    wform1->setDB(db);
    layout1->addWidget(wform1);
    ui->widget->setLayout(layout1);

    QVBoxLayout *layout2 = new QVBoxLayout;
    wform2 = new Wform1;
    wform2->setDB(db);
    layout2->addWidget(wform2);
    ui->widget_2->setLayout(layout2);

    QVBoxLayout *layout3 = new QVBoxLayout;
    wform3 = new Wform2;
    wform3->setDB(db);
    layout3->addWidget(wform3);
    ui->widget_3->setLayout(layout3);

    Warehousekeeper::on_Hide_clicked();
}

Warehousekeeper::~Warehousekeeper()
{
    delete ui;
}

void Warehousekeeper::setDB(QSqlDatabase *db){
    this->db = db;
}

void Warehousekeeper::on_LogOut_clicked()
{
    emit loginOpen();
    this->hide();
}

void Warehousekeeper::on_Hide_clicked()
{
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_3->hide();
}

void Warehousekeeper::on_watchStock_clicked()
{
    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget->show();
}

void Warehousekeeper::on_whatchStockChanges_clicked()
{
    ui->widget->hide();
    ui->widget_3->hide();
    ui->widget_2->show();
}

void Warehousekeeper::on_AddIngredients_clicked()
{
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_3->show();
}
