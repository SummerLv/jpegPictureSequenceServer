#-------------------------------------------------
#
# Project created by QtCreator 2014-04-08T10:46:59
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_receive_pic
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    tcpserver.cpp \
    tcpthread.cpp \
    tcpdialog.cpp

HEADERS  += dialog.h \
    tcpserver.h \
    tcpthread.h \
    tcpdialog.h
