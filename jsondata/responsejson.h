#ifndef RESPONSEJSON_H
#define RESPONSEJSON_H

#include <QJsonObject>


class ResponseJson {
public:
    ResponseJson();
    ResponseJson(const QByteArray js);
    void setSuccess(const bool isSuccess = true);
    void setMessage(const QJsonValue val);
    QByteArray getJson();
    void setCommand(const int command);
    int getCommand();

protected:
    QJsonObject m_object;
};



class FileResponseJson : public ResponseJson {
public:
    FileResponseJson();
    FileResponseJson(const QByteArray js);
    QByteArray exec();
protected:
    QJsonObject m_object;
};

#endif // RESPONSEJSON_H
