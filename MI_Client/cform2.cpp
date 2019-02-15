#include "cform2.h"
#include "ui_cform2.h"

CForm2::CForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm2)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT * FROM ingtable");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

CForm2::~CForm2()
{
    delete ui;
}

void CForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}
