#include "request.h"
#include <QTextCodec>

Request::Request(const QString &request)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QStringList headers = request.split("\r\n");
    QStringList StartLine = headers[0].split(' ');
    this->Type_=StartLine[0];
    this->Url_=StartLine[1];
    headers.pop_front();
    this->Body_ = headers.back();
    headers.pop_back();

    QUrl url(Url_);
    this->Path_=url.path();
    QString cgistr = url.query();
    QStringList cgi = url.query().split('&');
    for (const auto& param : cgi){
        QStringList parametrs = param.split('=');
        if(parametrs.size()==2){
            this->Cgi_[parametrs[0]]=parametrs[1];
        }
    }
}

QString Request::GetCgi(const QString &name) const
{
    if(Cgi_.contains(name)){
        return  Cgi_[name];
    }
    else {
        return QString();
    }
}

const QString& Request::GetUrl() const{
    return this->Url_;
}

const QString& Request::GetBody() const{
    return  this->Body_;
}

const QString& Request::GetPath() const{
    return this->Path_;
}

const QString& Request::GetType() const{
    return this->Type_;
}
