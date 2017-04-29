#include "tcpserver.h"
#include "tcpsocket.h"
#include <QJsonDocument>


TcpServer::TcpServer(QObject *parent, const int port):
    QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
    setMaxPendingConnections(30);
}

TcpServer::~TcpServer()
{
    qDeleteAll(m_sockList);
    m_sockList.clear();
}

//处理断线客户
void TcpServer::handleDisconnected()
{
    for(int i = 0; i < m_sockList.size(); i++)
    {
        TcpSocket* socket = m_sockList.at(i);
        if(socket->socketDescriptor() == -1 ){
            socket->deleteLater();
            m_sockList.removeOne(socket);
        }
    }
}

//有新客户
void TcpServer::incomingConnection(qintptr handle)
{
    TcpSocket* socket = new TcpSocket( this);
    socket->setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyReadData(QByteArray,qintptr)),
            this, SLOT(readData(QByteArray,qintptr)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(handleDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(hanelServerError(QAbstractSocket::SocketError)));

    m_sockList.append(socket);
}


void TcpServer::hanelServerError(QAbstractSocket::SocketError err)
{
    qDebug()<< "handleSocketError() " << err << errorString();
}


