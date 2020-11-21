#include "mainwindow.h"
#include <QApplication>
#include"login.h"
#include"QDebug"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login l;
    bool test=l.creatLogin();
    if(test) qDebug()<<"connection reuissite";
    else
        qDebug()<<"failed ";

 w.show();
    return a.exec();
}
