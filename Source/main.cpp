#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
  //  w.setStyleSheet("background-image:url(.qrc:/../../../IDM/Image/i (2).jpg)");
    w.show();


    return a.exec();
}
