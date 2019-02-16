#include "cform4.h"
#include "ui_cform4.h"

CForm4::CForm4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm4)
{
    ui->setupUi(this);
    //qDebug() << ui->calendar->selectedDate().toString("dd-MM-yyyy"); дата в нужном формате
}

CForm4::~CForm4()
{
    delete ui;
}

void CForm4::setDB(QSqlDatabase *db)
{
    this->db=db;
}


