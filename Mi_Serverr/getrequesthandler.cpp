#include "getrequesthandler.h"

GetRequestHandler::GetRequestHandler(QSqlDatabase *db, Request *request):DB_(db),Request_(request)
{
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

QString GetRequestHandler::dishHandle(){
    QJsonArray dishs_array;
    QSqlQuery* query = new QSqlQuery(*DB_);
    if (query->exec("SELECT * FROM dish")) {
        while (query->next()) {
            QJsonObject dish_obj;
            dish_obj["id"] = query->value(0).toString();
            dish_obj["dish"] = query->value(1).toString();
            QJsonArray ingredients;

            QSqlQuery* qry = new QSqlQuery(*DB_);
            qry->prepare("SELECT `ingredients`.`title_ingredient`, `ingredients-dish`.`amount_ingredient`, `ingredients`.`unit` FROM `ingredients` INNER JOIN (`dish` INNER JOIN `ingredients-dish` ON `dish`.`id_dish` = `ingredients-dish`.`id_dish`) ON `ingredients`.`id_ingredient` = `ingredients-dish`.`id_ingredient`WHERE (((`dish`.`title_dish`)=\""+dish_obj["dish"].toString()+"\"))");
            qry->exec();

            while (qry->next()) {
                QJsonObject ingr_obj;
                ingr_obj["title"]=qry->value(0).toString();
                ingr_obj["amount"]=qry->value(1).toString();
                //ingr_obj["unit"]=qry->value(2).toString();
                ingredients.append(ingr_obj);
            }

            dish_obj["ingredients"]=ingredients;
            dishs_array.append(dish_obj);
        }
    }

    QJsonObject dish;
    dish["Dishs"]=dishs_array;
    QJsonArray ingredients;
    if (query->exec("SELECT `title_ingredient`, `unit` FROM ingredients"))
        while (query->next()) {
            QJsonObject ingredient;
            ingredient["title"]=query->value(0).toString();
            ingredient["unit"]=query->value(1).toString();
            ingredients.append(ingredient);
        }
    dish["Ingredients"]=ingredients;
    QJsonDocument doc;
    doc.setObject(dish);
    return QString(doc.toJson());
}

QString GetRequestHandler::StockIngHandler(){
    QJsonArray stock_ing_array;
    QSqlQuery* query = new QSqlQuery(*DB_);
    if (query->exec("SELECT `stock`.`title_stock`, `ingredients`.`title_ingredient`, `ingredients-stock`.`amount_ingredient`, `ingredients`.`unit` FROM `ingredients-stock` INNER JOIN `stock` ON `ingredients-stock`.`id_stock` = `stock`.`id_stock` INNER JOIN `ingredients` ON `ingredients-stock`.`id_ingredient`= `ingredients`.`id_ingredient`")) {
        while (query->next()) {
            QJsonObject stock_ing_obj;
            stock_ing_obj["stock_title"] = query->value(0).toString();
            stock_ing_obj["ingredient_title"] = query->value(1).toString();
            stock_ing_obj["amount"] = query->value(2).toString();
            stock_ing_obj["unit"] = query->value(3).toString();
            stock_ing_array.append(stock_ing_obj);
        }
    }
    QJsonObject stock;
    stock["ingredient_stock"]=stock_ing_array;
    QJsonDocument doc;
    doc.setObject(stock);
    return QString(doc.toJson());
}

QString GetRequestHandler::menuHandler(){
    QJsonArray menu_arr;
    QSqlQuery* query = new QSqlQuery(*DB_);
    if(query->exec("SELECT `menu`.`id_menu`, `menu`.`date_menu`, `type_menu`.`title_type`, `menu`.`amount_portion` FROM `menu` INNER JOIN `type_menu` ON `type_menu`.`id_type`=`menu`.`id_type`"))
        while (query->next()) {
            QJsonObject menu_obj;
            menu_obj["id"]=query->value(0).toString();
            menu_obj["date"]=query->value(1).toString();
            menu_obj["type"]=query->value(2).toString();
            menu_obj["amount"]=query->value(3).toString();

            QSqlQuery* qry = new QSqlQuery(*DB_);
            QJsonArray dishs;
            if(qry->exec("SELECT `dish`.`title_dish` FROM `menu-dish` INNER JOIN `dish` ON `menu-dish`.`id_dish`=`dish`.`id_dish` WHERE `menu-dish`.`id_menu`= "+menu_obj["id"].toString()))
                while (qry->next()) {
                    dishs.append(qry->value(0).toString());
                }
            menu_obj["dishs"]=dishs;
            menu_arr.append(menu_obj);
        }
    QJsonObject menu;
    menu["Menu"]=menu_arr;
    QJsonDocument doc;
    doc.setObject(menu);
    return QString(doc.toJson());
}
