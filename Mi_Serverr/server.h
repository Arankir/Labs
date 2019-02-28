#ifndef SERVER_H
#define SERVER_H


//#include "requestprocessing.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QFile>
#include <QThreadPool>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <requestprocessing.h>
class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);
    ~Server();
    void incomingConnection(qintptr socketDescriptor);
public slots:
    void StartServer();
private:
    QThreadPool* ThreadPool;
    QSqlDatabase DB_;
};

#endif // SERVER_H
