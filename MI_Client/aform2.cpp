#include "aform2.h"
#include "ui_aform2.h"

AForm2::AForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm2)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_ingredient` as `Ингредиент`, `unit` as `Измерение` FROM ingredients");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->Ingr->setModel(model);

}

AForm2::~AForm2()
{
    delete ui;
}

void AForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}
