#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject* parent = 0);
    void sendData(QByteArray msg);

signals:
    void readyReadData(QByteArray, qintptr);

public slots:
    void readData();

private:
    int m_dataLeft;
};

#endif // TCPSOCKET_H
