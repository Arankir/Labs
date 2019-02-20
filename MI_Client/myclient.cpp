#include "myclient.h"

MyClient::MyClient(QWidget *parent) : QMainWindow(parent)
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisk()));

    socket->connectToHost("127.0.0.1",5555);
}

void MyClient::sockReady()
{

}

void MyClient::sockDisk()
{

}
