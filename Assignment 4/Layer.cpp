#include "Layer.h"

Layer::Layer()
{
    this->up = NULL;
    this->down = NULL;
}

Layer::~Layer()
{
    delete this->down;
    this->down = NULL;
}

void Layer::setUp(Layer* up)
{
    this->up = up;
}

void Layer::configure(config settings)
{
    this->computerName = settings.computerName;
    this->down->configure(settings);
}

void Layer::link(Layer* linkStack)
{
    this->down->link(linkStack);
}

Layer *Layer::getDown()
{
    return this->down;
}
