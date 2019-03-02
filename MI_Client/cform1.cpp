#include "cform1.h"
#include "ui_cform1.h"

CForm1::CForm1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CForm1)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QJsonObject dish_req_obj;
    dish_req_obj["type"]="select";
    dish_req_obj["request"]="all_dish";
    QJsonDocument dish_req_doc;
    dish_req_doc.setObject(dish_req_obj);
    QString dish_req = QString(dish_req_doc.toJson()).toLocal8Bit();

    QJsonObject ing_req_obj;
    ing_req_obj["type"]="select";
    ing_req_obj["request"]="all_ingredients";
    QJsonDocument ing_req_doc;
    ing_req_doc.setObject(ing_req_obj);
    QString ing_req = QString(ing_req_doc.toJson()).toLocal8Bit();

    //MyClient* dish = new MyClient;
    //connect(dish,SIGNAL(ClientReady(MyClient*)),this,SLOT(dishRequest(MyClient*)));
    //dish->setRequest(dish_req);

    //MyClient* ingr = new MyClient;
    //connect(ingr,SIGNAL(ClientReady(MyClient*)),this,SLOT(ingrRequest(MyClient*)));
    //ingr->setRequest(ing_req);


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
    QCheckBox* chb = (QCheckBox*) sender();
    if(state == 2){

        this->add=1;


        QJsonObject wIngr_obj;
        QString str = chb->text();
        wIngr_obj["dish"]=chb->text();
        wIngr_obj["request"]="whatch_ingr";
        wIngr_obj["type"]="select";
        QJsonDocument wIngr_doc;
        wIngr_doc.setObject(wIngr_obj);
        QString wIngr_req = QString(wIngr_doc.toJson()).toLocal8Bit();

        //MyClient* wIngredients = new MyClient;
        //connect(wIngredients,SIGNAL(ClientReady(MyClient*)),this,SLOT(countRequest(MyClient*)));
        //wIngredients->setRequest(wIngr_req);


    }
    else {
        QFormLayout* layout = new QFormLayout;
        QSqlQuery* qry = new QSqlQuery;
        qry->prepare("SELECT `ingredients`.`title_ingredient`, `ingredients-dish`.`amount_ingredient`, `ingredients`.`unit` FROM `ingredients` INNER JOIN (`dish` INNER JOIN `ingredients-dish` ON `dish`.`id_dish` = `ingredients-dish`.`id_dish`) ON `ingredients`.`id_ingredient` = `ingredients-dish`.`id_ingredient`WHERE (((`dish`.`title_dish`)=\""+chb->text()+"\"))");
        qry->exec();
        while(qry->next()){
            for(int i=0; i<ingredients.size();i++){

                if (ingredients[i].first.first == qry->record().value(0).toString()){
                    qDebug() << qry->record().value(1).toString();
                    ingredients[i].first.second-= qry->record().value(1).toInt();
                }
            }


        }
        for(int i=0; i<ingredients.size();i++){
            if(ingredients[i].first.second > 0){
                QLabel* lb = new QLabel;
                lb->setText(ingredients[i].first.first + " " +QString::number(ingredients[i].first.second) + " " + ingredients[i].second);
                layout->addWidget(lb);
            }
        }

        QWidget* widget = new QWidget;
        widget->setLayout(layout);
        ui->ingredientsCount->setWidget(widget);
    }
}

//void CForm1::dishRequest(MyClient *dishReq)
//{
//    QWidget* widget = new QWidget;
//    QFormLayout *layout = new QFormLayout;

//    QJsonDocument doc = QJsonDocument::fromJson(dishReq->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray dish_arr = obj["result"].toArray();
//    for(int i=0; i<dish_arr.size();i++){
//        qDebug() << dish_arr[i].toObject().value("title").toString();
//        QCheckBox *chb = new QCheckBox(this);
//        chb->setText(dish_arr[i].toObject().value("title").toString());
//        layout->addWidget(chb);
//        connect(chb,SIGNAL(stateChanged(int)),this,SLOT(chbChange(int)));
//    }

//    widget->setLayout(layout);
//    ui->allDish->setWidget(widget);


//}

//void CForm1::ingrRequest(MyClient *ingrReq)
//{
//    QJsonDocument doc = QJsonDocument::fromJson(ingrReq->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray ingr_arr = obj["result"].toArray();
//    for (int i=0;i<ingr_arr.size();i++) {
//        QPair <QPair <QString, int>, QString> p;
//        QPair <QString,int> pair;
//        qDebug() << ingr_arr[i].toObject().value("title").toString();
//        pair.first = ingr_arr[i].toObject().value("title").toString();
//        pair.second=0;
//        p.first=pair;
//        p.second = ingr_arr[i].toObject().value("unit").toString();
//        ingredients.push_back(p);
//    }


//}

//void CForm1::countRequest(MyClient *countReq)
//{

//    QJsonDocument doc = QJsonDocument::fromJson(countReq->answer.toUtf8());
//    QJsonObject obj = doc.object();
//    QJsonArray ingr_arr = obj["result"].toArray();

//    for (int i=0;i<ingr_arr.size();i++) {
//        for (int j=0;j<ingredients.size();j++) {
//            if(ingredients[j].first.first == ingr_arr[i].toObject().value("title").toString()){
//                if (this->add == 1){
//                    qDebug() << ingr_arr[i].toObject().value("amount").toInt();
//                    ingredients[j].first.second+=ingr_arr[i].toObject().value("amount").toInt();
//                }
//                else {
//                    ingredients[j].first.second-=ingr_arr[i].toObject().value("amount").toInt();
//                }
//            }
//        }
//    }

//    QFormLayout* layout = new QFormLayout;
//    for(int i=0; i<ingredients.size();i++){
//        if(ingredients[i].first.second > 0){
//            QLabel* lb = new QLabel;
//            //lb->setText("<span style=\"color: red\">text</span>"); тест для разноцветного текста
//            lb->setText(ingredients[i].first.first + " " +QString::number(ingredients[i].first.second) + " " + ingredients[i].second);
//            layout->addWidget(lb);
//        }
//    }

//    QWidget* widget = new QWidget;
//    widget->setLayout(layout);
//    ui->ingredientsCount->setWidget(widget);

//}
