#include "dialog.h"
#include <iostream>

using namespace std;
int delay = 200;
int frame = 1;

Server::Server(QWidget *parent)
    : QDialog(parent)

{
    display = new QLabel("3G Transform");
    firstim = false;
    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->addWidget(display,0,0,6,6);
    testimage = new QImage;
//   bool f1 = testimage->load("D:\\123.png");
//   cout<<f1<<endl;
    timer = new QTimer(this);
    msgSize = -1;
  //  timer->start(1000);
    //将newConnection()与acceptConnection()连结
    connect(&server, SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Display()));
    //timer->start(300);
    cout<<"listening..."<<endl;
    //bool QTcpServer::listen ( const QHostAddress & address = QHostAddress::Any, quint16 port = 0 )
    //Tells the server to listen for incoming connections on address address and port port.
    //If port is 0, a port is chosen automatically.
    //If address is QHostAddress::Any, the server will listen on all network interfaces.
    //在任意网络接口监听
    //server.listen(QHostAddress::Any,8888);
    //在服务端IP地址172.18.218.2的端口8888监听
    QHostAddress addr("222.197.174.76");
    server.listen(QHostAddress::Any,10150);
    cout<<"listen..."<<endl;
}

Server::~Server()
{
    cout<<"closing..."<<endl;
    //关闭服务器
    server.close();
}

void Server::acceptConnection()
{
    //返回等待的连接
    cout<<"connecting..."<<endl;
    client = server.nextPendingConnection();
    qDebug()<<"client ip: "<<client->peerAddress().toString();
    qDebug()<<"client port: "<<client->peerPort();
//    while(1)
//    {
//        if(!getPicture()){
//            cout<<"no picture data"<<endl;
//        }

//       // getPicMessage();
//    }

    connect(client, SIGNAL(readyRead()),this, SLOT(getPicture()));
    //将readyRead()与startRead()连结
   // connect(client, SIGNAL(readyRead()),this, SLOT(startRead()));
}

bool Server::getPicture()
{
    QDataStream in(client);

    if (client->bytesAvailable() && msgSize == -1) {
    in >> msgSize;
   // cout<<msgSize<<endl;
    //cout<<client->bytesAvailable();
    }

    while (client->bytesAvailable() < msgSize - sizeof(int)) {
       if(!client->waitForReadyRead(100))
        return false;
    }

    QByteArray byte = client->read(msgSize);

   // qDebug()<<"get frame "<<frame++<<", time:"<<QDateTime::currentDateTime();
    image = QImage::fromData(byte , "JPG");
    if(firstim == false)
    {
        image.save("D:\\hhh.JPG");
        firstim = true;
        timer->start(40);
    }
    msgSize = -1;
    return true;
}

void Server::getPicMessage()
{

}

void Server::Display()
{
        display->setPixmap(QPixmap::fromImage(image));
        display->show();
}

void Server::startRead()
{
   // cout<<"start Read"<<endl;
    long receivelen;
    //imagebyte.clear();
    QByteArray receivepic;
    //读入数据
    receivelen = client->bytesAvailable();
    receivepic = client->readAll();

    imagebyte.append(receivepic);

    //QFile file("D:\\test.h264");
    if(receivelen != 0){
        qDebug()<<"time"<<QDateTime::currentDateTime();
        cout<< "receivelen"<<receivelen<<endl;
      if(imagebyte.size() >= 20000)
      {
          if(firstim == false)
          {
              firstim = true;
              timer->start(100);
          }
        cout<<"imagebyte"<<imagebyte.size()<<endl;
//        for(int i = 0;i<frame;i++)
//        {
//            cout<<"frame"<<i<<endl;
//            QByteArray temp = imagebyte.mid(i*153600,153600);
//            while(delay-- > 0);
//                delay = 20000000;
//           // image = QImage::fromData(temp , "JPG");
//        }
        image = QImage::fromData(imagebyte , "JPG");
        imagebyte.resize(0);
      }
      // if(!file.open(QIODevice::WriteOnly)){
       //     return;
       // }
      //  file.write(imagebyte);
    }
}

void Server::begin()
{
    //显示状态
     cout<<"try to connect..."<<endl;
}
