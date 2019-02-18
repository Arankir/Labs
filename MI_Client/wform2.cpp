#include "wform2.h"
#include "ui_wform2.h"

Wform2::Wform2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wform2)
{
    ui->setupUi(this);
}

Wform2::~Wform2()
{
    delete ui;
}

void Wform2::setDB(QSqlDatabase *db)
{
    this->db=db;
}
