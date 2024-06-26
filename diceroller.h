#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <QString>
#include <QStringList>

class DiceRoller
{
public:
    QString rollDice(const QString& request);
    QString rollDiceAdv(const QString& request);
    QString userName, diceCheck;
    QStringList diceTrows, reqVal, modType;
    int diceQ, diceType, modValue, tempResult;


private:
    QString roll(int diceType, int diceQ);
    QString advRoll(int diceType);
    QString result;
    QString advResult;
    QStringList msgPubList;
    QStringList finalDices;
    QString space = " ";
    int random, advDice_1, advDice_2;
};

#endif // DICEROLLER_H
