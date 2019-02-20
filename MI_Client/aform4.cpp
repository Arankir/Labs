#include "aform4.h"
#include "ui_aform4.h"

AForm4::AForm4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm4)
{
    ui->setupUi(this);

    Refresh();
}

AForm4::~AForm4()
{
    delete ui;
}

void AForm4::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void AForm4::Refresh()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_stock` as `Склад` FROM stock");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->stock->setModel(model);
}

void AForm4::on_Apply_clicked()
{
    if(!ui->StockEdit->text().isEmpty()){
        QSqlQuery* qry = new QSqlQuery;
        int id=1;
        qry->prepare("SELECT COUNT(id_stock) FROM stock");
        qry->exec();
        while(qry->next())
        id += qry->record().value(0).toInt();
        qDebug() << id;
        qry->prepare("INSERT INTO `stock`(`id_stock`, `title_stock`) VALUES ('"+QString::number(id)+"','"+ui->StockEdit->text()+"')");
        qry->exec();
        QMessageBox mes;
        mes.setWindowTitle("Поздравляю");
        mes.setText("Склад добавлен успешно!");
        mes.exec();
        Refresh();
    }
    else {
        QMessageBox::warning(this,"Внимание","Введите название Склада!");
    }
}
