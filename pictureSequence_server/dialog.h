#ifndef DIALOG_H
#define DIALOG_H

#include <QtNetwork/QTcpServer>
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QBuffer>
#include <QImage>
#include <QImageReader>
#include <QDebug>
#include <QFile>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>
#include <QDateTime>
class Server: public QDialog
{
Q_OBJECT
public:
    Server(QWidget * parent = 0);
    ~Server();
    void begin();

public slots:
    void acceptConnection();
    void startRead();
    void Display();
    bool getPicture();
private:
   // bool getPicture();
    void getPicMessage();
private:
    QTcpServer server;
    QTcpSocket *client;
    QByteArray imagebyte;
    QLabel *display;
    QTimer *timer;
    QImage image;
    QImage *testimage;
    bool firstim;
    int msgSize;
   // QFile file;
};

#endif // DIALOG_H
