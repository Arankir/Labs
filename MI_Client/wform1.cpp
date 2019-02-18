#include "wform1.h"
#include "ui_wform1.h"

Wform1::Wform1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wform1)
{
    ui->setupUi(this);
    //DateChange->DateTime=0;
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `invoice`.`date_invoice` as `Дата`, `stock`.`title_stock` as `Склад`, `ingredients`.`title_ingredient` as `Ингредиент`, `ingredients-stock`.`amount_ingredient` as `Кол-во`, `ingredients`.`unit` as `Ед измерения` FROM `invoice` INNER JOIN (`stock` INNER JOIN ((`ingredients` INNER JOIN `ingredients-stock` ON `ingredients`.`id_ingredient` = `ingredients-stock`.`id_ingredient`) INNER JOIN `invoice-stock` ON `ingredients`.`id_ingredient` = `invoice-stock`.`id_ingredient`) ON (`stock`.`id_stock` = `invoice-stock`.`id_stock`) AND (`stock`.`id_stock` = `ingredients-stock`.`id_stock`)) ON `invoice`.`id_invoice` = `invoice-stock`.`id_invoice`");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->StockChangeTable->setModel(model);

//    SELECT `invoice`.`date_invoice`, `stock`.`title_stock`, `ingredients`.`title_ingredient`, `ingredients-stock`.`amount_ingredient`, `ingredients`.`unit` FROM `invoice` INNER JOIN (`stock` INNER JOIN ((`ingredients` INNER JOIN `ingredients-stock` ON `ingredients`.`id_ingredient` = `ingredients-stock`.`id_ingredient`) INNER JOIN `invoice-stock` ON `ingredients`.`id_ingredient` = `invoice-stock`.`id_ingredient`) ON (`stock`.`id_stock` = `invoice-stock`.`id_stock`) AND (`stock`.`id_stock` = `ingredients-stock`.`id_stock`)) ON `invoice`.`id_invoice` = `invoice-stock`.`id_invoice`
//    WHERE (((invoice.date_invoice)="1") AND ((stock.title_stock)="2") AND ((ingredients.title_ingredient)="3") AND (([ingredients-stock].amount_ingredient)>0));

}

Wform1::~Wform1()
{
    delete ui;
}

void Wform1::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void Wform1::on_ApplyStockChangeFilter_clicked()
{
//   QSqlQuery* qry = new QSqlQuery;

//    qry->prepare("SELECT `invoice`.`date_invoice` as `Дата`, `stock`.`title_stock` as `Склад`, `ingredients`.`title_ingredient` as `Ингредиент`, `ingredients-stock`.`amount_ingredient` as `Кол-во`, `ingredients`.`unit` as `Ед измерения` FROM `invoice` INNER JOIN (`stock` INNER JOIN ((`ingredients` INNER JOIN `ingredients-stock` ON `ingredients`.`id_ingredient` = `ingredients-stock`.`id_ingredient`) INNER JOIN `invoice-stock` ON `ingredients`.`id_ingredient` = `invoice-stock`.`id_ingredient`) ON (`stock`.`id_stock` = `invoice-stock`.`id_stock`) AND (`stock`.`id_stock` = `ingredients-stock`.`id_stock`)) ON `invoice`.`id_invoice` = `invoice-stock`.`id_invoice` WHERE (((invoice.date_invoice)=\""+DateChange->DateTime()+"\") AND ((stock.title_stock)=\""+LineStock->text()+"\") AND ((ingredients.title_ingredient)=\""+LineIngredient->text()+"\") AND (([ingredients-stock].amount_ingredient)>0))");

//    qry->exec();
//    model = new QSqlQueryModel;
//    model->setQuery(*qry);
//    ui->StockChangeTable->setModel(model);
}
