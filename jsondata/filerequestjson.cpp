#include "filerequestjson.h"
#include "responsejson.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <QFile>
#include "tcpsocket.h"

FileRequestJson::FileRequestJson():
    m_socket(NULL)
{

}

FileRequestJson::FileRequestJson(const QByteArray js)
    :RequestJson(js), m_socket(NULL)
{

}

QByteArray FileRequestJson::exec()
{
    m_command = m_object.value(QString("command")).toInt();
    m_params = m_object.value(QString("params"));
    //命令解析
    switch(m_command){
    case 1:     //5.1.1.	获取图像文件
        loadImage();
        break;
    case 2:     //

        break;
    case 3:     //

        break;
    case 4:     //

        break;
    case 5:     //

        break;
    case 6:     //

        break;
    default:
        break;
    }
    return response.getJson();
}

void FileRequestJson::setSocket(TcpSocket *socket)
{
    m_socket = socket;
}

static int calculateFileSize(const QString path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly)){
        qDebug()<< "file open error" << file.errorString();
        return 0;
    }
    int s = file.size();
    file.close();
    return s;
}

//5.1.1.	获取图像文件
void FileRequestJson::loadImage()
{
//    QJsonObject params = m_params.toObject();
//    QString pid = params.value(QString("pid")).toString();

//    QSqlQuery query;
//    QJsonObject msg;
//    FileResponseJson response;
//    QString filePath;


//    if(query.exec(QString("select * from image where pid=%1")
//                  .arg(pid))){
//        if(query.next()){
//            filePath = query.value(5).toString();

//            //待完善。。。。。。
//            msg.insert(QString("FileSize"),QJsonValue(fileSize));
//            response.setMessage(msg);
//            response.setSuccess(true);
//        }else{
//            response.setSuccess(false);
//        }
//    }else{
//        response.setSuccess(false);
//    }

//    response.setMessage(msg);
//    response.setCommand(m_command);

//    if(m_socket)
//        m_socket->sendData(response.getJson());
}
