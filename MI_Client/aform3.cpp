#include "aform3.h"
#include "ui_aform3.h"

AForm3::AForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm3)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_dish` as `Блюдо` FROM dish");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->dishs->setModel(model);
}

AForm3::~AForm3()
{
    delete ui;
}

void AForm3::setDB(QSqlDatabase *db)
{
    this->db=db;
}
