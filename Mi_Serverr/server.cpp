#include "server.h"

Server::Server(QObject* parent): QTcpServer (parent),ThreadPool(new QThreadPool(this))
{
    DB_= QSqlDatabase::addDatabase("QMYSQL");
    DB_.setDatabaseName("sanatorii");
    DB_.setHostName("127.0.0.1");
    DB_.setUserName("root");
    DB_.setPassword("1423");
    if(DB_.open()){
        qDebug() << "Db open";
    }
    else {
        qDebug() << "NO";
    }
}

Server::~Server(){

}

void Server::StartServer(){
    if(this->listen(QHostAddress::Any,5555)){
        qDebug() << "listen";
    }
    else {
        qDebug() << "not listen";
    }
}

void Server::incomingConnection(qintptr socketDescriptor){
    RequestProcessing* requestProcessing =new RequestProcessing(socketDescriptor,&DB_);
    ThreadPool->start(requestProcessing);
}
