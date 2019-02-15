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

void Cook::on_whatchDish_clicked()
{
    QVBoxLayout *layout = new QVBoxLayout;
    cform1 = new CForm1;
    cform1->setDB(db);
    layout->addWidget(cform1);
    ui->widget->setLayout(layout);
    ui->widget->show();
}

void Cook::on_pushButton_2_clicked()
{
    QVBoxLayout *layout = new QVBoxLayout;
    cform2 = new CForm2;
    cform2->setDB(db);
    layout->addWidget(cform2);
    ui->widget->setLayout(layout);
    ui->widget->show();
}
