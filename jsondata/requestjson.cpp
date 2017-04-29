#include "requestjson.h"
#include <QMap>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>

RequestJson::RequestJson()
{
    QJsonValue val(-1);
    QJsonValue val2(QString(""));

    m_object.insert(QString("command"),val);
    m_object.insert(QString("params"),val2);
}

RequestJson::RequestJson(const QByteArray jsData)
{
    QJsonDocument doc = QJsonDocument::fromJson(jsData);
    if(doc.isObject()){
        m_object = doc.object();
    }
}

QByteArray RequestJson::getJson()
{
    QJsonDocument doc(m_object);
    return  doc.toJson(QJsonDocument::Compact);
}

void RequestJson::setCommand(const int command)
{
 m_object.insert(QString("command"),QJsonValue(command));
}

int RequestJson::getCommand()
{
 return m_object.value(QString("command")).toInt();
}

void RequestJson::setParams(const QMap<QString, QString> params)
{
    QJsonObject obj;
    QList<QString> keys = params.keys();
    for(int i = 0; i < keys.size(); i++){
        obj.insert(keys.at(i), QJsonValue(params.value(keys.at(i))));
    }
    m_object.insert(QString("params"),QJsonValue(obj));
}

QJsonValue RequestJson::getParams()
{
    if(m_object.contains(QString("params"))){
        return m_object.value(QString("params"));
    }
    return QJsonValue();
}

QByteArray RequestJson::exec()
{
    return QByteArray();
}
