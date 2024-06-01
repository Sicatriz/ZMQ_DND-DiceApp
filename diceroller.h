#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <QString>
#include <QStringList>

class DiceRoller
{
public:
    QString rollDice(const QString& request);
    QString userName;
    QStringList diceTrows, reqVal;
    int diceQ, diceType;


private:
    QString roll(int diceType, int diceQ);
    QString result;
    QStringList msgPubList;
    QStringList finalDices;
    QString space = " ";
};

#endif // DICEROLLER_H
