#include "Datalink.h"

Datalink::Datalink()
{
    this->down = new Physical();
    this->down->setUp(this);
}

void Datalink::execute(Message *message, bool sending)
{
    if(sending)
    {
        down->execute(message, true);
    }
    else
    {
        std::cout << "Message at Datalink layer" << std::endl;
        up->execute(message, false);
    }
}
