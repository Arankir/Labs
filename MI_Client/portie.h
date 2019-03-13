#ifndef PORTIE_H
#define PORTIE_H

#include <QWidget>
#include <network.h>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QSpacerItem>
#include <filterinvoice.h>

namespace Ui {
class Portie;
}

class Portie : public QWidget
{
    Q_OBJECT

public:
    explicit Portie(QString ips, QWidget *parent = nullptr);
    ~Portie();

signals:
    void loginOpen();

private slots:
    void on_Hide_clicked();

    void on_LogOut_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_Result_networkPortie(Network *portie);

    void on_P1ButtonAccept_clicked();

private:
    Ui::Portie *ui;
    QJsonDocument portie;
    QString IP;
    typedef bool (FilterInvoice::*DateFunc)(QString a, QString b);
    typedef bool (FilterInvoice::*TitleFunc)(QString a, QString b);
};

#endif // PORTIE_H
