#include "dispatch.h"

dispatch::dispatch(std::string o)
{
    this->order = o;
    this->next = NULL;
}

dispatch::~dispatch()
{
    std::cout << this->order << " processed" << std::endl;
}

std::string dispatch::getOrder()
{
    return this->order;
}
