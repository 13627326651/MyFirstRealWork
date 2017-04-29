#include "mainwindow.h"
#include "dbserver.h"
#include "fileserver.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //m_dbServer = new DbServer(this);
    m_fileServer = new FileServer(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}
