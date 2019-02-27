#include "serverrequest.h"


ServerRequest::ServerRequest(QSqlDatabase *db)
{
   this->DB=db;
   qDebug() << "ok";
   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

ServerRequest::~ServerRequest()
{

}

void ServerRequest::run()
{
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(Socket_id);
    Socket->waitForReadyRead(1000);
    Responce();
    Socket->waitForBytesWritten(1000);
    Socket->close();
    Socket->disconnectFromHost();
}

void ServerRequest::Responce()
{
    //qDebug() << Socket->readAll();
    //QString request = QString::fromLocal8Bit(Socket->readAll());
    QString request = Socket->readAll();
    if(request.isEmpty()) return;
    QJsonDocument doc = QJsonDocument::fromJson(request.toLocal8Bit());
    QJsonObject obj = doc.object();
    if(obj["type"].toString()=="select"){
        select(obj);
    }
    if(obj["type"].toString()=="insert"){
        insert(obj);
    }
}

void ServerRequest::select(QJsonObject obj)
{
    qDebug() << obj["request"].toString();
    QSqlQuery *qry = new QSqlQuery(*DB);
    if(obj["request"].toString()=="login"){

        QJsonArray arr = obj["data"].toArray();
        QString ans;
        QJsonDocument doc;
        qry->prepare("SELECT  `role`.`role` FROM `auth` INNER JOIN `role` ON `role`.`id_role`=`auth`.`id_role`WHERE `auth`.`login`=\""+arr[0].toObject().value("login").toString()+"\" AND `auth`.`password`=\""+arr[0].toObject().value("password").toString().toUtf8()+"\"");
        qry->exec();
        qDebug() << qry->record().count();
        while(qry->next()){
            QJsonObject obj;
            obj["position"]= qry->record().value(0).toString();
            qDebug() << obj["position"].toString();
            doc.setObject(obj);
        }
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }

    }

    if(obj["request"].toString()=="all_dish"){
        QJsonArray dish_arr;
        qry->prepare("SELECT * FROM dish");
        qry->exec();
        while(qry->next()){
            QJsonObject dish;
            dish["id"]=qry->record().value(0).toString();
            dish["title"]=qry->record().value(1).toString();
            dish_arr.append(dish);
        }
        QJsonObject obj;
        obj["result"]=dish_arr;
        QJsonDocument doc;
        doc.setObject(obj);
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }
    }

    if(obj["request"].toString()=="all_ingredients"){
        QJsonArray ingr_arr;
        qry->prepare("SELECT * FROM ingredients");
        qry->exec();
        while(qry->next()){
            QJsonObject ingr;
            ingr["id"]=qry->record().value(0).toString();
            ingr["title"]=qry->record().value(1).toString();
            ingr["unit"]=qry->record().value(2).toString();
            ingr_arr.append(ingr);
        }
        QJsonObject obj;
        obj["result"]=ingr_arr;
        QJsonDocument doc;
        doc.setObject(obj);
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }
    }

    if(obj["request"].toString()=="whatch_ingr"){
        QJsonArray ingr_arr;
        qDebug() << obj["dish"].toString();
        qry->prepare("SELECT `ingredients`.`title_ingredient`, `ingredients-dish`.`amount_ingredient` FROM `ingredients` INNER JOIN (`dish` INNER JOIN `ingredients-dish` ON `dish`.`id_dish` = `ingredients-dish`.`id_dish`) ON `ingredients`.`id_ingredient` = `ingredients-dish`.`id_ingredient`WHERE (((`dish`.`title_dish`)=\""+obj["dish"].toString()+"\"))");
        qry->exec();
        while(qry->next()){
            QJsonObject ingr;
            ingr["title"]=qry->record().value(0).toString();
            ingr["amount"]=qry->record().value(1).toInt();
            ingr_arr.append(ingr);
        }
        QJsonObject obj;
        obj["result"]=ingr_arr;
        QJsonDocument doc;
        doc.setObject(obj);
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }
    }

    if(obj["request"].toString()=="ing_select"){
        QJsonArray where_Arr;
        where_Arr = obj["data"].toArray();

        QString query = "SELECT `ingredients`.`title_ingredient` as `ингредиент`, `stock`.`title_stock` as `склад`, `ingredients-stock`.`amount_ingredient` as `количество`, `ingredients`.`unit` as `измерение` FROM `ingredients-stock`INNER JOIN `ingredients` ON `ingredients-stock`.`id_ingredient`=`ingredients`.`id_ingredient`INNER JOIN `stock` ON `ingredients-stock`.`id_stock` = `stock`.`id_stock` ";
        if(where_Arr[0].toObject().value("where").toString()==""){
            query += "WHERE `ingredients`.`title_ingredient` != \"\" ";
        }
        else {
            query += "WHERE `ingredients`.`title_ingredient` = '"+ where_Arr[0].toObject().value("where").toString() +"' ";
        }

        if(where_Arr[1].toObject().value("where").toString()==""){
            query += "AND `stock`.`title_stock` != \"\" ";
        }
        else {
            query += "AND `stock`.`title_stock` = '"+ where_Arr[1].toObject().value("where").toString() +"' ";
        }

        if(where_Arr[2].toObject().value("where").toString()==""){
            query += "AND `ingredients-stock`.`amount_ingredient` != \"\" ";
        }
        else {
            query += "AND `ingredients-stock`.`amount_ingredient` = "+ where_Arr[2].toObject().value("where").toString() +" ";
        }

        QJsonArray ing_arr;
        qry->prepare(query);
        qry->exec();
        while (qry->next()) {
            QJsonObject ing;
            ing["title"]=qry->record().value(0).toString();
            ing["stock"]=qry->record().value(1).toString();
            ing["amount"]=qry->record().value(2).toString();
            ing["unit"]=qry->record().value(3).toString();
            ing_arr.append(ing);
        }
        QJsonDocument doc;
        QJsonObject obj;
        obj["result"]=ing_arr;
        doc.setObject(obj);
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }
    }

    if(obj["request"].toString() == "menu_select"){
        QJsonArray data_arr;
        data_arr=obj["data"].toArray();
        QJsonArray menu_arr;
        qry->prepare("SELECT `dish`.`title_dish`,`type_menu`.`title_type`,`menu`.`date_menu`,`menu`.`amount_portion` FROM `menu-dish`INNER JOIN `dish` ON `dish`.`id_dish`=`menu-dish`.`id_dish`INNER JOIN `menu` ON `menu-dish`.`id_menu`=`menu`.`id_menu`INNER JOIN `type_menu` ON `menu`.`id_type`=`type_menu`.`id_type`WHERE `type_menu`.`title_type`=\""+data_arr[0].toObject().value("type").toString()+"\" AND `menu`.`date_menu`=\""+data_arr[0].toObject().value("date").toString()+"\"");
        qry->exec();
        while (qry->next()) {
            QJsonObject menu;
            menu["title"]=qry->record().value(0).toString();
            menu["amount"]=qry->record().value(3).toString();
            menu_arr.append(menu);
        }
        QJsonObject menu_obj;
        menu_obj["result"]=menu_arr;
        QJsonDocument doc;
        doc.setObject(menu_obj);
        if(doc.object().size() == 0){
            Socket->write("NO");
        }
        else {
            Socket->write(QString(doc.toJson()).toLocal8Bit());
        }
    }

    if(obj["request"].toString()=="id_menu"){
        qry->prepare("SELECT * FROM menu WHERE `id_menu`= '"+obj["where"].toString()+"'");
        qry->exec();
        while(qry->next()){
            if(obj["where"].toString() == qry->record().value(0).toString()){
                Socket->write("NO");
                return;
            }

        }
        Socket->write("YES");
    }

}

void ServerRequest::insert(QJsonObject obj)
{
    qDebug() << obj["request"].toString();
    QSqlQuery *qry = new QSqlQuery(*DB);
    if(obj["request"]=="menu"){
        QJsonArray data_arr=obj["data"].toArray();

        qry->prepare("INSERT INTO `menu`(`id_menu`, `date_menu`, `id_type`, `amount_portion`) VALUES ('"+QString::number(data_arr[0].toObject().value("id").toString().toInt())+"','"+data_arr[0].toObject().value("date").toString()+"','"+data_arr[0].toObject().value("type").toString()+"','"+data_arr[0].toObject().value("amount").toString()+"')");
        qry->exec();
        qDebug() << "YES";
        Socket->write("YES");
    }

    if(obj["request"]=="menu-dish"){
        QJsonArray data_arr=obj["data"].toArray();

        for(int i=0;i<data_arr.size();i++){
            qry->prepare("INSERT INTO `menu-dish`(`id_menu`, `id_dish`) VALUES ('"+QString::number(data_arr[i].toObject().value("id-menu").toString().toInt())+"','"+QString::number(data_arr[i].toObject().value("id-dish").toString().toInt())+"')");
            qry->exec();
        }
        qDebug() << "YES";
        Socket->write("YES");
    }
}
