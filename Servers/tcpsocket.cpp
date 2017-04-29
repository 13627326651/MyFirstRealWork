#include "tcpsocket.h"
#include <QDebug>


TcpSocket::TcpSocket(QObject *parent):
    QTcpSocket(parent),
    m_dataLeft(0)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readData()));
}

void TcpSocket::sendData(QByteArray msg)
{
    int len = write(msg);
    if(len <= 0)
        qDebug()<< "sendData() write error!";
}


void TcpSocket::readData()
{
    if(bytesAvailable() > 0){
        emit readyReadData(readAll(), socketDescriptor());
    }
}


