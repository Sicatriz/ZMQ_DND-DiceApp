#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>
#include <QStringList>
#include <QDebug>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

