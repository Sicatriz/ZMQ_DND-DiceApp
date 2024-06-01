#include "MainApplication.h"
#include <iostream>

void MainApplication::run() {
    commManager.connectSockets();

    while (true) {
        std::string received_msg = commManager.receiveMessage();
        std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

        QString qstr = QString::fromStdString(received_msg);
        if (qstr.startsWith("DnD?>Dice>")) {

            if(qstr.endsWith(diceRoller.userName))
            {
                msgToSend = diceRoller.rollDice(qstr);
                std::cout << "Check OK: " << msgToSend.toStdString() << std::endl;
                commManager.sendMessage(msgToSend.toStdString());
            }
            else
            {
                msgToSend = "ERROR:  You little mothafucka, this command is not correct... bitchslap Bart";
                std::cout << msgToSend.toStdString() << std::endl;
                commManager.sendMessage(msgToSend.toStdString());
            }
        }
        else
        {
            std::cout << "Received : " << qstr.toStdString() << std::endl;
        }
    }
}
