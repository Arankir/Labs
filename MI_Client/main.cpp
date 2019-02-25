#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_ALL,"Rus");
    MainWindow w;
    w.show();

    return a.exec();
}
