#include "cform4.h"
#include "ui_cform4.h"

CForm4::CForm4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm4)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
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

    QJsonArray data_arr;
    QJsonObject data_obj;
    data_obj["type"]=type;
    data_obj["date"]=ui->calendar->selectedDate().toString("yyyy-MM-dd");
    data_arr.append(data_obj);
    QJsonObject obj;
    obj["data"]=data_arr;
    obj["request"]="menu_select";
    obj["type"]="select";
    QJsonDocument doc;
    doc.setObject(obj);
    QString request = QString(doc.toJson()).toLocal8Bit();

    //MyClient* menu_req = new MyClient;
    //connect(menu_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(menuRequest(MyClient*)));
    //menu_req->setRequest(request);


}

void CForm4::on_calendar_selectionChanged()
{
    ui->date->setText(ui->calendar->selectedDate().toString("yyyy-MM-dd"));
}

//void CForm4::menuRequest(MyClient *client)
//{

//    QJsonDocument doc = QJsonDocument::fromJson(client->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray menu_arr = obj["result"].toArray();
//    QFormLayout* layout = new QFormLayout;
//    for(int i=0;i<menu_arr.size();i++){
//        QLabel* lb = new QLabel;
//        lb->setText(menu_arr[i].toObject().value("title").toString()+" "+menu_arr[i].toObject().value("amount").toString() + " порций");
//        layout->addWidget(lb);
//    }
//    QWidget* widget= new QWidget;
//    widget->setLayout(layout);
//    ui->menu->setWidget(widget);
//}
