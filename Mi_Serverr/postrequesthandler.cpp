#include "postrequesthandler.h"

PostRequestHandler::PostRequestHandler(QSqlDatabase *db, Request *request):DB_(db),Request_(request)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

QString PostRequestHandler::registrHandler(QString post)
{

    if(post != ""){
        QJsonDocument doc = QJsonDocument::fromJson(post.toLocal8Bit());
        QJsonObject obj = doc.object();
        //QJsonObject user = obj["Data"].toObject();

        QSqlQuery *query = new QSqlQuery(*DB_);
        query->prepare("SELECT `auth`.`login` FROM `auth` WHERE `auth`.`login` = \""+obj["login"].toString()+"\"");
        query->exec();

        if(query->size()==0){
            query->prepare("INSERT INTO `auth`(`login`, `password`, `id_role`) VALUES ('"+obj["login"].toString()+"','"+obj["password"].toString()+"',(SELECT `role`.`id_role` FROM `role` WHERE `role`.`role`= \""+obj["role"].toString()+"\"))");
            query->exec();
            return QString ("YES");
        }
        else{
            return QString("NO");
        }
    }
    else return QString("NO");
}

QString PostRequestHandler::newIngredientHandler(QString post)
{
    if(post != ""){
        QJsonDocument doc = QJsonDocument::fromJson(post.toLocal8Bit());
        QJsonObject obj = doc.object();

        QSqlQuery *query = new QSqlQuery(*DB_);
        query->prepare("SELECT `ingredients`.`title_ingredient` FROM `ingredients` WHERE `ingredients`.`title_ingredient` =\""+obj["title"].toString()+"\"");
        query->exec();
        if(query->size()==0){
            int id = 1;
            bool f =1;
            while (f) {
                query->prepare("SELECT `ingredients`.`id_ingredient` FROM `ingredients` WHERE `id_ingredient` = " + QString::number(id));
                query->exec();
                if(query->size()==0){
                    f=0;
                }
                else {
                    id++;
                }
            }

            query->prepare("INSERT INTO `ingredients`(`id_ingredient`, `title_ingredient`, `unit`) VALUES ('"+QString::number(id)+"','"+obj["title"].toString()+"','"+obj["unit"].toString()+"')");
            query->exec();
            return QString("YES");
        }
        else {
            return QString("Ingredients exist");
        }
    }
    else return QString("NO");
}

QString PostRequestHandler::newStockHandler(QString post)
{
    if(post != ""){
        QJsonDocument doc = QJsonDocument::fromJson(post.toLocal8Bit());
        QJsonObject obj = doc.object();

        QSqlQuery *query = new QSqlQuery(*DB_);
        query->prepare("SELECT `stock`.`title_stock` FROM `stock` WHERE `stock`.`title_stock` =\""+obj["title"].toString()+"\"");
        query->exec();
        if(query->size()==0){
            int id = 1;
            bool f =1;
            while (f) {
                query->prepare("SELECT `stock`.`id_stock` FROM `stock` WHERE `stock`.`id_stock` = " + QString::number(id));
                query->exec();
                if(query->size()==0){
                    f=0;
                }
                else {
                    id++;
                }
            }

            query->prepare("INSERT INTO `stock`(`id_stock`, `title_stock`) VALUES ('"+QString::number(id)+"','"+obj["title"].toString()+"')");
            query->exec();
            return QString("YES");
        }
        else {
            return QString("Stock exist");
        }
    }
    else return QString("NO");
}

QString PostRequestHandler::newDishHandler(QString post)
{
    if(post != ""){
        QJsonDocument doc = QJsonDocument::fromJson(post.toLocal8Bit());
        QJsonObject obj = doc.object();

        QSqlQuery *query = new QSqlQuery(*DB_);
        query->prepare("SELECT `dish`.`title_dish` FROM `dish` WHERE `dish`.`title_dish` =\""+obj["title"].toString()+"\"");
        query->exec();
        if(query->size()==0){
            int id = 1;
            bool f =1;
            while (f) {
                query->prepare("SELECT `dish`.`id_dish` FROM `dish` WHERE `dish`.`id_dish` = " + QString::number(id));
                query->exec();
                if(query->size()==0){
                    f=0;
                }
                else {
                    id++;
                }
            }

            query->prepare("INSERT INTO `dish`(`id_dish`, `title_dish`) VALUES ('"+QString::number(id)+"','"+obj["title"].toString()+"')");
            query->exec();

            QJsonArray arr = obj["ingredients"].toArray();
            for (int i=0; i<arr.size();i++){
                query->prepare("INSERT INTO `ingredients-dish`(`id_dish`, `id_ingredient`, `amount_ingredient`) VALUES ('"+QString::number(id)+"',(SELECT `ingredients`.`id_ingredient` FROM `ingredients` WHERE `ingredients`.`title_ingredient` = \""+arr[i].toObject().value("title").toString()+"\" ),'"+arr[i].toObject().value("amount").toString()+"')");
                query->exec();
            }


            return QString("YES");
        }
        else {
            return QString("Dish exist");
        }
    }
    else return QString("NO");
}
