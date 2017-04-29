#include "fileserver.h"
#include <QJsonDocument>
#include "tcpsocket.h"
#include "filerequestjson.h"

FileServer::FileServer(QObject *parent, const int port):
    TcpServer(parent, port)
{

}

void FileServer::readData(QByteArray data, qintptr descriptor)
{
    TcpSocket* socket;
    for(int i = 0; i < m_sockList.size(); i++){
        socket = m_sockList.at(i);

        if(socket->socketDescriptor() == descriptor){
            //qDebug()<< "server readData() " << data;
            FileRequestJson request(data);
            request.setSocket(socket);
            request.exec();
        }
    }
}

