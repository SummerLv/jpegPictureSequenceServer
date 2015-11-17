#include "tcpthread.h"

TcpThread::TcpThread(int sockDescripter)
    :sockDescripter(sockDescripter)
{
}

void TcpThread::run(){
    tcpSocket = new QTcpSocket();
    if(tcpSocket->setSocketDescriptor(sockDescripter) == false)
    {
        cerr<<"set socket descriptor error"<<endl;
        return;
    }
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(RecvdFile()));
    exec();
}

void TcpThread::RecvdFile()
{
    long receivelen;
    //imagebyte.clear();
    QByteArray receivepic;
    //读入数据
    receivelen = tcpSocket->bytesAvailable();
    receivepic = tcpSocket->readAll();

    imagebyte.append(receivepic);

    if(receivelen != 0){
        cout<<"receivelen"<<receivelen<<endl;
        QImage image = QImage::fromData(imagebyte , "PNG");
        emit imageInfo(image);
        imagebyte.resize(0);
    }
}
