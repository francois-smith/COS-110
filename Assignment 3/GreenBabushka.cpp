#include "GreenBabushka.h"

GreenBabushka::GreenBabushka(const unsigned char* id, unsigned int displacement) : Babushka(id)
{
    this->displacement = displacement;
}

void GreenBabushka::decrypt(unsigned char *data, int size)
{
    if(displacement+1 >= size)
    {
        throw DisplacementException();
    }
    else
    {
        unsigned char temp;
        for (int i = 0; i < size - displacement; i = i+displacement+2)
        {
            temp = data[i];
            data[i] = data[i+displacement+1];
            data[i+displacement+1] = temp;
        }
    }
}

void GreenBabushka::encrypt(unsigned char *data, int size)
{
    if(displacement+1 >= size)
    {
        throw DisplacementException();
    }
    else {
        unsigned char temp;
        for (int i = 0; i < size - displacement; i = i + displacement + 2)
        {
            temp = data[i];
            data[i] = data[i + displacement + 1];
            data[i + displacement + 1] = temp;
        }
    }
}
