#include "aform3.h"
#include "ui_aform3.h"

AForm3::AForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm3)
{
    ui->setupUi(this);

    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT * FROM ingredients");
    qry->exec();
    while(qry->next()){
        ui->IngrBox->addItem(qry->record().value(1).toString());
    }

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

        qry->prepare("INSERT INTO `dish`(`id_dish`, `title_dish`) VALUES ('"+QString::number(id)+"','"+ui->DishEdit->text()+"')");
        qry->exec();

        for (int i=0;i<ingredients.size();i++) {
            qry->prepare("INSERT INTO `ingredients-dish`(`id_dish`, `id_ingredient`, `amount_ingredient`) VALUES ((SELECT `id_dish` FROM `dish` WHERE `dish`.`title_dish`=\""+ui->DishEdit->text()+"\"),(SELECT `id_ingredient` FROM `ingredients` WHERE `ingredients`.`title_ingredient`=\""+ingredients[i].first+"\"),'"+QString::number(ingredients[i].second)+"')");
            qry->exec();
        }
        QMessageBox msg;
        msg.setText("Блюдо успешно добавлено");
        msg.exec();
        Refresh();
    }
}

void AForm3::on_Add_clicked()
{
    if(!ui->CountEdit->text().isEmpty()){
        QPair <QString,int> pair;
        pair.first = ui->IngrBox->currentText();
        pair.second = ui->CountEdit->text().toInt();
        ingredients.push_back(pair);
        QGridLayout* layout = new QGridLayout;
        for(int i=0; i<ingredients.size();i++){
            QLabel* lb = new QLabel;
            lb->setText(ingredients[i].first + " " + QString::number(ingredients[i].second));
            layout->addWidget(lb);
        }
        QWidget* widget = new QWidget;
        widget->setLayout(layout);
        ui->Ingredients->setWidget(widget);

    }
}
