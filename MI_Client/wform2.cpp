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
        chb->setText(qry->record().value(1).toString());
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
    }
    widget->setLayout(layout);
    ui->AllIngredients->setWidget(widget);


/*    qry->prepare("SELECT * FROM ingredients");
    qry->exec();
    while(qry->next()){
        QPair <QPair <QString,int>,QString> p;
        QPair <QString,int> pair;
        qDebug() << qry->record().value(1).toString();
        pair.first = qry->record().value(1).toString();
        pair.second=0;
        p.first=pair;
        p.second=qry->record().value(2).toString();
       // ingredients.push_back(p);
    }*/

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
        QHBoxLayout* layouth = new QHBoxLayout;
        QSqlQuery* qry = new QSqlQuery;
        qry->prepare("SELECT `ingredients`.`unit` FROM `ingredients` WHERE (((`ingredients`.`title_ingredient`)=\""+chb->text()+"\"))");
        qry->exec();
        while(qry->next()){
            QLabel* lb1 = new QLabel;
            lb1->setText(chb->text());
            layouth->addWidget(lb1);
            QLineEdit* LiEd = new QLineEdit();
            LiEd->setValidator(new QRegExpValidator(exp,this));
            layouth->addWidget(LiEd);
            QLabel* Lb2 = new QLabel(this);
            Lb2->setText(qry->record().value(0).toString());
            layouth->addWidget(Lb2);
        }
        QWidget* widget = new QWidget;
        widget->setLayout(layouth);
        QWidget* widget2 = new QWidget;
        QGridLayout* layout = new QGridLayout;
        layout->addWidget(widget);
        widget2->setLayout(layout);
        ui->IngredientsInStock->setWidget(widget2);


        while(qry->next()){
            for(int i=0; i<ingredients.size();i++){
                if (ingredients[i].first.first->text() == qry->record().value(0).toString()){
                    qDebug() << qry->record().value(1).toString();
                    ingredients[i].second->text() = qry->record().value(1).toString();
                }
            }

        }
 /*
                QLabel* Lab = new QLabel(this);
                Lab->setText(qry->record().value(1).toString());
                layout2->addWidget(Lab);
                QLineEdit* LiEd = new QLineEdit(this);
                layout2->addWidget(LiEd);
                QLabel* Lab2 = new QLabel(this);
                Lab2->setText(qry->record().value(2).toString());
                layout2->addWidget(Lab2);
                QWidget* widget = new QWidget;
                widget->setLayout(layout);
                ui->IngredientsInStock->setWidget(widget);*/

        for(int i=0; i<ingredients.size();i++){
            bool ok;
            if(ingredients[i].first.second->text().toInt(&ok) > 0){
              //  QLabel* lb1 = new QLabel;
                //lb->setText("<span style=\"color: red\">text</span>"); тест для разноцветного текста
               // lb1->setText(qry->record().value(1).toString());
              //  layout->addWidget(lb1);
              //  QLineEdit* LiEd = new QLineEdit();
             //   layout->addWidget(LiEd);
             //   QLabel* Lb2 = new QLabel(this);
             //   Lb2->setText(qry->record().value(2).toString());
             //   layout->addWidget(Lb2);
            }
        }

     //   QWidget* widget = new QWidget;
     //   widget->setLayout(layout);
     //   ui->IngredientsInStock->setWidget(widget);
    }
  /*  else {
        QGridLayout* layout = new QGridLayout;
        QSqlQuery* qry = new QSqlQuery;
        qry->prepare("SELECT `ingredients`.`title_ingredient`, `ingredients-dish`.`amount_ingredient` FROM `ingredients` INNER JOIN (`dish` INNER JOIN `ingredients-dish` ON `dish`.`id_dish` = `ingredients-dish`.`id_dish`) ON `ingredients`.`id_ingredient` = `ingredients-dish`.`id_ingredient`WHERE (((`dish`.`title_dish`)=\""+chb->text()+"\"))");
        qry->exec();
        while(qry->next()){
            for(int i=0; i<ingredients.size();i++){

                if (ingredients[i].first.first == qry->record().value(0).toString()){
                    qDebug() << qry->record().value(1).toString();
                    ingredients[i].first.second-= qry->record().value(1).toInt();
                }
            }


        }
        for(int i=0; i<ingredients.size();i++){
            if(ingredients[i].first.second > 0){
                QLabel* lb = new QLabel;
                lb->setText(ingredients[i].first.first + " " +QString::number(ingredients[i].first.second) + " " + ingredients[i].second);
                layout->addWidget(lb);
            }
        }

        QWidget* widget = new QWidget;
        widget->setLayout(layout);
        ui->ingredientsCount->setWidget(widget);
    }*/
}
