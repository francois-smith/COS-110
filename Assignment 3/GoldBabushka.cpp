#include "GoldBabushka.h"

GoldBabushka::GoldBabushka(const unsigned char* id, unsigned char xorValue) : Babushka(id)
{
    this->xorValue = xorValue;
}

void GoldBabushka::encrypt(unsigned char *data, int size)
{
    unsigned char temp;
    for (int i = 0; i < size; ++i)
    {
        temp = data[i] xor xorValue;
        if(temp > MAX_VALUE_INCLUSIVE)
            throw OverflowException();

        if(temp < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();

        data[i] = temp;
    }
}

void GoldBabushka::decrypt(unsigned char *data, int size)
{
    unsigned char temp;
    for (int i = 0; i < size; ++i)
    {
        temp = data[i] xor xorValue;
        if(temp > MAX_VALUE_INCLUSIVE)
            throw OverflowException();

        if(temp < MIN_VALUE_INCLUSIVE)
            throw UnderflowException();

        data[i] = temp;
    }
}