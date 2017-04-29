#include "dbserver.h"
#include <QJsonDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonArray>
#include "tcpserver.h"
#include "dbrequestjson.h"
#include "tcpsocket.h"


DbServer::DbServer(QObject *parent, const int port):
    TcpServer(parent, port)
{

}


void DbServer::readData(QByteArray data, qintptr descriptor)
{
    TcpSocket* socket;
    for(int i = 0; i < m_sockList.size(); i++){
        socket = m_sockList.at(i);

        if(socket->socketDescriptor() == descriptor){
            qDebug()<< "server readData() " << data;
            QByteArray arr = DBRequestJson(data).exec();
            socket->sendData(arr);
        }
    }
}

