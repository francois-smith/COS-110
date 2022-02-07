#ifndef ASSINGMENT3_LIGHTBLUEBABUSHKA_H
#define ASSINGMENT3_LIGHTBLUEBABUSHKA_H

#include "BlueBabushka.h"

class LightBlueBabushka : public BlueBabushka{
public:
    LightBlueBabushka(const unsigned char* id, unsigned int amount);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_LIGHTBLUEBABUSHKA_H
