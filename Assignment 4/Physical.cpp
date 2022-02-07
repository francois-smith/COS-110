#include "Physical.h"

Physical::Physical()
{
    this->next = NULL;
    this->down = NULL;
}

void Physical::execute(Message *message, bool sending)
{
    if(sending)
    {
        if(!next)
        {
            std::cout << "NOT CONNECTED TO A NETWORK" << std::endl;
            message->PrintMessage();
        }
        else
        {
            this->next->execute(message, false);
        }
    }
    else
    {
        std::cout << "Message at Physical layer of computer: " << this->computerName << std::endl;
        this->up->execute(message, false);
    }
}

Physical::~Physical()
{
    if(next != NULL)
    {
        Physical* ptr = next;
        while(ptr->next != this)
        {
            ptr = ptr->next;
        }

        ptr->next = next;
        next = NULL;
    }
}

void Physical::link(Layer* LinkStack)
{
    Layer* stack = LinkStack;
    while(stack->getDown() != NULL)
    {
        stack = stack->getDown();
    }

    Physical* bottom = dynamic_cast<Physical*>(stack);
    if(bottom)
    {
        if(next == NULL)
        {
            bottom->next = this;
            next = bottom;
        }
        else
        {
            bottom->next = next;
            next = bottom;
        }
    }
}

Physical *Physical::getNext()
{
    return this->next;
}

void Physical::setNext(Physical *newNext)
{
    this->next = newNext;
}

void Physical::configure(config settings)
{
    this->computerName = settings.computerName;
}
