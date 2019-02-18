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

    //запрос для фильтра "SELECT `ingredients`.`title_ingredient`, `stock`.`title_stock`, `ingredients-stock`.`amount_ingredient`, `ingredients-stock`.`unit` FROM `stock` INNER JOIN (`ingredients` INNER JOIN `ingredients-stock` ON `ingredients.id_ingredient` = `ingredients-stock`.`id_ingredient`) ON `stock`.`id_stock` = `ingredients-stock`.`id_stock` WHERE (((`ingredients`.`title_ingredient`)="Название блюда") AND ((`stock`.`title_stock`)="Название склада") AND ((`ingredients-stock`.`amount_ingredient`)="кол-во ингредиентов"))"
    //и в верхний запрос добавь unit (но фильтр по нему делать не надо, просто, чтобы было вижно в чем измеряется)
    //ну и кнопку, которая будет применять фильтр
}

CForm2::~CForm2()
{
    delete ui;
}

void CForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}
