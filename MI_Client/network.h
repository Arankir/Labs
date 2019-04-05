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
#include <QTcpSocket>

class Network : public QMainWindow
{
    Q_OBJECT
public:
    Network(QWidget *parent=nullptr);
    ~Network();
    void Get(QString str);
    void Post(QString req, QJsonDocument doc);
    QString GetAnswer();
    QString GetError();

signals:
    void onReady(Network *net);

private:
    QNetworkAccessManager *manager;
    QString answer;
    QString error;
    QTcpSocket *Socket;

public slots:
    void OnResultGet(QNetworkReply *reply);
    void OnResultPost();
};

#endif // MYCLIENT_H
