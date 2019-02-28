#ifndef REQUEST_H
#define REQUEST_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <QUrl>

class Request
{
public:
    Request(const QString& request);
    const QString& GetType() const;
    const QString& GetUrl() const;
    const QString& GetPath() const;
    const QString& GetBody() const;
    QString GetCgi (const QString& name) const;
private:
    QString Type_;
    QString Url_;
    QString Path_;
    QString Body_;
    QMap<QString,QString> Cgi_;
};

#endif // REQUEST_H
