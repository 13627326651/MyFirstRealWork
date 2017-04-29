#include "dbrequestjson.h"
#include "responsejson.h"
#include <QMap>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>

DBRequestJson::DBRequestJson()
{
}

DBRequestJson::DBRequestJson(const QByteArray js):
    RequestJson(js)
{

}


QByteArray DBRequestJson::exec()
{

    m_command = m_object.value(QString("command")).toInt();
    m_params = m_object.value(QString("params"));
    ResponseJson response;
    //命令解析
    switch(m_command){
    case 1:     //获取所有病人信息
        response = loadPatients();
        break;
    case 2:     //获取指定患者的所有检查信息
        response = loadStudiesById();
        break;
    case 3:     //获取指定患者指定检查的所有图片信息
        response = loadPatientStudyImgs();
        break;
    case 4:     //添加病人
        response = addPatient();
        break;
    case 5:     //添加检查
        response = addPatientStudy();
        break;
    case 6:     //添加图片信息
        response = addPatientStudyImg();
        break;
    case 7:     //删除病人
        response = deletePatient();
        break;
    case 8:     //删除检查
        response = deleteStudy();
        break;
    case 9:     //删除图片
        response = deleteImg();
        break;
    case 10:    //修改病人信息
        response = modPatient();
        break;
    case 11:      //修改检查信息
        response = modStudy();
        break;
    case 12:      //修改图片信息
        response = modImg();
        break;
    case 13:    //根据病人id获取病人信息
        response = loadPatientById();
        break;
    case 14:    //根据检查id获取检查信息
        response = loadStudyById();
        break;
    case 15:    //获取患者总数
        response = loadPatientsCount();
        break;
    case 16:    //6获取所有检查信息
        response = loadStudies();
        break;
    default:
        break;
    }

    return response.getJson();
}

//3.1.1.	获取所有病人信息
ResponseJson DBRequestJson::loadPatients()
{
    QSqlQuery query;
    QJsonArray msg;
    ResponseJson response;

    if(query.exec(QString("select * from patients"))){
        while(query.next()){
            QJsonObject obj;
            obj.insert(QString("PatientID"), QJsonValue(query.value(0).toInt()));
            obj.insert(QString("FirstName"), QJsonValue(query.value(2).toString()));
            obj.insert(QString("LastName"), QJsonValue(query.value(3).toString()));
            msg.append(obj);
        }
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }

    response.setMessage(msg);
    response.setCommand(m_command);
    return response;
}

//3.1.2.	获取指定患者的所有检查信息
ResponseJson DBRequestJson::loadStudiesById()
{
    QJsonObject params = m_params.toObject();
    QString patientId = params.value(QString("PatientID")).toString();

    QSqlQuery query;
    QJsonArray msg;
    ResponseJson response;

    if(query.exec(QString("select * from studies where PatientID=%1").arg(patientId))){
        while(query.next()){
            QJsonObject obj;
            int SAlignment = query.value(1).toInt();
            QString SDescription = query.value(2).toString();
            QString SComments = query.value(3).toString();

            obj.insert(QString("SAlignment"), QJsonValue(SAlignment));
            obj.insert(QString("SDescription"), QJsonValue(SDescription));
            obj.insert(QString("SComments"), QJsonValue(SComments));
            obj.insert(QString("PatientID"), QJsonValue(patientId));
            msg.append(obj);
        }
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;

    return response;
}


//3.1.3.	获取指定患者指定检查的所有图片信息
ResponseJson DBRequestJson::loadPatientStudyImgs()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString StudyID = params.value(QString("StudyID")).toString();

    QString record = QString("select * from images where PatientID=%1 and StudyID=%2")
            .arg(PatientID)
            .arg(StudyID);

    QSqlQuery query;
    QJsonArray msg;
    ResponseJson response;
    if(query.exec(record)){
        while(query.next()){
            QJsonObject o;
            o.insert(QString("StudyID"),QJsonValue(query.value(1).toInt()));
            o.insert(QString("PatientID"),QJsonValue(query.value(2).toInt()));
            o.insert(QString("IArrayPos"),QJsonValue(query.value(3).toInt()));
            o.insert(QString("AcquireMode"),QJsonValue(query.value(4).toInt()));
            o.insert(QString("TLocation"),QJsonValue(query.value(5).toString()));
            o.insert(QString("IComments"),QJsonValue(query.value(6).toString()));
            msg.append(o);
        }
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}

//3.1.4.	添加病人
ResponseJson DBRequestJson::addPatient()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString PatientNo = "";
    QString FirstName = params.value(QString("FirstName")).toString();
    QString LastName = params.value(QString("LastName")).toString();

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;

    if(query.exec(QString("insert into patients values(%1, '%2', '%3', '%4')")
                  .arg(PatientID)
                  .arg(PatientNo)
                  .arg(FirstName)
                  .arg(LastName))){
        query.exec(QString("select last_insert_rowid() from patients limit 1"));

        query.next();
        int lastId = query.value(0).toInt();
        qDebug()<< "last id" << lastId;
        msg.insert(QString("NewID"),QJsonValue(lastId));
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}

//添加检查
ResponseJson DBRequestJson::addPatientStudy()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString SAlignment = params.value(QString("SAlignment")).toString();
    QString SDescription = params.value(QString("SDescription")).toString();
    QString SComments = params.value(QString("SComments")).toString();

    QString record = QString("insert into studies(PatientID,SAlignment,SDescription,SComments) values(%1, %2, '%3', '%4')")
            .arg(PatientID)
            .arg(SAlignment)
            .arg(SDescription)
            .arg(SComments);

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;

    if(query.exec(record)){
        //得到上次插入的id值
        query.exec(QString("select last_insert_rowid() from studies limit 1"));
        query.next();
        int lastId = query.value(0).toInt();
        msg.insert(QString("NewID"),QJsonValue(lastId));
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}


//3.1.6.	添加图片信息
ResponseJson DBRequestJson::addPatientStudyImg()
{
    QJsonObject params = m_params.toObject();
    QString OnlyGetNewID = params.value(QString("OnlyGetNewID")).toString();
    QString StudyID = params.value(QString("StudyID")).toString();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString IArrayPos = params.value(QString("IArrayPos")).toString();
    QString AcquireMode = params.value(QString("AcquireMode")).toString();
    QString TLocation = params.value(QString("TLocation")).toString();
    QString IComments = params.value(QString("IComments")).toString();

    QString record = QString("insert into images(StudyID,PatientID,IArrayPos,AcquireMode,TLocation,IComments) values(%1, %2, %3, %4, '%5','%6')")
            .arg(StudyID)
            .arg(PatientID)
            .arg(IArrayPos)
            .arg(AcquireMode)
            .arg(TLocation)
            .arg(IComments);
    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;
    if(query.exec(record)){
        //得到上次插入的id值
        query.exec(QString("select last_insert_rowid() from images limit 1"));
        query.next();
        int lastId = query.value(0).toInt();
        //如果只要求得到id，则删除记录
        if(OnlyGetNewID.toInt())
            query.exec(QString("delete from images where id=%1").arg(lastId));

        msg.insert(QString("NewID"),QJsonValue(lastId));
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}


//3.1.7.	删除病人
ResponseJson DBRequestJson::deletePatient()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString record = QString("delete from patients where id=%1")
            .arg(PatientID);

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;
    if(query.exec(record)){
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}

//3.1.8.	删除检查
ResponseJson DBRequestJson::deleteStudy()
{
    QJsonObject params = m_params.toObject();
    QString StudyID = params.value(QString("StudyID")).toString();
    QString record = QString("delete from studies where id=%1")
            .arg(StudyID);

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;
    if(query.exec(record)){
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}

//3.1.9.	删除图片
ResponseJson DBRequestJson::deleteImg()
{
    QJsonObject params = m_params.toObject();
    QString ImageID = params.value(QString("ImageID")).toString();
    QString record = QString("delete from images where id=%1")
            .arg(ImageID);

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;
    if(query.exec(record)){
        response.setSuccess(true);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    response.setMessage(msg);
    return response;
}

//3.1.10.	修改病人信息
ResponseJson DBRequestJson::modPatient()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString PatientNo = params.value(QString("PatientNo")).toString();
    QString FirstName = params.value(QString("FirstName")).toString();
    QString LastName = params.value(QString("LastName")).toString();

    QSqlQuery query;
    ResponseJson response;
    response.setCommand(m_command);
    if(!PatientID.isEmpty()){
        if(!PatientNo.isEmpty())
            if(!query.exec(QString("update patients set PatientNo='%1' where id=%2").arg(PatientNo).arg(PatientID))){
                qDebug() << "update error" << query.lastError();
                response.setSuccess(false);
                return response;
            }
        if(!FirstName.isEmpty())
            if(!query.exec(QString("update patients set FirstName='%1' where id=%2").arg(FirstName).arg(PatientID))){
                qDebug() << "update error" << query.lastError();
                response.setSuccess(false);
                return response;
            }
        if(!LastName.isEmpty())
            if(!query.exec(QString("update patients set LastName='%1' where id=%2").arg(LastName).arg(PatientID))){
                qDebug() << "update error" << query.lastError();
                response.setSuccess(false);
                return response;
            }
    }
    response.setSuccess(true);
    return response;
}


//3.1.11.	修改检查信息
ResponseJson DBRequestJson::modStudy()
{
    ResponseJson response;
    return response;
}


//3.1.11.	修改图片信息
ResponseJson DBRequestJson::modImg()
{

    QJsonObject params = m_params.toObject();
    QString ImageID = params.value(QString("ImageID")).toString();
    QString TLocation = params.value(QString("TLocation")).toString();
    QString IComments = params.value(QString("IComments")).toString();

    QSqlQuery query;
    ResponseJson response;
    response.setCommand(m_command);
    if(!ImageID.isEmpty()){
        if(!TLocation.isEmpty())
            if(!query.exec(QString("update images set TLocation='%1' where id=%2").arg(TLocation).arg(ImageID))){
                qDebug() << "update error" << query.lastError();
                response.setSuccess(false);
                return response;
            }
        if(!IComments.isEmpty())
            if(!query.exec(QString("update images set IComments='%1' where id=%2").arg(IComments).arg(ImageID))){
                qDebug() << "update error" << query.lastError();
                response.setSuccess(false);
                return response;
            }
    }
    response.setSuccess(true);
    return response;;
}

//3.1.13.	根据病人id获取病人信息
ResponseJson DBRequestJson::loadPatientById()
{

    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;

    if(query.exec(QString("select * from patients where id=%1").arg(PatientID))){
        if(query.next()){
            msg.insert(QString("PatientID"),QJsonValue(query.value(0).toInt()));
            msg.insert(QString("PatientNo"),QJsonValue(query.value(1).toInt()));
            msg.insert(QString("FirstName"),QJsonValue(query.value(2).toString()));
            msg.insert(QString("LastName"),QJsonValue(query.value(3).toString()));
            response.setMessage(msg);
            response.setSuccess(true);
        }else{
            response.setSuccess(false);
        }
    }else{
        response.setSuccess(false);
    }

    response.setMessage(msg);
    response.setCommand(m_command);
    return response;
}

//3.1.14.	根据检查id获取检查信息
ResponseJson DBRequestJson::loadStudyById()
{
    QJsonObject params = m_params.toObject();
    QString PatientID = params.value(QString("PatientID")).toString();
    QString StudyID = params.value(QString("StudyID")).toString();

    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;

    if(query.exec(QString("select * from studies where PatientID=%1 and id=%2")
                  .arg(PatientID)
                  .arg(StudyID))){
        if(query.next()){
            msg.insert(QString("StudyID"),QJsonValue(query.value(0).toInt()));
            msg.insert(QString("PatientID"),QJsonValue(query.value(1).toInt()));
            msg.insert(QString("SAlignment"),QJsonValue(query.value(2).toInt()));
            msg.insert(QString("SDescription"),QJsonValue(query.value(3).toString()));
            msg.insert(QString("SComments"),QJsonValue(query.value(4).toString()));
            response.setMessage(msg);
            response.setSuccess(true);
        }else{
            response.setSuccess(false);
        }
    }else{
        response.setSuccess(false);
    }

    response.setMessage(msg);
    response.setCommand(m_command);
    return response;
}

//获取患者总数
ResponseJson DBRequestJson::loadPatientsCount()
{
    QSqlQuery query;
    QJsonObject msg;
    ResponseJson response;
    if(query.exec(QString("select count() from patients"))){
        if(query.next()){
            msg.insert(QString("Count"),QJsonValue(query.value(0).toInt()));
            response.setSuccess(true);
        }else{
            response.setSuccess(false);
        }
    }else{
        response.setSuccess(false);
    }
    response.setMessage(msg);
    response.setCommand(m_command);
    return response;
}


//3.1.16获取所有检查信息
ResponseJson DBRequestJson::loadStudies()
{
    QSqlQuery query;
    QJsonArray msg;
    ResponseJson response;
    if(query.exec(QString("select * from studies"))){
        while(query.next()){
            QJsonObject o;
            o.insert(QString("StudyID"),QJsonValue(query.value(0).toInt()));
            o.insert(QString("PatientID"),QJsonValue(query.value(1).toInt()));
            o.insert(QString("SAlignment"),QJsonValue(query.value(2).toInt()));
            o.insert(QString("SDescription"),QJsonValue(query.value(3).toString()));
            o.insert(QString("SComments"),QJsonValue(query.value(4).toString()));
            msg.append(o);
        }
        response.setSuccess(true);
        response.setMessage(msg);
    }else{
        response.setSuccess(false);
    }
    response.setCommand(m_command);
    return response;
}
