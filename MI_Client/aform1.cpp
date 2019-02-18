#include "aform1.h"
#include "ui_aform1.h"

AForm1::AForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm1)
{
    ui->setupUi(this);
}

AForm1::~AForm1()
{
    delete ui;
}

void AForm1::setDB(QSqlDatabase *db)
{
    this->db=db;
}
