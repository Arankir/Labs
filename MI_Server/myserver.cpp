#include "myserver.h"

MyServer::MyServer()
{
    Thread = new QThreadPool;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("sanatorii");
    db.setUserName("root");
    db.setPassword("1423");
}

MyServer::~MyServer(){

}

void MyServer::startServer(){
    if(this->listen(QHostAddress::Any,5555)){

        if(db.open())
        qDebug() << "listning";
    }
    else {
        qDebug() << "not listning";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor){

    ServerRequest* request = new ServerRequest(&db);
    //request->setAutoDelete(1);
    request->Socket_id = socketDescriptor;
    Thread->start(request);

}


void MyServer::sockReady(){

}

void MyServer::sockDisc(){
    qDebug() << "disconect";
    socket->deleteLater();
}
