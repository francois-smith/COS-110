#ifndef ASSINGMENT3_BLUEBABUSHKA_H
#define ASSINGMENT3_BLUEBABUSHKA_H

#include "Babushka.h"

class BlueBabushka : public Babushka{
protected:
    unsigned int amount;
public:
    BlueBabushka(const unsigned char* id, unsigned int amount);
    virtual void decrypt(unsigned char *data, int size) override=0;
    virtual void encrypt(unsigned char *data, int size) override=0;
};

#endif //ASSINGMENT3_BLUEBABUSHKA_H
