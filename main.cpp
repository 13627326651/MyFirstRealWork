#include "mainwindow.h"
#include "mywidget.h"
#include "fileclient.h"
#include <QApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

static void createDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open()){
        qDebug()<< "db open error!" << db.lastError();
    }

    QSqlQuery query(db);
    if(!query.exec("create table patients(id integer not null primary key autoincrement,"
                   " PatientNo integer, "
                   " FirstName varchar(50), "
                   "LastName varchar(50))")){
        qDebug()<< "create table error!" << query.lastError();
    }

    if(!query.exec("create table studies(id integer not null primary key autoincrement , "
                   "PatientID integer, "
                   "SAlignment integer,"
                   "SDescription text,"
                   "SComments text)")){
        qDebug()<< "create table error!" << query.lastError();
    }

    if(!query.exec("create table images(id integer not null primary key autoincrement, "
                   "StudyID integer,"
                   "PatientID integer,"
                   "IArrayPos integer,"
                   "AcquireMode integer,"
                   "TLocation text,"
                   "IComments text)")){

        qDebug()<< "create table error!" << query.lastError();
    }

    if(!query.exec("create table image(id integer not null primary key autoincrement, "
                   "pid integer,"
                   "sid integer,"
                   "iid integer,"
                   "ImageType integer,"
                   "path text)")){

        qDebug()<< "create table error!" << query.lastError();
    }

    if(!query.exec("insert into image(pid, sid, iid, ImageType, path) values (1, 1, 1, 0, 'image/view.png')")){

        qDebug()<< "insert table error!" << query.lastError();
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    createDb();

    MainWindow w;
    FileClient client;
    client.show();
    w.show();

    return a.exec();
}
