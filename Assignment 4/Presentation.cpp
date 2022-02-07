#include "Presentation.h"

Presentation::Presentation()
{
    this->down = new Transport();
    this->down->setUp(this);
}

void Presentation::execute(Message *message, bool sending)
{
    if (sending)
    {
        message->setEncoding(this->encoding);
        down->execute(message, sending);
    }
    else
    {
        if(this->encoding == message->getEncoding())
        {
            std::cout << "Message at Presentation layer on computer: " << this->computerName << std::endl;
            up->execute(message, false);
        }
        else
        {
            std::cout << "Encoding type mismatch on computer: " << this->computerName << " Expected: " << this->encoding << std::endl;
            message->PrintMessage();
        }
    }
}

void Presentation::configure(config settings)
{
    this->encoding = settings.encoding;
    Layer::configure(settings);
}
