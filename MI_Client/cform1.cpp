#include "cform1.h"
#include "ui_cform1.h"

CForm1::CForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm1)
{
    ui->setupUi(this);
    ingLay = new QGridLayout;
    ingr = new QWidget;
    QGridLayout *layout = new QGridLayout;
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT name FROM dish");
    qry->exec();
    while(qry->next()){
        QCheckBox *chb = new QCheckBox(this);
        chb->setText(qry->record().value(0).toString());
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
    }
    for(int i=0;i<30;i++){
        QCheckBox *chb = new QCheckBox(this);
        chb->setText(QString::number(i));
        layout->addWidget(chb);
    }
    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);



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

    if(state == 2){
        QCheckBox *chb=(QCheckBox*) sender();
        QLabel* lb = new QLabel;
        lb->setText(chb->text());
        ingLay->addWidget(lb);
        ingr->setLayout(ingLay);
        ui->scrollArea_2->setWidget(ingr);
    }
    else {
        //как сделать удаление????
    }
}
