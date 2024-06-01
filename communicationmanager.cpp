#include "communicationmanager.h"
#include <iostream>

CommunicationManager::CommunicationManager()
    : context(1), ventilator(context, ZMQ_PUSH), subscriber(context, ZMQ_SUB) {
}

void CommunicationManager::connectSockets() {
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    std::string topicStrSub = "DnD?>Dice>";
    subscriber.setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());
}

std::string CommunicationManager::receiveMessage() {
    zmq::message_t msg;
    subscriber.recv(&msg);
    return std::string(static_cast<char*>(msg.data()), msg.size());
}

void CommunicationManager::sendMessage(const std::string& message) {
    ventilator.send(message.c_str(), message.length());
}
