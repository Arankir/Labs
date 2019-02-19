#include "cform3.h"
#include "ui_cform3.h"

cForm3::cForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cForm3)
{
    ui->setupUi(this);

    ui->dateEdit->setDate(QDate::currentDate().addDays(1));

    QWidget* widget = new QWidget;
    QGridLayout* layout = new QGridLayout;
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT * FROM dish");
    qry->exec();
    while(qry->next()){
        QPair<QString,int> pair;
        pair.first = qry->record().value(1).toString();
        pair.second = qry->record().value(0).toInt();
        QCheckBox* chb = new QCheckBox;
        chb->setText(qry->record().value(1).toString());
        checks.push_back(chb);
        dishs.push_back(pair);
        layout->addWidget(chb);
        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
    }
    widget->setLayout(layout);
    ui->AllDish->setWidget(widget);
}

cForm3::~cForm3()
{
    delete ui;
}

void cForm3::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void cForm3::chbChange(int state)
{
    QCheckBox* chb = (QCheckBox*) sender();
    QGridLayout* layout = new QGridLayout;
    QWidget* widget = new QWidget;
    QString count = ui->CountEdit->text();

    if(state == 2){
        QLabel* lb = new QLabel;
        lb->setText(chb->text());
        menu.push_back(lb);
    }
    else {
        menu.clear();
        for(int i=0;i<checks.size();i++){
            if(checks[i]->isChecked()){
                QLabel* lb = new QLabel;
                lb->setText(checks[i]->text());
                menu.push_back(lb);
            }

        }
    }

    for(int i=0; i<menu.size();i++){
        layout->addWidget(menu[i]);
    }
    widget->setLayout(layout);
    ui->DishMenu->setWidget(widget);

}



void cForm3::on_Cancel_clicked()
{
    for(int i=0 ; i< checks.size();i++){
        checks[i]->setChecked(0);
    }
}

void cForm3::on_Applay_clicked()
{
    if (!ui->CountEdit->text().isEmpty() && (ui->lunch->isChecked() || ui->other->isChecked() || ui->dinner->isChecked() || ui->breakfast->isChecked()))
    {
        QMessageBox msg;
        msg.setText("Вы уверены?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int res = msg.exec();
        if(res == QMessageBox::Yes){
            QString type;
            if (ui->breakfast->isChecked()){
                type="1";
            }
            else if(ui->lunch->isChecked()){
                type="2";
            }
            else if (ui->dinner->isChecked()){
                type="3";
            }
            else {
                type="4";
            }
            QSqlQuery *qry = new QSqlQuery;
            int id=1;
            qry->prepare("SELECT COUNT(id_menu) FROM menu");
            qry->exec();
            while(qry->next()){
                id += qry->record().value(0).toInt();
            }
            qry->prepare("INSERT INTO `menu`(`id_menu`, `date_menu`, `id_type`, `amount_portion`) VALUES ('"+QString::number(id)+"','"+ui->dateEdit->date().toString("yyyy-MM-dd")+"','"+type+"','"+ui->CountEdit->text()+"')");
            qry->exec();

            for(int i=0;i<dishs.size();i++){
                for(int j=0; j<menu.size();j++){
                    if(menu[j]->text()==dishs[i].first){
                        qry->prepare("INSERT INTO `menu-dish`(`id_menu`, `id_dish`) VALUES ('"+QString::number(id)+"','"+QString::number(dishs[i].second)+"')");
                        qry->exec();
                    }
                }
            }
            QMessageBox msg;
            msg.setText("Успешно добавлено");
            msg.exec();
        }
    }

    else {
        QMessageBox msg;
        msg.setText("Введите количество, и выберите тип (Завтрак, обед, ужин или другое)!");
        msg.exec();
    }



}
