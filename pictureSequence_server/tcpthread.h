#ifndef TCPTHREAD_H
#define TCPTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include <iostream>
#include <QByteArray>
#include <QImage>
using namespace std;
//#include <QErrorMessage>
class TcpThread:public QThread
{
    Q_OBJECT
public:
    explicit TcpThread(int sockDescripter);
    void run();
private:
    int sockDescripter;
    QTcpSocket *tcpSocket;
    QByteArray imagebyte;
signals:
    void imageInfo(QImage &);
private slots:
    void RecvdFile();
};

#endif // TCPTHREAD_H
