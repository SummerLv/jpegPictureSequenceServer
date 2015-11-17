#ifndef TCPDIALOG_H
#define TCPDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QImage>
class tcpdialog:public QDialog
{
    Q_OBJECT
public:
    tcpdialog();
private:
   QLabel *display;
private slots:
   void DisplayImage(QImage &);
};

#endif // TCPDIALOG_H
