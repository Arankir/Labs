#ifndef PORTIE_H
#define PORTIE_H

#include <QWidget>

namespace Ui {
class Portie;
}

class Portie : public QWidget
{
    Q_OBJECT

public:
    explicit Portie(QString ips, QWidget *parent = nullptr);
    ~Portie();

private slots:
    void on_Hide_clicked();

private:
    Ui::Portie *ui;
    QString IP;
};

#endif // PORTIE_H
