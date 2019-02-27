#ifndef SERVERREQUEST_H
#define SERVERREQUEST_H
#include <QRunnable>
#include <QTcpSocket>
#include <QTcpServer>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>


class ServerRequest : public QRunnable
{
public:
    qintptr Socket_id;
    ServerRequest(QSqlDatabase *db);
    ~ServerRequest();
    void run();
    private:
        void Responce();
        void select(QJsonObject obj);
        void insert(QJsonObject obj);
    private:

        QTcpSocket* Socket;
        QSqlDatabase* DB;
        QString req;
};

#endif // SERVERREQUEST_H
