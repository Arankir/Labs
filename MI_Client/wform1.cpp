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
    ui->DateChange->setDate(QDate::currentDate());
    ui->Stocks->addItem("");
    qry->prepare("SELECT * FROM stock");
    qry->exec();
    while(qry->next()){
        ui->Stocks->addItem(qry->record().value(1).toString());
    }
    ui->Ingredients->addItem("");
    qry->prepare("SELECT * FROM ingredients");
    qry->exec();
    while(qry->next()){
        ui->Ingredients->addItem(qry->record().value(1).toString());
    }
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
    QSqlQuery* qry = new QSqlQuery;
    QString sql="SELECT `invoice`.`date_invoice` as `Дата`, `stock`.`title_stock` as `Склад`, `ingredients`.`title_ingredient` as `Ингредиент`, `ingredients-stock`.`amount_ingredient` as `Кол-во`, `ingredients`.`unit` as `Ед измерения` FROM `invoice` INNER JOIN (`stock` INNER JOIN ((`ingredients` INNER JOIN `ingredients-stock` ON `ingredients`.`id_ingredient` = `ingredients-stock`.`id_ingredient`) INNER JOIN `invoice-stock` ON `ingredients`.`id_ingredient` = `invoice-stock`.`id_ingredient`) ON (`stock`.`id_stock` = `invoice-stock`.`id_stock`) AND (`stock`.`id_stock` = `ingredients-stock`.`id_stock`)) ON `invoice`.`id_invoice` = `invoice-stock`.`id_invoice`";
    switch (Date) {
    case 1:{
        sql+=" WHERE (`invoice`.`date_invoice`!=\"\")";
        break;}
    case 2:{
        sql+=" WHERE (`invoice`.`date_invoice`<=\""+ui->DateChange->date().toString("yyyy-MM-dd")+"\")";
        break;}
    case 3:{
        sql+=" WHERE (`invoice`.`date_invoice`=\""+ui->DateChange->date().toString("yyyy-MM-dd")+"\")";
        break;}
    case 4:{
        sql+=" WHERE (`invoice`.`date_invoice`>=\""+ui->DateChange->date().toString("yyyy-MM-dd")+"\")";
        break;}
    }
    if(ui->Stocks->currentText().isEmpty())
        sql+=" AND (`stock`.`title_stock`!=\"\")"; else
        sql+=" AND (`stock`.`title_stock`=\""+ui->Stocks->currentText()+"\")";
    if(ui->Ingredients->currentText().isEmpty())
        sql+=" AND (`ingredients`.`title_ingredient`!=\"\")"; else
        sql+=" AND (`ingredients`.`title_ingredient`=\""+ui->Ingredients->currentText()+"\")";
    switch (Ingr) {
    case 1:{
        break;}
    case 2:{
        sql+=" AND (`ingredients-stock`.`amount_ingredient`>0)";
        break;}
    case 3:{
        sql+=" AND (`ingredients-stock`.`amount_ingredient`<0)";
        break;}
    }
    qDebug() << sql;
    //    qry->prepare(" AND (([ingredients-stock].amount_ingredient)>0))");
    qry->prepare(sql);
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->StockChangeTable->setModel(model);
}

void Wform1::on_RBAllDate_clicked()
{
    Date=1;
}

void Wform1::on_RBBDate_clicked()
{
    Date=2;
}

void Wform1::on_RBInDate_clicked()
{
    Date=3;
}

void Wform1::on_RBADate_clicked()
{
    Date=4;
}

void Wform1::on_RBAll_clicked()
{
    Ingr=1;
}

void Wform1::on_RBInc_clicked()
{
    Ingr=2;
}

void Wform1::on_RBDec_clicked()
{
    Ingr=3;
}
