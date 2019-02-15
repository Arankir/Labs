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
