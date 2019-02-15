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
    //MySocket* socket = new MySocket("SELECT * FROM workers");
}
