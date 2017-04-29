#ifndef FILECLIENT_H
#define FILECLIENT_H

#include <QWidget>
class TcpSocket;

namespace Ui {
class FileClient;
}

class FileClient : public QWidget
{
    Q_OBJECT

public:
    explicit FileClient(QWidget *parent = 0);
    ~FileClient();

public slots:
    void readData(QByteArray,qintptr);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FileClient *ui;
    TcpSocket* m_socket;
};

#endif // FILECLIENT_H
