#include "cooform1.h"
#include "ui_cooform1.h"

CooForm1::CooForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CooForm1)
{
    ui->setupUi(this);


}

CooForm1::~CooForm1()
{
    delete ui;
}
