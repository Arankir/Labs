#include "q123.h"
#include "ui_q123.h"

q123::q123(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::q123)
{
    ui->setupUi(this);
}

q123::~q123()
{
    delete ui;
}
