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

void Cook::on_pushButton_clicked()
{
    Form3=new q123;
    QGridLayout *l = new QGridLayout;
    l->addWidget(Form3);
    ui->widget->setLayout(l);
    ui->widget->show();
    //MySocket* socket = new MySocket("SELECT * FROM workers");
}

void Cook::on_pushButton_6_clicked()
{
    ui->widget->hide();
}
