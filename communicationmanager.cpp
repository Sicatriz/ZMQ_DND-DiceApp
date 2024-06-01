#include "communicationmanager.h"
#include <iostream>

CommunicationManager::CommunicationManager()
    : context(1) {
}

void CommunicationManager::connectSocket(const std::string& socketName, const std::string& address, int socketType) {
    // ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");
    // subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    // std::string topicStrSub = "DnD?>Dice>";
    // subscriber.setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());

    zmq::socket_t socket(context, socketType);
    socket.connect(address);
    sockets[socketName] = std::move(socket);
}

std::string CommunicationManager::receiveMessage(const std::string& socketName) {
    // zmq::message_t msg;
    // subscriber.recv(&msg);
    // return std::string(static_cast<char*>(msg.data()), msg.size());
    zmq::message_t msg;
    sockets[socketName].recv(&msg);
    return std::string(static_cast<char*>(msg.data()), msg.size());
}

void CommunicationManager::sendMessage(const std::string& socketName, const std::string& message) {
    // ventilator.send(message.c_str(), message.length());
    sockets[socketName].send(message.c_str(), message.length());
}
