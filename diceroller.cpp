#include "DiceRoller.h"
#include <cstdlib>
//#include <iostream>

QString DiceRoller::rollDice(const QString& request) {

    msgPubList.clear();
    result = "";

    reqVal = request.split('>');
    diceTrows = reqVal.at(2).split('D');
    userName = reqVal.at(3);

    diceType = diceTrows.last().toInt();
    diceQ = diceTrows.first().toInt();

    switch (diceType) {
    case 4:
        result = roll(diceType, diceQ);
        break;
    case 6:
        result = roll(diceType, diceQ);
        break;
    case 8:
        result = roll(diceType, diceQ);
        break;
    case 10:
        result = roll(diceType, diceQ);
        break;
    case 12:
        result = roll(diceType, diceQ);
        break;
    case 20:
        result = roll(diceType, diceQ);
        break;
    default:
        result = "Asked dice does not exist, try again. Eligible dice values are 4, 6, 8, 10, 12 or 20.";
        break;
    }

    msgPubList.append("DnD!>Dice");
    msgPubList.append(userName);
    msgPubList.append(result);

    // msgPubList << "DnD!>Dice" << userName << result;
    return msgPubList.join('>');
}



QString DiceRoller::roll(int diceType, int diceQ) {

    finalDices.clear();

    for (int trow = 0; trow < diceQ; ++trow) {
        int random = 1 + (rand() % diceType);
        finalDices.append(QString::number(random));
    }

    return finalDices.join(space);
}
