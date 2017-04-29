#include "responsejson.h"
#include <QMap>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>


ResponseJson::ResponseJson()
{
    QJsonValue val(0);
    QJsonValue val2(-1);
    QJsonValue val3(QString(""));

    m_object.insert(QString("success"),val);
    m_object.insert(QString("command"),val2);
    m_object.insert(QString("message"),val3);
}

ResponseJson::ResponseJson(const QByteArray js)
{
    QJsonDocument doc = QJsonDocument::fromJson(js);
    if(doc.isObject()){
        m_object = doc.object();
    }
}

void ResponseJson::setSuccess(const bool isSuccess)
{
    if(isSuccess)
        m_object.insert(QString("success"),QJsonValue(1));
    else
        m_object.insert(QString("success"),QJsonValue(0));
}

void ResponseJson::setMessage(const QJsonValue val)
{
    m_object.insert(QString("message"), val);
}

QByteArray ResponseJson::getJson()
{
    QJsonDocument doc(m_object);

    return  doc.toJson(QJsonDocument::Compact);
}

void ResponseJson::setCommand(const int command)
{
    m_object.insert(QString("command"),QJsonValue(command));
}

int ResponseJson::getCommand()
{
     return m_object.value(QString("command")).toInt();
}




FileResponseJson::FileResponseJson()
{

}

FileResponseJson::FileResponseJson(const QByteArray js)
    :ResponseJson(js)
{

}

QByteArray FileResponseJson::exec()
{
    return QByteArray();
}
