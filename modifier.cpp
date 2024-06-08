#include "modifier.h"
#include <cstdlib>

QString Modifier::rollModifier(const QString& request) {

    msgPubList.clear();

    reqVal = request.split('>');
    diceTrows = reqVal.at(2).split('D');
    userName = reqVal.at(3);

  //  modType = diceTrows.at(1);

    if (diceTrows.contains("+"))

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
    userName.clear();
    result.clear();

    return msgPubList.join('>');

}
