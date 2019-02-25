#include "cform4.h"
#include "ui_cform4.h"

CForm4::CForm4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm4)
{
    ui->setupUi(this);
     ui->date->setText(ui->calendar->selectedDate().toString("yyyy-MM-dd"));
    ui->calendar->setGridVisible(1);
}

CForm4::~CForm4()
{
    delete ui;
}

void CForm4::setDB(QSqlDatabase *db)
{
    this->db=db;
}



void CForm4::on_search_clicked()
{
    QString type;
    if(ui->breakfast->isChecked()){
        type="завтрак";
    }
    if(ui->lunch->isChecked()){
        type="обед";
    }
    if(ui->dinner->isChecked()){
        type="ужин";
    }
    if(ui->other->isChecked()){
        type="другое";
    }

    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT `dish`.`title_dish`,`type_menu`.`title_type`,`menu`.`date_menu`,`menu`.`amount_portion` FROM `menu-dish`INNER JOIN `dish` ON `dish`.`id_dish`=`menu-dish`.`id_dish`INNER JOIN `menu` ON `menu-dish`.`id_menu`=`menu`.`id_menu`INNER JOIN `type_menu` ON `menu`.`id_type`=`type_menu`.`id_type`WHERE `type_menu`.`title_type`=\""+type+"\" AND `menu`.`date_menu`=\""+ui->calendar->selectedDate().toString("yyyy-MM-dd")+"\"");
    qry->exec();
    QFormLayout* layout = new QFormLayout;
    while(qry->next()){
        qDebug() << qry->record().value(0).toString();
        QLabel* lb = new QLabel;
        lb->setText(qry->record().value(0).toString()+" "+qry->record().value(3).toString() + " порций");
        layout->addWidget(lb);
    }
    QWidget* widget= new QWidget;
    widget->setLayout(layout);
    ui->menu->setWidget(widget);
}

void CForm4::on_calendar_selectionChanged()
{
    ui->date->setText(ui->calendar->selectedDate().toString("yyyy-MM-dd"));
}
