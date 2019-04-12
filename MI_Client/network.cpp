#include "network.h"

Network::Network(QWidget *parent):QMainWindow(parent){
    manager = new QNetworkAccessManager();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString answer="";
    QString error="";
    Socket = new QTcpSocket;
    connect(Socket,SIGNAL(readyRead()),this,SLOT(OnResultPost()));
}

void Network::Get(QString str){
    QUrl url(str);
    connect(manager,&QNetworkAccessManager::finished,this,&Network::OnResultGet);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void Network::Post(QString req, QJsonDocument doc){
//    QByteArray ba;
//    ba = QString(doc.toJson()).toLocal8Bit();
//    QUrl url(req);
    QString str;
    str="POST "+req.mid(req.indexOf("/",8),req.length())+" HTTP/1.1\r\n";
    str+="Host: "+req.mid(7,req.indexOf("/",8)-7)+"\r\n";
    str+="Content-Type:application/x-www-form-urlencoded\r\n";
    str+="Content-Length:85\r\n";
    str+="Connection:Keep-Alive\r\n";
    str+="Accept-Encoding:gzip,deflate\r\n";
    str+="Accept-Language:ru-RU,en,*\r\n";
    str+="User-Agent:Mozilla/5.0\r\n";
    str+="\r\n";
    str+=QString(doc.toJson());

        qDebug()<<req.mid(7,req.indexOf(":",5)-7) <<(req.mid(req.indexOf(":",5)+1,4)).toInt();
        Socket->connectToHost(req.mid(7,req.indexOf(":",5)-7),(req.mid(req.indexOf(":",5)+1,4)).toInt());
        Socket->write(str.toLocal8Bit());
//    QNetworkRequest request;
//    request.setUrl(url);
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
//    connect(manager,&QNetworkAccessManager::finished,this,&Network::OnResultPost);
//    qDebug() << ba;
//    manager->post(request,ba);
}

void Network::OnResultGet(QNetworkReply *reply){
    if(reply->error()){
        error=reply->errorString();
        } else {
        answer=reply->readAll();
        }
    emit onReady(this);
}

//void Network::OnResultPost(QNetworkReply *reply){
//    if(socket->read){
//        error=reply->errorString();
//        } else {
//        answer=QString::fromLocal8Bit(reply->readAll());
//        }
//    emit onReady(this);
//}

void Network::OnResultPost(){
    QString str=Socket->readAll();
//    if(str){
//        error=reply->errorString();
//        } else {
        answer=str.remove("HTTP/1.1 200 OK \r\nContent-Type: application/json\r\n\r\n");
//        }
    emit onReady(this);
}

Network::~Network(){
    delete manager;
}

QString Network::GetAnswer(){
    return answer;
}


QString Network::GetError(){
    return error;
}

