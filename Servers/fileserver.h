#ifndef FILESERVER_H
#define FILESERVER_H
#include "tcpserver.h"

class FileServer : public TcpServer{
public:
    FileServer(QObject* parent = 0, const int port = 7782);
     void readData(QByteArray,qintptr);
};

#endif // FILESERVER_H
