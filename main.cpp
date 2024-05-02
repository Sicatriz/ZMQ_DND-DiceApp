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



            std::string topicStrPub = "DnD!>Dice>random";

            if (qstr.startsWith( "DnD?>Dice>" )) {

                // Split # dice and dice type
                QStringList reqVal = qstr.split('>');
               // qDebug() << reqVal << reqVal.at(2).split('d');
                QStringList diceTrows = reqVal.at(2).split('D');
               // qDebug() << diceTrows;

                if(diceTrows.at(1).contains("20")){
                   // QString diceType("D20");
                  //  ventilator.send(diceType.toStdString().c_str(), diceType.length());
                }


                // Ints for quantity and type of dice
                int diceType = diceTrows.last().toInt();
                int diceQ = diceTrows.first().toInt();
             //   qDebug() << diceType;
             //   qDebug() << diceQ;
                QStringList finalDices;
                QString space = " ";
                QString dicesToSend;

                // trow the dices by dicetype
                switch (diceType) {
                case 4:
                    std::cout << "Asked dice is a D4" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;

                    // loop the # of asked trows
                    for (int trow = 0; trow < diceQ; ++trow) {
                        int random = 1 + (rand() % diceType);
                        QString trowToSend("dice # %1 : ");
                        trowToSend = trowToSend.arg(trow+1);
                        ventilator.send(trowToSend.toStdString().c_str(), trowToSend.length());

                        QString dataToSend("the value is %1.");
                        dataToSend = dataToSend.arg(random);
                        ventilator.send(dataToSend.toStdString().c_str(), dataToSend.length());
                        QString randomS = QString::number(random);


                        finalDices.append(randomS);
                        qDebug() << finalDices;

                     //   QString totalDice;
                     //   QString tempDice;
                     //   tempDice = randomS;
                     //   totalDice = totalDice + space + tempDice;
                     //   std::cout << "Totals are " << totalDice.toStdString() << std::endl;

                    }
                    dicesToSend = finalDices.join(",");
                    ventilator.send(dicesToSend.toStdString().c_str(), dicesToSend.length());



                    break;
                case 6:
                    std::cout << "Asked dice is a D6" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    break;
                case 8:
                    std::cout << "Asked dice is a D8" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    break;
                case 10:
                    std::cout << "Asked dice is a D10" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    break;
                case 12:
                    std::cout << "Asked dice is a D12" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    break;
                case 20:
                    std::cout << "Asked dice is a D20" << std::endl;
                    std::cout << "# of trows is " << diceQ << std::endl;
                    break;
                default:
                    std::cout << "Asked dice does not excist, try again." << std::endl;
                    std::cout << "Eligible dice values are 2, 4, 6, 8, 10, 12 or 20." << std::endl;
                    break;
                }


                // Get a random number
            //    int random = 1 + (rand() % diceType);
                std::cout << "Check OK" << std::endl;
                ventilator.send(topicStrPub.c_str(), topicStrPub.length());
                QString dataToSend("value is %1.");
              //  dataToSend = dataToSend.arg(random);
              //  ventilator.send(dataToSend.toStdString().c_str(), dataToSend.length());
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
