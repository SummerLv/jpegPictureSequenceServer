// server's main.cpp
#include <QApplication>
#include <iostream>
#include "dialog.h"
#include "tcpdialog.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //从class的类构造函数调用套接字
    Server server;
   // server.show();
    //tcpdialog dialog;
   // dialog.show();
    //显示状态
   // server.begin();
    return a.exec();
}
