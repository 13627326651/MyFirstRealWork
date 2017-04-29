#ifndef FILEREQUESTJSON_H
#define FILEREQUESTJSON_H

#include "requestjson.h"
class TcpSocket;

class FileResponseJson;

class FileRequestJson : public RequestJson{
public:
    FileRequestJson();
    FileRequestJson(const QByteArray js);
    virtual QByteArray exec();

    void setSocket(TcpSocket* socket);
private:
    TcpSocket* m_socket;

    FileResponseJson loadImage();

};
#endif // FILEREQUESTJSON_H
