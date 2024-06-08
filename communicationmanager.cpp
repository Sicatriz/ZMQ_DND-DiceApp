#include "communicationmanager.h"


CommunicationManager::CommunicationManager()
    : context(1) {
}

void CommunicationManager::connectSocket(const std::string& socketName, const std::string& address, int socketType) {


    zmq::socket_t socket(context, socketType);
    socket.connect(address);
    sockets[socketName] = std::move(socket);
}

std::string CommunicationManager::receiveMessage(const std::string& socketName) {

    zmq::message_t msg;
    sockets[socketName].recv(&msg);
    return std::string(static_cast<char*>(msg.data()), msg.size());
}

void CommunicationManager::sendMessage(const std::string& socketName, const std::string& message) {

   // sockets[socketName].send(message.c_str(), message.length());

    zmq::message_t msg(message.size());
    memcpy(msg.data(), message.data(), message.size());
    sockets[socketName].send(msg, zmq::send_flags::none);
}
