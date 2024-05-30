#include "heartbeat.h"

heartbeat::heartbeat() {


    // Game tick timer
    moveTimer = new QTimer();
    moveTimer->start(10000);

    // check player collision
 //   heartbeat::heartbeat(moveTimer,SIGNAL(timeout(),this,SLOT(heartbeat())));

}

