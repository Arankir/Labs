#include "cform1.h"
#include "ui_cform1.h"

CForm1::CForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm1)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout;
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT * FROM dish");
    qry->exec();
    while(qry->next()){
        QCheckBox *chb = new QCheckBox(this);
        chb->setText(qry->record().value(1).toString());
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
    }
    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);

    qry->prepare("SELECT * FROM ingredients");
    qry->exec();
    while(qry->next()){
        QPair <QString,int> pair;
        qDebug() << qry->record().value(1).toString();
        pair.first = qry->record().value(1).toString();
        pair.second=0;
        ingredients.push_back(pair);
    }

}

CForm1::~CForm1()
{
    delete ui;
}

void CForm1::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void CForm1::chbChange(int state){
    QCheckBox* chb = (QCheckBox*) sender();
    if(state == 2){
        QGridLayout* layout = new QGridLayout;
        QSqlQuery* qry = new QSqlQuery;
        qry->prepare("SELECT `dish`.`title_dish`, `ingredients`.`title_ingredient`, `ingredients-dish`.`amount_ingredient` FROM `ingredients` INNER JOIN (`dish` INNER JOIN `ingredients-dish` ON `dish`.`id_dish` = `ingredients-dish`.`id_dish`) ON `ingredients`.`id_ingredient` = `ingredients-dish`.`id_ingredient`WHERE (((`dish`.`title_dish`)=\""+chb->text()+"\"))");
        qry->exec();
        while(qry->next()){
            for(int i=0; i<ingredients.size();i++){

                if (ingredients[i].first == qry->record().value(1).toString()){
                    qDebug() << qry->record().value(2).toString();
                    ingredients[i].second+= qry->record().value(2).toInt();
                }
            }


        }
        for(int i=0; i<ingredients.size();i++){
            if(ingredients[i].second > 0){
                QLabel* lb = new QLabel;
                lb->setText(ingredients[i].first);
                layout->addWidget(lb);
            }
        }

        QWidget* widget = new QWidget;
        widget->setLayout(layout);
        ui->scrollArea_2->setWidget(widget);
    }
    else {
        //как сделать удаление????
    }
}
