#include "cform2.h"
#include "ui_cform2.h"

CForm2::CForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm2)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `ingredients`.`title_ingredient` as `ингредиент`, `stock`.`title_stock` as `склад`, `ingredients-stock`.`amount_ingredient` as `количество` FROM `ingredients-stock`INNER JOIN `ingredients` ON `ingredients-stock`.`id_ingredient`=`ingredients`.`id_ingredient`INNER JOIN `stock` ON `ingredients-stock`.`id_stock` = `stock`.`id_stock`");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->IngredientsTable->setModel(model);
}

CForm2::~CForm2()
{
    delete ui;
}

void CForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}
