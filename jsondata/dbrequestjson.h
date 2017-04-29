#ifndef DBREQUESTJSON_H
#define DBREQUESTJSON_H

#include "requestjson.h"

class ResponseJson;
class DBRequestJson : public RequestJson{
public:
    DBRequestJson();
    DBRequestJson(const QByteArray js);
    virtual QByteArray exec();
private:
    //指令操作1-16
    ResponseJson loadPatients();
    ResponseJson loadStudiesById();
    ResponseJson loadPatientStudyImgs();
    ResponseJson addPatient();
    ResponseJson addPatientStudy();
    ResponseJson addPatientStudyImg();
    ResponseJson deletePatient();
    ResponseJson deleteStudy();
    ResponseJson deleteImg();
    ResponseJson modPatient();
    ResponseJson modStudy();
    ResponseJson modImg();
    ResponseJson loadPatientById();
    ResponseJson loadStudyById();
    ResponseJson loadPatientsCount();
    ResponseJson loadStudies();
};

#endif // DBREQUESTJSON_H
