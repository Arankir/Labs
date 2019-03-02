#include "cform2.h"
#include "ui_cform2.h"

CForm2::CForm2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm2)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QJsonArray where_arr;
    QJsonObject where_obj;
    where_obj["where"]=ui->IngredientEdit->text();
    where_arr.append(where_obj);
    where_obj["where"]=ui->stockEdit->text();
    where_arr.append(where_obj);
    where_obj["where"]=ui->countEdit->text();
    where_arr.append(where_obj);
    QJsonObject ing_req_obj;
    ing_req_obj["data"]=where_arr;
    ing_req_obj["request"]="ing_select";
    ing_req_obj["type"]="select";
    QJsonDocument ing_doc;
    ing_doc.setObject(ing_req_obj);
    QString request = QString(ing_doc.toJson()).toLocal8Bit();

    //MyClient* ing_req = new MyClient;
    //connect(ing_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(ingredientsRequest(MyClient*)));
    //ing_req->setRequest(request);

}

CForm2::~CForm2()
{
    delete ui;
}

void CForm2::setDB(QSqlDatabase *db)
{
    this->db=db;
}

void CForm2::on_Search_clicked()
{
    QJsonArray where_arr;
    QJsonObject where_obj;
    where_obj["where"]=ui->IngredientEdit->text();
    where_arr.append(where_obj);
    where_obj["where"]=ui->stockEdit->text();
    where_arr.append(where_obj);
    where_obj["where"]=ui->countEdit->text();
    where_arr.append(where_obj);
    QJsonObject ing_req_obj;
    ing_req_obj["data"]=where_arr;
    ing_req_obj["request"]="ing_select";
    ing_req_obj["type"]="select";
    QJsonDocument ing_doc;
    ing_doc.setObject(ing_req_obj);
    QString request = QString(ing_doc.toJson()).toLocal8Bit();

    //MyClient* ing_req = new MyClient;
    //connect(ing_req,SIGNAL(ClientReady(MyClient*)),this,SLOT(ingredientsRequest(MyClient*)));
    //ing_req->setRequest(request);
}

//void CForm2::ingredientsRequest(MyClient *client)
//{
//    QJsonDocument doc = QJsonDocument::fromJson(client->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray ingr_arr = obj["result"].toArray();

//    QStandardItemModel* model = new QStandardItemModel;
//    model->setHorizontalHeaderLabels(QStringList() << "ингредиент" << "склад" << "количество" << "измерение");
//    for(int i=0; i<ingr_arr.size();i++){
//        QStandardItem* col1 = new QStandardItem(ingr_arr[i].toObject().value("title").toString());
//        QStandardItem* col2 = new QStandardItem(ingr_arr[i].toObject().value("stock").toString());
//        QStandardItem* col3 = new QStandardItem(ingr_arr[i].toObject().value("amount").toString());
//        QStandardItem* col4 = new QStandardItem(ingr_arr[i].toObject().value("unit").toString());
//        model->appendRow(QList<QStandardItem*>() << col1 << col2 << col3 << col4);
//    }
//    ui->IngredientsTable->setModel(model);
//}
