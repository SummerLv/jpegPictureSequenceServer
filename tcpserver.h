#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include "tcpthread.h"
class TcpServer:public QTcpServer
{
    Q_OBJECT
public:
        explicit TcpServer();
signals:
        void imageInfo(QImage &);
protected:
        void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVER_H
