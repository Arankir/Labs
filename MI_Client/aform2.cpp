#include "aform2.h"
#include "ui_aform2.h"

AForm2::AForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm2)
{
    ui->setupUi(this);

    Refresh();

}

AForm2::~AForm2()
{
    delete ui;
}

void AForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void AForm2::Refresh()
{
    QSqlQuery* qry = new QSqlQuery;
    qry->prepare("SELECT `title_ingredient` as `Ингредиент`, `unit` as `Измерение` FROM ingredients");
    qry->exec();
    model = new QSqlQueryModel;
    model->setQuery(*qry);
    ui->Ingr->setModel(model);
}

void AForm2::on_Apply_clicked()
{
    if(!ui->IngrEdit->text().isEmpty() && !ui->UnitEdit->text().isEmpty()){
        QSqlQuery* qry = new QSqlQuery;
        int id=1;
        qry->prepare("SELECT COUNT(id_ingredient) FROM ingredients");
        qry->exec();
        while(qry->next())
        id += qry->record().value(0).toInt();
        qDebug() << id;
        qry->prepare("INSERT INTO `ingredients`(`id_ingredient`, `title_ingredient`, `unit`) VALUES ('"+QString::number(id)+"','"+ui->IngrEdit->text()+"','"+ui->UnitEdit->text()+"')");
        qry->exec();
        QMessageBox mes;
        mes.setWindowTitle("Поздравляю");
        mes.setText("Ингредиент добавлен успешно!");
        mes.exec();
        Refresh();
    }
    else {
        QMessageBox::warning(this,"Внимание","Введите название ингредиента и в чем он измеряется!");
    }
}
