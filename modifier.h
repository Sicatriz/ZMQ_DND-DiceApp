#ifndef MODIFIER_H
#define MODIFIER_H

#include <QString>
#include <QStringList>
#include "diceroller.h"

class Modifier
{
public:
    QString rollModifier(const QString& request);
    QString userName;
    QStringList diceTrows, reqVal, modType;
    int diceQ, diceType;

private:
    QString roll(int diceType, int diceQ);
    QString result;
    QStringList msgPubList;
    QStringList finalDices;
    QString space = " ";
};

#endif // MODIFIER_H
