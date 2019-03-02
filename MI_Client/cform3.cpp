#include "cform3.h"
#include "ui_cform3.h"

cForm3::cForm3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cForm3)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui->dateEdit->setDate(QDate::currentDate().addDays(1));



    QJsonObject dish_obj;
    dish_obj["type"]="select";
    dish_obj["request"]="all_dish";
    QJsonDocument doc;
    doc.setObject(dish_obj);
    QString dish_req = QString(doc.toJson()).toLocal8Bit();

    //MyClient* dish_request= new MyClient;
    //connect(dish_request,SIGNAL(ClientReady(MyClient*)),this,SLOT(dishRequest(MyClient*)));
    //dish_request->setRequest(dish_req);


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
    QFormLayout* layout = new QFormLayout;
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

            id++;
            QJsonObject id_obj;
            id_obj["type"]="select";
            id_obj["request"]="id_menu";
            id_obj["where"]=QString::number(id);
            QJsonDocument id_doc;
            id_doc.setObject(id_obj);
            QString id_request = QString(id_doc.toJson()).toLocal8Bit();

            //MyClient* id_req = new MyClient;
            //connect(id_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(idRequest(MyClient*)));
            //id_req->setRequest(id_request);

        }
    }

    else {
        QMessageBox msg;
        msg.setText("Введите количество, и выберите тип (Завтрак, обед, ужин или другое)!");
        msg.exec();
    }



}

//void cForm3::dishRequest(MyClient *client)
//{
//    QWidget* widget = new QWidget;
//    QGridLayout* layout = new QGridLayout;

//    QJsonDocument doc = QJsonDocument::fromJson(client->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray dish_arr = obj["result"].toArray();

//    for(int i=0;i<dish_arr.size();i++){
//        QPair<QString,int> pair;
//        pair.first = dish_arr[i].toObject().value("title").toString();
//        pair.second = dish_arr[i].toObject().value("id").toString().toInt();
//        QCheckBox* chb = new QCheckBox;
//        chb->setText(dish_arr[i].toObject().value("title").toString());
//        checks.push_back(chb);
//        dishs.push_back(pair);
//        layout->addWidget(chb);
//        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
//    }

//    widget->setLayout(layout);
//    ui->AllDish->setWidget(widget);
//}

//void cForm3::idRequest(MyClient *client)
//{
//    QJsonDocument doc = QJsonDocument::fromJson(client->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    if(client->answer != "NO"){

//        QString type;
//        if (ui->breakfast->isChecked()){
//            type="1";
//        }
//        else if(ui->lunch->isChecked()){
//            type="2";
//        }
//        else if (ui->dinner->isChecked()){
//            type="3";
//        }
//        else {
//            type="4";
//        }

//        QJsonArray data_arr;
//        QJsonObject data_obj;
//        data_obj["id"]=QString::number(this->id);
//        data_obj["date"]=ui->dateEdit->date().toString("yyyy-MM-dd");
//        data_obj["type"]=type;
//        data_obj["amount"]=ui->CountEdit->text();
//        data_arr.append(data_obj);
//        QJsonObject ins_req_obj;
//        ins_req_obj["data"]=data_arr;
//        ins_req_obj["request"]="menu";
//        ins_req_obj["type"]="insert";
//        QJsonDocument ins_doc;
//        ins_doc.setObject(ins_req_obj);
//        QString ins_request = QString(ins_doc.toJson()).toLocal8Bit();

//        MyClient* ins_req = new MyClient;
//        connect(ins_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(insertRequest(MyClient*)));
//        ins_req->setRequest(ins_request);



//    }
//    else {
//        id++;
//        QJsonObject id_obj;
//        id_obj["type"]="select";
//        id_obj["request"]="id_menu";
//        id_obj["where"]=QString::number(id);
//        QJsonDocument id_doc;
//        id_doc.setObject(id_obj);
//        QString id_request = QString(id_doc.toJson()).toLocal8Bit();

//        MyClient* id_req = new MyClient;
//        connect(id_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(idRequest(MyClient*)));
//        id_req->setRequest(id_request);
//    }
//}

//void cForm3::insertRequest(MyClient *client)
//{



//    QJsonArray dat_arr;
//    for(int i=0;i<dishs.size();i++){
//        for(int j=0; j<menu.size();j++){
//            if(menu[j]->text()==dishs[i].first){
//                QJsonObject dat_obj;
//                dat_obj["id-menu"]=QString::number(this->id);
//                dat_obj["id-dish"]=QString::number(dishs[i].second);
//                dat_arr.append(dat_obj);

//            }
//        }
//    }

//    QJsonObject in_req_obj;
//    in_req_obj["data"]=dat_arr;
//    in_req_obj["request"]="menu-dish";
//    in_req_obj["type"]="insert";
//    QJsonDocument insdoc;
//    insdoc.setObject(in_req_obj);
//    QString in_request = QString(insdoc.toJson()).toLocal8Bit();

//    MyClient* in_req = new MyClient;
//    in_req->setRequest(in_request);

//    QMessageBox msg;
//    msg.setText("Успешно добавлено");
//    msg.exec();




//}
