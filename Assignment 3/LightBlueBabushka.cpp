#include "LightBlueBabushka.h"

LightBlueBabushka::LightBlueBabushka(const unsigned char *id, unsigned int amount) :
BlueBabushka(id, amount){ }

void LightBlueBabushka::encrypt(unsigned char *data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        unsigned char temp = data[i] + amount;
        if(temp > MAX_VALUE_INCLUSIVE)
            throw OverflowException();

        if(temp < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();

        data[i] = temp;
    }
}

void LightBlueBabushka::decrypt(unsigned char *data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        unsigned char temp = data[i] - this->amount;
        if(temp < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();

        if(temp > MAX_VALUE_INCLUSIVE)
            throw OverflowException();

        data[i] = temp;
    }
}
