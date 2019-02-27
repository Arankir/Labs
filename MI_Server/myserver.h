#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QSqlDatabase>

#include <QThreadPool>
#include <serverrequest.h>

class MyServer: public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    ~MyServer();

    QTcpSocket* socket;
    QByteArray data;
    QSqlDatabase db;
    QThreadPool* Thread;
public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
