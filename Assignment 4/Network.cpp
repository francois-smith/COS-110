#include "Network.h"

Network::Network()
{
    this->down = new Datalink();
    this->down->setUp(this);
}

void Network::execute(Message *message, bool sending)
{
    if(sending)
    {
        if(!message->setOriginIP(this->ip))
        {
            std::cout << "ERROR OCCURRED WITH ORIGIN IP" << std::endl;
            return;
        }

        if(!message->setDestinationIP(this->DestIP))
        {
            std::cout << "ERROR OCCURRED WITH DESTINATION IP" << std::endl;
            return;
        }
        down->execute(message, true);
    }
    else
    {
        if(message->getDestinationIP() == this->ip)
        {
            std::cout << "Message at Network layer" << std::endl;
            up->execute(message, false);
        }
        else if(message->getOriginIP() == this->ip)
        {
            std::cout << "Message has been returned to sender without finding the destination" << std::endl;
            message->PrintMessage();
        }
        else
        {
            std::cout << "Message at Network layer" << std::endl;
            down->execute(message, true);
        }
    }
}

void Network::configure(config settings)
{
    this->ip = settings.ip;
    this->DestIP = settings.DestIP;
    Layer::configure(settings);
}
