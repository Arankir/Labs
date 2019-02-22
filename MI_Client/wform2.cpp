#include "wform2.h"
#include "ui_wform2.h"

Wform2::Wform2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wform2)
{
    ui->setupUi(this);
    QWidget* widget = new QWidget;
    QFormLayout *layout = new QFormLayout;
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT * FROM ingredients");
    qry->exec();
    while(qry->next()){
        QCheckBox *chb = new QCheckBox(this);
        chb->setText(qry->record().value(1).toString()+" ("+qry->record().value(2).toString()+")");
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
    }
    widget->setLayout(layout);
    ui->AllIngredients->setWidget(widget);

    qry->prepare("SELECT * FROM stock");
    qry->exec();
    while(qry->next()){
        ui->Stocks->addItem(qry->record().value(1).toString());
    }


}

Wform2::~Wform2()
{
    delete ui;
}

void Wform2::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void Wform2::chbChange(int state){
    QCheckBox* chb = (QCheckBox*) sender();
    QRegExp exp("[1-9]{1}[0-9]{0,10}");
    if(state == 2){
        ingredients.push_back(chb);
        QWidget* widget2 = new QWidget;
        QFormLayout* layout = new QFormLayout;
        for(int i=0; i<ingredients.size();i++){
            QHBoxLayout* layouth = new QHBoxLayout;
            QLabel* lb1 = new QLabel;
            lb1->setText(ingredients[i]->text());
            layouth->addWidget(lb1);
            QLineEdit* LiEd = new QLineEdit();
            LiEd->setObjectName(ingredients[i]->text().rightJustified(ingredients[i]->text().indexOf(" ("), '.', true));
            LiEd->setValidator(new QRegExpValidator(exp,this));
            layouth->addWidget(LiEd);
            QWidget* widget = new QWidget;
            widget->setLayout(layouth);
            layout->addWidget(widget);
        }
        widget2->setLayout(layout);
        ui->IngredientsInStock->setWidget(widget2);
    } else {
        for(int i=0; i<ingredients.size();i++){
            if (ingredients[i] == chb){
                ingredients.takeAt(i);
            }
        }
        QFormLayout* layout = new QFormLayout;
        QWidget* widget2 = new QWidget;
        for(int i=0; i<ingredients.size();i++){
            QHBoxLayout* layouth = new QHBoxLayout;
            QLabel* lb1 = new QLabel;
            lb1->setText(ingredients[i]->text());
            layouth->addWidget(lb1);
            QLineEdit* LiEd = new QLineEdit();
            LiEd->setObjectName(ingredients[i]->text().rightJustified(ingredients[i]->text().indexOf(" ("), '.', true));
            LiEd->setValidator(new QRegExpValidator(exp,this));
            layouth->addWidget(LiEd);
            QWidget* widget = new QWidget;
            widget->setLayout(layouth);
            layout->addWidget(widget);
        }
        widget2->setLayout(layout);
        ui->IngredientsInStock->setWidget(widget2);
    }
}

void Wform2::on_pushButton_clicked()
{
    QSqlQuery *qry = new QSqlQuery;
    QSqlQuery *qry_stock = new QSqlQuery;
    QSqlQuery *qry_ing = new QSqlQuery;
    qry->prepare("SELECT * FROM `invoice` WHERE (`id_invoice`=\""+ui->NumberInvoice->text()+"\")");
    qry->exec();
    if (qry->size()==0){
        qry->prepare("INSERT INTO `invoice`(`id_invoice`, `date_invoice`) VALUES ('"+ui->NumberInvoice->text()+"','"+ui->DateInvoice->text()+"')");
        qry->exec();
        qry_stock->prepare("SELECT * FROM `stock` WHERE (`title_stock`=\""+ui->Stocks->currentText()+"\")");
        qry_stock->exec();
        qry_stock->next();
        while(ingredients.size()>0){
            QCheckBox *s=ingredients.takeFirst();
            qry_ing->prepare("SELECT * FROM `ingredients` WHERE (`title_ingredient`=\""+s->text().rightJustified(s->text().indexOf(" ("), '.', true)+"\")");
            qry_ing->exec();
            qry_ing->next();
            qry->prepare("INSERT INTO `invoice-stock`(`id_invoice`,`id_ingredient`,`amount_ingredient`,`id_stock`) VALUES ('"+ui->NumberInvoice->text()+"','"+qry_ing->record().value(0).toString()+"','"+findChild<QLineEdit*>(s->text().rightJustified(s->text().indexOf(" ("), '.', true))->text()+"','"+qry_stock->record().value(0).toString()+"')");
            qry->exec();
        }
        QMessageBox mes;
        mes.setWindowTitle("Поздравляю!");
        mes.setText("Накладная добавлена успешно!");
        mes.exec();
    } else QMessageBox::warning(this,"Внимание","Накладная с таким номером уже существует!");
   // findChild<First *>("first")
}
