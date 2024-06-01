#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include <zmq.hpp>
#include <string>
#include <map>

class CommunicationManager
{
public:
    CommunicationManager();
    void connectSocket(const std::string& socketName, const std::string& address, int socketType);
    std::string receiveMessage(const std::string& socketName);
    void sendMessage(const std::string& socketName, const std::string& message);
    std::map<std::string, zmq::socket_t> sockets;

private:
    zmq::context_t context;

    //  zmq::socket_t ventilator;
    //  zmq::socket_t subscriber;

};

#endif // COMMUNICATIONMANAGER_H
