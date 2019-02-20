#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QStandardItem>
#include <QJsonArray>

class MyClient : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyClient(QWidget *parent = nullptr);
    QTcpSocket* socket;
    QByteArray Data;

signals:

public slots:
    void sockReady();
    void sockDisk();
};

#endif // MYCLIENT_H
