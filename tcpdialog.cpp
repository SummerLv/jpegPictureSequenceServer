#include "tcpdialog.h"
#include "tcpserver.h"
tcpdialog::tcpdialog()
{
    display = new QLabel;
    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->addWidget(display,0,0,6,6);
    setLayout(mainlayout);
    TcpServer *tcpServer = new TcpServer();
    tcpServer->listen(QHostAddress::Any,10150);
    cout<<"listening..."<<endl;
    connect(tcpServer,SIGNAL(imageInfo(QImage&)),this,SLOT(DisplayImage(QImage&)));
}

void tcpdialog::DisplayImage(QImage &image){
    cout<<"receive image"<<endl;
    display->setPixmap(QPixmap::fromImage(image));
}
