#ifndef DBSERVER_H
#define DBSERVER_H

#include "tcpserver.h"


class DbServer : public TcpServer{
public:
    DbServer(QObject* parent = 0, const int port = 7781);
    void readData(QByteArray data, qintptr descriptor);
};


#endif // DBSERVER_H
