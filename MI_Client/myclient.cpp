#include "myclient.h"

MyClient::MyClient(QWidget *parent) : QMainWindow(parent)
{

}

void MyClient::setRequest(QString req)
{
    this->request=req;
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisk()));

    socket->connectToHost("127.0.0.1",5555);
    if(socket->isOpen()) {
            socket->write(request.toLocal8Bit());
            socket ->waitForBytesWritten(500);
        }
}

void MyClient::sockReady()
{
    if(socket->waitForConnected(500)){
        socket->waitForReadyRead(500);
        Data = socket->readAll();
        answer = QString::fromLocal8Bit(Data);
        emit ClientReady(this);
    }
}

void MyClient::sockDisk()
{
    socket->deleteLater();
}
