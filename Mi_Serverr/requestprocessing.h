#ifndef REQUESTPROCESSING_H
#define REQUESTPROCESSING_H


#include <QRunnable>
#include <QTcpSocket>
#include <QTcpServer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QSql>
#include <request.h>
#include <getrequesthandler.h>
class RequestProcessing : public QRunnable
{
public:
    RequestProcessing(qintptr socket_id, QSqlDatabase* db);
    ~RequestProcessing();
    void run();
private:
    QString GetUri(const QString& body_http);
    void Responce();
    void GetRequest();
    void PostRequest();
private:
    qintptr Socket_id;
    QTcpSocket* Socket_;
    QSqlDatabase* DB_;
    Request* Request_;
};

#endif // REQUESTPROCESSING_H
