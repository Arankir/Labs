#ifndef GETREQUESTHANDLER_H
#define GETREQUESTHANDLER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <request.h>



class GetRequestHandler
{
public:
    GetRequestHandler(QSqlDatabase* db, Request* request);
    QString dishHandle();
    QString StockIngHandler();
    QString menuHandler();
private:
    QSqlDatabase* DB_;
    Request* Request_;
};

#endif // GETREQUESTHANDLER_H
