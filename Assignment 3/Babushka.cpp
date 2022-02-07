#include "Babushka.h"

Babushka::Babushka(const unsigned char* id)
{
    this->id = id;
}

Babushka::~Babushka()
{
    if(this->id != NULL)
    {
        delete[] id;
        id = NULL;
    }
}

const int Babushka::getIdLength()
{
    return ID_LENGTH;
}

const unsigned char* Babushka::getId()
{
    return id;
}
