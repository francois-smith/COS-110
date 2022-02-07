#include "Application.h"

Application::Application()
{
    this->down = new Presentation();
    this->down->setUp(this);
}

void Application::execute(Message* message, bool sending)
{
    if (sending)
        down->execute(message, sending);
    else
        std::cout << "Computer " << computerName << " Received message: " << message->getData() << std::endl;
}

void Application::execute(std::string data, int contentLength)
{
    Message* message = new Message(data);
    message->setContentLength(contentLength);
    down->execute(message, true);
}
