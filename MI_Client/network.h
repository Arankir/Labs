#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>

class Network : public QMainWindow
{
    Q_OBJECT
public:
    Network(QWidget *parent=nullptr);
    ~Network();
    void Get(QString str);
    void Post(QString req,QByteArray ba);
    QString GetAnswer();
    QString GetError();

signals:
    void onReady(Network *net);

private:
    QNetworkAccessManager *manager;
    QString answer;
    QString error;

public slots:
    void OnResultGet(QNetworkReply *reply);
    void OnResultPost(QNetworkReply *reply);
};

#endif // MYCLIENT_H
