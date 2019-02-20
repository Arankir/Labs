#include "cform2.h"
#include "ui_cform2.h"

CForm2::CForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm2)
{
    ui->setupUi(this);

    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `ingredients`.`title_ingredient` as `ингредиент`, `stock`.`title_stock` as `склад`, `ingredients-stock`.`amount_ingredient` as `количество`, `ingredients`.`unit` as `измерение` FROM `ingredients-stock`INNER JOIN `ingredients` ON `ingredients-stock`.`id_ingredient`=`ingredients`.`id_ingredient`INNER JOIN `stock` ON `ingredients-stock`.`id_stock` = `stock`.`id_stock`");
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

void CForm2::on_Search_clicked()
{
    QString query = "SELECT `ingredients`.`title_ingredient` as `ингредиент`, `stock`.`title_stock` as `склад`, `ingredients-stock`.`amount_ingredient` as `количество`, `ingredients`.`unit` as `измерение` FROM `ingredients-stock`INNER JOIN `ingredients` ON `ingredients-stock`.`id_ingredient`=`ingredients`.`id_ingredient`INNER JOIN `stock` ON `ingredients-stock`.`id_stock` = `stock`.`id_stock` ";
    if(ui->IngredientEdit->text().isEmpty()){
        query += "WHERE `ingredients`.`title_ingredient` != \"\" ";
    }
    else {
        query += "WHERE `ingredients`.`title_ingredient` = '"+ ui->IngredientEdit->text() +"' ";
    }

    if(ui->stockEdit->text().isEmpty()){
        query += "AND `stock`.`title_stock` != \"\" ";
    }
    else {
        query += "AND `stock`.`title_stock` = '"+ ui->stockEdit->text() +"' ";
    }

    if(ui->countEdit->text().isEmpty()){
        query += "AND `ingredients-stock`.`amount_ingredient` != \"\" ";
    }
    else {
        query += "AND `ingredients-stock`.`amount_ingredient` = "+ ui->countEdit->text() +" ";
    }

    QSqlQuery *qry = new QSqlQuery;
    qry->prepare(query);
    qry->exec();
    model->setQuery(*qry);
    ui->IngredientsTable->setModel(model);
}
