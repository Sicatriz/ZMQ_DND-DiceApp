#include "MainApplication.h"
#include <iostream>

void MainApplication::run() {
    commManager.connectSocket("ventilator", "tcp://benternet.pxl-ea-ict.be:24041", ZMQ_PUSH);
    commManager.connectSocket("subscriber", "tcp://benternet.pxl-ea-ict.be:24042", ZMQ_SUB);

    std::string topicStrSub = "DnD?>Dice>";
    commManager.sockets["subscriber"].setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());

    while (true) {
        std::string received_msg = commManager.receiveMessage("subscriber");
        std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

        QString qstr = QString::fromStdString(received_msg);
        if (qstr.startsWith("DnD?>Dice>")) {

            if(qstr.endsWith(diceRoller.userName))
            {

                if (qstr.contains(">advantage>")) {
                    // msgToSend = diceRoller.rollWithAdvantage(qstr);
                    msgToSend = "ADV ROLL";
                } else if (qstr.contains(">disadvantage>")) {
                    //  msgToSend = diceRoller.rollWithDisadvantage(qstr);
                    msgToSend = "DIS_ADV ROLL";
                } else {
                    msgToSend = diceRoller.rollDice(qstr);
                }


                // msgToSend = diceRoller.rollDice(qstr);
                std::cout << "Check OK: " << msgToSend.toStdString() << std::endl;
                commManager.sendMessage("ventilator", msgToSend.toStdString());
                // commManager.sendMessage(msgToSend.toStdString());
            }
            else
            {
                msgToSend = "ERROR:  You little mothafucka, this command is not correct... bitchslap Bart";
                std::cout << msgToSend.toStdString() << std::endl;
                commManager.sendMessage("ventilator", msgToSend.toStdString());
            }
        }
        else
        {
            std::cout << "Received : " << qstr.toStdString() << std::endl;
        }
    }
}
