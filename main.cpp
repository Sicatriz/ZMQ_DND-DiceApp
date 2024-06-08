#include "MainApplication.h"
#include <QCoreApplication>
#include <ctime>
#include <iostream>
// #include <string>
#include <zmq.hpp>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTimer>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    srand(static_cast<unsigned>(time(NULL)));

    try {
        MainApplication app;
        app.run();
    } catch (zmq::error_t &ex) {
        std::cerr << "Caught an exception : " << ex.what() << std::endl;
    }

    return 0;
}
