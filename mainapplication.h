#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "CommunicationManager.h"
#include "DiceRoller.h"

class MainApplication
{
public:
    void run();
    QString msgToSend;

private:
    CommunicationManager commManager;
    DiceRoller diceRoller;
};

#endif // MAINAPPLICATION_H
