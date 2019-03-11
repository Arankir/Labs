#include "portie.h"
#include "ui_portie.h"

Portie::Portie(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Portie)
{
    IP=ips;
    ui->setupUi(this);
}

Portie::~Portie()
{
    delete ui;
}

void Portie::on_Hide_clicked()
{

}
