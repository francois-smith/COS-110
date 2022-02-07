#include "Transport.h"

Transport::Transport()
{
    this->down = new Network();
    this->down->setUp(this);
}

void Transport::execute(Message* message, bool sending)
{
    if (sending)
    {
        bool oPort = message->setOriginPort(this->port);
        if(!oPort)
        {
            std::cout << "ERROR OCCURRED WITH ORIGIN PORT" << std::endl;
            return;
        }

        bool dPort = message->setDestinationPort(this->DestPort);
        if(!dPort)
        {
            std::cout << "ERROR OCCURRED WITH DESTINATION PORT" << std::endl;
            return;
        }

        down->execute(message);
    }
    else
    {
        if(message->getDestinationPort() != this->port)
        {
            std::cout << "Message sent to wrong port" << std::endl;
            message->PrintMessage();
        }
        else if (message->getContentLength() != message->getData().length())
        {
            std::cout << "Content Length error" << std::endl;
            message->PrintMessage();
        }
        else
        {
            std::cout << "Message at Transport layer" << std::endl;
            this->up->execute(message, false);
        }
    }
}

void Transport::configure(config settings)
{
    this->port = settings.port;
    this->DestPort = settings.DestPort;
    Layer::configure(settings);
}
