#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include <zmq.hpp>
#include <string>

class CommunicationManager
{
public:
    CommunicationManager();
    void connectSockets();
    std::string receiveMessage();
    void sendMessage(const std::string& message);
private:
    zmq::context_t context;
    zmq::socket_t ventilator;
    zmq::socket_t subscriber;

};

#endif // COMMUNICATIONMANAGER_H
