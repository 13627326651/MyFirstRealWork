#ifndef TCPSERVER_H
#define TCPSERVER_H

//文件服务端和数据库服务端基类，完成基本的控制，子类只用重新
//实现readData()方法
#include <QTcpServer>
class TcpSocket;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject* parent = 0, const int port = 9999);
    ~TcpServer();

protected slots:
    void handleDisconnected();
    void hanelServerError(QAbstractSocket::SocketError);
    virtual void readData(QByteArray,qintptr) = 0;

protected:
     void incomingConnection(qintptr handle);

protected:
    QList<TcpSocket*> m_sockList;
};


#endif // TCPSERVER_H
