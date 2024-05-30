#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTimer>

class heartbeat
{// Q_OBJECT
public:
    heartbeat();
    QTimer * moveTimer;

};

#endif // HEARTBEAT_H
