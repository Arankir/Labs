#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Network : public QMainWindow
{
    Q_OBJECT
public:
    Network(QWidget *parent=nullptr);
    ~Network();
    void SetUrl(QString str);
    QString GetAnswer();
    QString GetError();

signals:
    void onReady(Network *net);

private:
    QNetworkAccessManager *manager;
    QString answer;
    QString error;

public slots:
    void OnResult(QNetworkReply *reply);
};

#endif // MYCLIENT_H
