#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

int main(int argc, char *argv[])
{
    try
    {
        zmq::context_t context(1);

        zmq::socket_t ventilator(context, ZMQ_PUSH);
        ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

        //Incoming messages come in here
        zmq::socket_t subscriber(context, ZMQ_SUB);
        subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
        subscriber.setsockopt(ZMQ_SUBSCRIBE, "DnD?>Dice>", 10);

        zmq::message_t msg; // Removed the pointer declaration

        // Receive the message directly into msg
        subscriber.recv(&msg);

        std::string received_msg = std::string(static_cast<char*>(msg.data()), msg.size());
        std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

        QString qstr = QString::fromStdString(received_msg);

        if (qstr == "DnD?>Dice>") {
            ventilator.send("DnD!>Dice>DND_20>", 18);
        }
    }
    catch (zmq::error_t &ex)
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

    return 0;
}
