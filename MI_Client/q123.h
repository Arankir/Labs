#ifndef Q123_H
#define Q123_H

#include <QWidget>

namespace Ui {
class q123;
}

class q123 : public QWidget
{
    Q_OBJECT

public:
    explicit q123(QWidget *parent = nullptr);
    ~q123();

private:
    Ui::q123 *ui;
};

#endif // Q123_H
