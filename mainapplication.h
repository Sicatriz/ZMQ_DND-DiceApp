#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QTimer>
#include "CommunicationManager.h"
#include "DiceRoller.h"

class MainApplication : public QObject
{
public:
    explicit MainApplication(QObject *parent = nullptr);
    void run();
    QString msgToSend;

private slots:
    void sendHeartbeat();

private:
    CommunicationManager commManager;
    DiceRoller diceRoller;
    QTimer *heartbeatTimer;


};

#endif // MAINAPPLICATION_H
