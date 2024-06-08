#include "MainApplication.h"
#include <iostream>
#include <QCoreApplication>

MainApplication::MainApplication(QObject *parent) : QObject(parent) {
    // Initialize the timer for heartbeat
    heartbeatTimer = new QTimer(this);
    connect(heartbeatTimer, &QTimer::timeout, this, &MainApplication::sendHeartbeat);
  //  QObject::connect(heartbeatTimer,SIGNAL(timeout()),this,SLOT(sendHeartbeat()));
    heartbeatTimer->start(20000); // Send heartbeat every 20 seconds
}

void MainApplication::run() {
    commManager.connectSocket("ventilator", "tcp://benternet.pxl-ea-ict.be:24041", ZMQ_PUSH);
    commManager.connectSocket("subscriber", "tcp://benternet.pxl-ea-ict.be:24042", ZMQ_SUB);
    commManager.connectSocket("heartbeat", "tcp://benternet.pxl-ea-ict.be:24041", ZMQ_PUSH);

    std::string topicStrSub = "DnD?>Dice>";
    commManager.sockets["subscriber"].setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());

    while (true) {
        std::string received_msg = commManager.receiveMessage("subscriber");
        std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

        QCoreApplication::processEvents();

        QString qstr = QString::fromStdString(received_msg);
        if (qstr.startsWith("DnD?>Dice>")) {

            if(qstr.endsWith(diceRoller.userName)) {

                if (qstr.contains(">ADV>")) {
                    msgToSend = diceRoller.rollDiceAdv(qstr);
                } else if (qstr.contains(">DIS>")) {
                    msgToSend = diceRoller.rollDiceAdv(qstr);
                } else {
                    msgToSend = diceRoller.rollDice(qstr);
                }

                std::cout << "Check OK: " << msgToSend.toStdString() << std::endl;
                commManager.sendMessage("ventilator", msgToSend.toStdString());

            }
            else {
                msgToSend = "ERROR:  You little mothafucka, this command is not correct... bitchslap Bart";
                std::cout << msgToSend.toStdString() << std::endl;
                commManager.sendMessage("ventilator", msgToSend.toStdString());
            }
        }
        else {
            std::cout << "Received : " << qstr.toStdString() << std::endl;
        }

      //  QCoreApplication::processEvents();
    }
}

void MainApplication::sendHeartbeat() {
    commManager.sendMessage("heartbeat", "HEARTBEAT DND_APP");
}
