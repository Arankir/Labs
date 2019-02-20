#include "aform1.h"
#include "ui_aform1.h"

AForm1::AForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AForm1)
{
    ui->setupUi(this);
}

AForm1::~AForm1()
{
    delete ui;
}

void AForm1::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void AForm1::on_Reg_clicked()
{
    if(!ui->LoginEdit->text().isEmpty() && !ui->PasswordEdit->text().isEmpty())
    {
        QSqlQuery* qry= new QSqlQuery;
        qry->prepare("SELECT login FROM auth");
        qry->exec();
        while(qry->next()){
            if(qry->record().value(0).toString() == ui->LoginEdit->text()){
                QMessageBox::warning(this,"Внимание","Логин занят!");
                return;
            }
        }
        qry->prepare("INSERT INTO `auth`(`login`, `password`, `id_role`) VALUES ('"+ui->LoginEdit->text()+"','"+ui->PasswordEdit->text()+"', (SELECT `id_role` FROM `role` WHERE \""+ui->Role->currentText()+"\"=`role`.`role`))");
        qry->exec();
        QMessageBox mes;
        mes.setWindowTitle("Поздравляю");
        mes.setText("Пользователь зарегистрирован успешно!");
        mes.exec();
    }
    else {
        QMessageBox::warning(this,"Внимание","Логин занят!");
    }

}
