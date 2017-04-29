#ifndef REQUETJSON_H
#define REQUETJSON_H

#include <QJsonObject>

class RequestJson{
public:
    RequestJson();
    RequestJson(const QByteArray jsData);
    QByteArray getJson();
    void setCommand(const int command);
    int getCommand();
    void setParams(const QMap<QString,QString> params);
    QJsonValue getParams();
    virtual QByteArray exec();

protected:
    int m_command;
    QJsonValue m_params;
    QJsonObject m_object;
};



#endif // REQUETJSON_H
