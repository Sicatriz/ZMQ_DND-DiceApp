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
    // Providing a seed value
    srand((unsigned) time(NULL));

    try
    {
        zmq::context_t context(1);

        zmq::socket_t ventilator(context, ZMQ_PUSH);
        ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

        //Incoming messages come in here
        zmq::socket_t subscriber(context, ZMQ_SUB);
        subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

        std::string topicStrSub = "DnD?>Dice>";
        subscriber.setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());

        while(1){
            zmq::message_t msg; // Removed the pointer declaration

            // Receive the message directly into msg
            subscriber.recv(&msg);

            std::string received_msg = std::string(static_cast<char*>(msg.data()), msg.size());
            std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

            QString qstr = QString::fromStdString(received_msg);


            QString topicStrPub = "DnD!>Dice";

            if (qstr.startsWith( "DnD?>Dice>" )) {

                // Split # of dice, dice type and player name
                QStringList reqVal = qstr.split('>');
                QStringList diceTrows = reqVal.at(2).split('D');
                QString userName = reqVal.at(3);
                //qDebug() << userName;

                // Ints for quantity and type of dice
                int diceType = diceTrows.last().toInt();
                int diceQ = diceTrows.first().toInt();
                QStringList finalDices;
                QString space = " ";
                QString sep = ">";
                QString dicesToSend;
                QStringList msgPubList;
                QString msgToSend;

                // trow the dices by dicetype
                switch (diceType) {
                case 4:
                    std::cout << "Asked dice is a D4" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;

                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                case 6:
                    std::cout << "Asked dice is a D6" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                case 8:
                    std::cout << "Asked dice is a D8" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                case 10:
                    std::cout << "Asked dice is a D10" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                case 12:
                    std::cout << "Asked dice is a D12" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                case 20:
                    std::cout << "Asked dice is a D20" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);

                        QString randomS = QString::number(random);
                        finalDices.append(randomS);
                    }
                    dicesToSend = finalDices.join(space);
                    break;
                default:
                    std::cout << "Asked dice does not excist, try again." << std::endl;
                    std::cout << "Eligible dice values are 2, 4, 6, 8, 10, 12 or 20." << std::endl;
                    dicesToSend = "Asked dice does not excist, try again. Eligible dice values are 2, 4, 6, 8, 10, 12 or 20.";
                    break;
                }

                //Combine message to send

                msgPubList.append(topicStrPub);
                msgPubList.append(userName);
                msgPubList.append(dicesToSend);
                msgToSend = msgPubList.join(sep);

                // Get a random number
                std::cout << "Check OK" << std::endl;
                std::cout << msgToSend.toStdString() << std::endl;
                ventilator.send(msgToSend.toStdString().c_str(), msgToSend.length());
            }
            else
            {
                std::cout << "Received : " << qstr.toStdString() << std::endl;
            }
        }
    }
    catch (zmq::error_t &ex)
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

    return 0;
}
