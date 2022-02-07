#include "YellowBabushka.h"

YellowBabushka::YellowBabushka(const unsigned char *id) : Babushka(id){ }

void YellowBabushka::decrypt(unsigned char *data, int size)
{
    int index = 0;
    unsigned char tempArr[size];
    for(int i=size-1; i > -1; i--)
    {
        tempArr[index] = data[i];
        index++;
    }

    for (int i = 0; i < size; ++i)
    {
        data[i] = tempArr[i];
    }
}

void YellowBabushka::encrypt(unsigned char *data, int size)
{
    int index = 0;
    unsigned char tempArr[size];
    for(int i=size-1; i > -1; i--)
    {
        tempArr[index] = data[i];
        index++;
    }

    for (int i = 0; i < size; ++i)
    {
        data[i] = tempArr[i];
    }
}
