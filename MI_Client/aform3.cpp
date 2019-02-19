#include "aform3.h"
#include "ui_aform3.h"

AForm3::AForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm3)
{
    ui->setupUi(this);

    Refresh();
}

AForm3::~AForm3()
{
    delete ui;
}

void AForm3::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void AForm3::Refresh()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_dish` as `Блюдо` FROM dish");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->dishs->setModel(model);
}

void AForm3::on_Apply_clicked()
{
    if(!ui->DishEdit->text().isEmpty()){
        QSqlQuery* qry = new QSqlQuery;
        int id=1;
        qry->prepare("SELECT COUNT(id_dish) FROM dish");
        qry->exec();
        while(qry->next())
        id += qry->record().value(0).toInt();
        qDebug() << id;
        qry->prepare("INSERT INTO `dish`(`id_dish`, `title_dish`) VALUES ('"+QString::number(id)+"','"+ui->DishEdit->text()+"')");
        qry->exec();
        QMessageBox mes;
        mes.setWindowTitle("Поздравляю");
        mes.setText("Блюдо добавлено успешно!");
        mes.exec();
        Refresh();
    }
    else {
        QMessageBox::warning(this,"Внимание","Введите название Блюда!");
    }
}
