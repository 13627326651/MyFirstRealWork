#include "fileclient.h"
#include "ui_fileclient.h"
#include "tcpsocket.h"
#include "filerequestjson.h"

FileClient::FileClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileClient)
{
    ui->setupUi(this);

    m_socket = new TcpSocket(this);
    m_socket->connectToHost(tr("127.0.0.1"), 7782);
    //connect(m_socket, SIGNAL(connected()), this, SLOT(updateText()));
    connect(m_socket, SIGNAL(readyReadData(QByteArray,qintptr)),
            this, SLOT(readData(QByteArray,qintptr)));
}

FileClient::~FileClient()
{
    delete ui;
}

void FileClient::readData(QByteArray data, qintptr socketDescriptor)
{
    qDebug()<< "client: " << data;
}

//5.1.1.	获取图像文件
void FileClient::on_pushButton_clicked()
{
    FileRequestJson request;
    QMap<QString, QString> params;
    params[QStringLiteral("pid")] =  QStringLiteral("1");
    params[QStringLiteral("sid")] =  QStringLiteral("1");
    params[QStringLiteral("iid")] =  QStringLiteral("1");
    params[QStringLiteral("ImageType")] =  QStringLiteral("0");

    request.setParams(params);
    request.setCommand(1);
    m_socket->sendData(request.getJson()+'\n');
}
