#include "cform3.h"
#include "ui_cform3.h"

cForm3::cForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cForm3)
{
    ui->setupUi(this);
}

cForm3::~cForm3()
{
    delete ui;
}

void cForm3::setDB(QSqlDatabase *db)
{
    this->db=db;
}
