#include "DiceRoller.h"
#include <cstdlib>
#include <QDebug>

// ROLL REGULAR DICE
QString DiceRoller::rollDice(const QString& request) {

    msgPubList.clear();

    reqVal = request.split('>');
    diceTrows = reqVal.at(2).split('D');
    diceCheck = diceTrows.at(1);
    qDebug() << diceCheck;
    userName = reqVal.at(3);

    diceQ = diceTrows.first().toInt();


    if (diceCheck.contains("+")){

        modType = diceTrows.at(1).split('+');
        qDebug() << modType;

        modValue = modType.last().toInt();
        // qDebug() << modValue;
        diceType = modType.first().toInt();
        // qDebug() << diceType;

    }else if (diceCheck.contains('-')){

        modType = diceTrows.at(1).split('-');
        qDebug() << modType;

        modValue = modType.last().toInt() *(-1);
        // qDebug() << modValue;
        diceType = modType.first().toInt();
        // qDebug() << diceType;

    } else {
        modValue = 0;
        diceType = diceTrows.at(1).toInt();
    }


    switch (diceType) {
    case 4:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
        break;
    case 6:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
        break;
    case 8:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
        break;
    case 10:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
        break;
    case 12:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
        break;
    case 20:
        tempResult = roll(diceType, diceQ).toInt() + modValue;
        result = QString::number(tempResult);
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



QString DiceRoller::roll(int diceType, int diceQ) {

    finalDices.clear();

    for (int trow = 0; trow < diceQ; ++trow) {
        random = 1 + (rand() % diceType);
        finalDices.append(QString::number(random));
    }

    return finalDices.join(space);
}


// ROLL ADVANTAGE OR DISADVANTAGE DICE
QString DiceRoller::rollDiceAdv(const QString& request) {

    msgPubList.clear();
    advResult = "";

    reqVal = request.split('>');
    diceTrows = reqVal.at(3).split('D');
    userName = reqVal.at(4);

    diceType = diceTrows.last().toInt();
    diceQ = diceTrows.first().toInt();

    if (diceQ != 1) {
        result = "ERROR: Only a single 'advantage' rolls are allowed; the highest value counts. ex: >ADV>1D20> = 2x D20 trow";
    } else {

        switch (diceType) {
        case 4:
            result = advRoll(diceType);
            break;
        case 6:
            result = advRoll(diceType);
            break;
        case 8:
            result = advRoll(diceType);
            break;
        case 10:
            result = advRoll(diceType);
            break;
        case 12:
            result = advRoll(diceType);
            break;
        case 20:
            result = advRoll(diceType);
            break;
        default:
            result = "Asked dice does not exist, try again. Eligible dice values are 4, 6, 8, 10, 12 or 20.";
            break;
        }
    }

    msgPubList.append("DnD!>Dice");
    msgPubList.append(userName);
    msgPubList.append(result);
    userName.clear();
    advResult.clear();

    return msgPubList.join('>');
}


QString DiceRoller::advRoll(int diceType) {

    finalDices.clear();

    for (int trow = 0; trow < 2; ++trow) {
        random = 1 + (rand() % diceType);

        if (trow == 0) {
            advDice_1 = random;
        }else {
            advDice_2 = random;
        }
    }

    if (advDice_1 > advDice_2) {
        finalDices.append("Highest is");
        finalDices.append(QString::number(advDice_1));
        finalDices.append("||");
        finalDices.append("Lowest is");
        finalDices.append(QString::number(advDice_2));
    } else if (advDice_2 > advDice_1) {
        finalDices.append("Highest is");
        finalDices.append(QString::number(advDice_2));
        finalDices.append("||");
        finalDices.append("Lowest is");
        finalDices.append(QString::number(advDice_1));
    } else {
        finalDices.append("Both trows are");
        finalDices.append(QString::number(advDice_1));
    }

    return finalDices.join(space);
}
