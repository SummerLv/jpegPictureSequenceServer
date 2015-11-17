#include "tcpserver.h"
TcpServer::TcpServer()
{

}

void TcpServer::incomingConnection(int socketDescriptor)
{
    cout<<"receive connection"<<endl;
    TcpThread *thread = new TcpThread(socketDescriptor);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(thread,SIGNAL(imageInfo(QImage&)),this,SIGNAL(imageInfo(QImage&)));
    thread->start();
}
