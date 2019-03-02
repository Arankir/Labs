#include "network.h"

Network::Network(QWidget *parent):QMainWindow(parent){
    manager = new QNetworkAccessManager();
    QString answer="";
    QString error="";
}

void Network::SetUrl(QString str){
    QUrl url(str);
    connect(manager,&QNetworkAccessManager::finished,this,&Network::OnResult);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void Network::OnResult(QNetworkReply *reply){
    if(reply->error()){
        error=reply->errorString();
        } else {
        answer=reply->readAll();
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

