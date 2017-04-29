#include "mywidget.h"
#include "ui_mywidget.h"
#include <QMap>
#include "dbrequestjson.h"
#include "responsejson.h"
#include "tcpsocket.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget),
    m_socket(NULL)
{
    ui->setupUi(this);

    m_socket = new TcpSocket(this);

    m_socket->connectToHost(tr("127.0.0.1"), 7781);
    connect(m_socket, SIGNAL(connected()), this, SLOT(updateText()));
    connect(m_socket, SIGNAL(readyReadData(QByteArray,qintptr)),
            this, SLOT(readData(QByteArray,qintptr)));

    ui->textBrowser->setText("等待链接！");
    ui->pushButton->setEnabled(false);
}

MyWidget::~MyWidget()
{
    delete ui;
}


//1.  获取所以病人信息
void MyWidget::on_pushButton_clicked()
{
    DBRequestJson request;
    request.setCommand(1);
    m_socket->sendData(request.getJson()+'\n');

}

void MyWidget::updateText()
{
    ui->textBrowser->setText(tr("链接成功..."));
    ui->pushButton->setEnabled(true);
}

void MyWidget::readData(QByteArray data, qintptr descriptor)
{
    qDebug() << "response size " << data.size();
    ResponseJson response(data);
    ui->textBrowser->setText(response.getJson());
}

//3.1.4.	添加病人
void MyWidget::on_pushButton_4_clicked()
{
    DBRequestJson jd;
    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    params[QStringLiteral("FirstName")] =  QStringLiteral("gp");
    params[QStringLiteral("LastName")] =  QStringLiteral("x");

    jd.setParams(params);
    jd.setCommand(4);
    m_socket->sendData(jd.getJson()+'\n');
}

//3.1.2.	获取指定患者的所有检查信息
void MyWidget::on_pushButton_2_clicked()
{
    DBRequestJson request;
    request.setCommand(2);

    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}


//3.1.6.	添加图片信息
void MyWidget::on_pushButton_6_clicked()
{
    DBRequestJson request;
    request.setCommand(6);

    QMap<QString, QString> params;
    params[QStringLiteral("OnlyGetNewID")] =  QStringLiteral("0");
    params[QStringLiteral("StudyID")] =  QStringLiteral("1");
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    params[QStringLiteral("IArrayPos")] =  QStringLiteral("6");
    params[QStringLiteral("AcquireMode")] =  QStringLiteral("4");
    params[QStringLiteral("TLocation")] =  QStringLiteral("010203");
    params[QStringLiteral("IComments")] =  QStringLiteral("");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}
//3.1.3.	获取指定患者指定检查的所有图片信息
void MyWidget::on_pushButton_3_clicked()
{
    DBRequestJson request;
    request.setCommand(3);

    QMap<QString, QString> params;
    params[QStringLiteral("StudyID")] =  QStringLiteral("1");
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}


//3.1.5.	添加检查
void MyWidget::on_pushButton_5_clicked()
{
    DBRequestJson request;
    request.setCommand(5);

    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    params[QStringLiteral("SAlignment")] =  QStringLiteral("18");
    params[QStringLiteral("SDescription")] =  QStringLiteral("18 pictures");
    params[QStringLiteral("SComments")] =  QStringLiteral("");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}
//3.1.7.	删除病人
void MyWidget::on_pushButton_7_clicked()
{
    DBRequestJson request;
    request.setCommand(7);
    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");

    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}


//3.1.8.	删除检查
void MyWidget::on_pushButton_8_clicked()
{
    DBRequestJson request;
    request.setCommand(8);
    QMap<QString, QString> params;
    params[QStringLiteral("StudyID")] =  QStringLiteral("1");

    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}

//3.1.9.	删除图片
void MyWidget::on_pushButton_9_clicked()
{
    DBRequestJson request;
    request.setCommand(9);
    QMap<QString, QString> params;
    params[QStringLiteral("ImageID")] =  QStringLiteral("1");

    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}

//3.1.10.	修改病人信息
void MyWidget::on_pushButton_10_clicked()
{
    DBRequestJson request;
    request.setCommand(10);
    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    params[QStringLiteral("PatientNo")] =  QStringLiteral("123455");
    params[QStringLiteral("FirstName")] =  QStringLiteral("徐");
    params[QStringLiteral("LastName")] =  QStringLiteral("国培");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}

//3.1.12.	修改图片信息
void MyWidget::on_pushButton_12_clicked()
{
    DBRequestJson request;
    request.setCommand(12);
    QMap<QString, QString> params;
    params[QStringLiteral("ImageID")] =  QStringLiteral("1");
    params[QStringLiteral("TLocation")] =  QStringLiteral("1111111");
    params[QStringLiteral("IComments")] =  QStringLiteral("*************");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}

//3.1.13.	根据病人id获取病人信息
void MyWidget::on_pushButton_13_clicked()
{
    DBRequestJson request;
    request.setCommand(13);
    QMap<QString, QString> params;
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}


//3.1.14.	根据检查id获取检查信息
void MyWidget::on_pushButton_14_clicked()
{
    DBRequestJson request;
    request.setCommand(14);
    QMap<QString, QString> params;
    params[QStringLiteral("StudyID")] =  QStringLiteral("1");
    params[QStringLiteral("PatientID")] =  QStringLiteral("1");
    request.setParams(params);

    m_socket->sendData(request.getJson()+'\n');
}

//1.15获取患者总数
void MyWidget::on_pushButton_15_clicked()
{
    DBRequestJson request;
    request.setCommand(15);
    m_socket->sendData(request.getJson()+'\n');
}

//3.1.16获取所有检查信息
void MyWidget::on_pushButton_16_clicked()
{
    DBRequestJson request;
    request.setCommand(16);
    m_socket->sendData(request.getJson()+'\n');
}
