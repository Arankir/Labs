#include "aform4.h"
#include "ui_aform4.h"

AForm4::AForm4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm4)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_stock` as `Склад` FROM stock");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->stock->setModel(model);
}

AForm4::~AForm4()
{
    delete ui;
}

void AForm4::setDB(QSqlDatabase *db)
{
    this->db=db;
}
