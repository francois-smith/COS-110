#include "RedBabushka.h"

RedBabushka::RedBabushka(const unsigned char* id, unsigned int rotationAmount) : Babushka(id)
{
    this->rotationAmount = rotationAmount;
}

void RedBabushka::decrypt(unsigned char *data, int size)
{
    if(rotationAmount >= size)
    {
        throw RotateException();
    }
    else
    {
        unsigned char tempArr[rotationAmount];
        for (int i = 0; i < rotationAmount; ++i)
        {
            tempArr[i] = data[i];
        }

        unsigned char temp[size];
        for (int i = 0; i < size-rotationAmount; ++i)
        {
            temp[i] = data[i+rotationAmount];
        }

        int index;
        for (int i = size-rotationAmount; i < size; ++i)
        {
            temp[i] = tempArr[index];
            index++;
        }

        for (int i = 0; i < size; ++i)
        {
            data[i] = temp[i];
        }
    }
}

void RedBabushka::encrypt(unsigned char* data, int size)
{
    if(rotationAmount >= size)
    {
        throw RotateException();
    }
    else
    {
        unsigned char tempArr[rotationAmount];
        for (int i = 0; i < rotationAmount; ++i)
        {
            tempArr[i] = data[(size+i) - rotationAmount];
        }

        unsigned char temp[size];
        for (int i = rotationAmount; i < size; ++i)
        {
            temp[i] = data[i-rotationAmount];
        }

        for (int i = 0; i < rotationAmount; ++i)
        {
            temp[i] = tempArr[i];
        }

        for (int i = 0; i < size; ++i)
        {
            data[i] = temp[i];
        }
    }
}
