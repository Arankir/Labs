#ifndef POSTREQUESTHANDLER_H
#define POSTREQUESTHANDLER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <request.h>

class PostRequestHandler
{
public:
    PostRequestHandler(QSqlDatabase* db, Request* request);
    QString registrHandler(QString post);
    QString newIngredientHandler(QString post);
    QString newStockHandler(QString post);
    QString newDishHandler(QString post);
private:
    QSqlDatabase* DB_;
    Request* Request_;
};

#endif // POSTREQUESTHANDLER_H
