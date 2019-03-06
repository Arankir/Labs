#include "network.h"

Network::Network(QWidget *parent):QMainWindow(parent){
    manager = new QNetworkAccessManager();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString answer="";
    QString error="";
}

void Network::Get(QString str){
    QUrl url(str);
    connect(manager,&QNetworkAccessManager::finished,this,&Network::OnResultGet);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void Network::Post(QString req, QByteArray ba){
    QUrl url(req);
    connect(manager,&QNetworkAccessManager::finished,this,&Network::OnResultPost);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("text/html; charset=utf-8"));
    manager->post(request,ba);
}

void Network::OnResultGet(QNetworkReply *reply){
    if(reply->error()){
        error=reply->errorString();
        } else {
        answer=reply->readAll();
        }
    emit onReady(this);
}

void Network::OnResultPost(QNetworkReply *reply){
    if(reply->error()){
        error=reply->errorString();
        } else {
        answer=QString::fromLocal8Bit(reply->readAll());
        }
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

