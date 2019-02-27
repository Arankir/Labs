#include <QCoreApplication>
#include <myserver.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Rus");
    MyServer server;
    server.startServer();

    return a.exec();
}
