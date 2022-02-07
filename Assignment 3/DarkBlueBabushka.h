#ifndef ASSINGMENT3_DARKBLUEBABUSHKA_H
#define ASSINGMENT3_DARKBLUEBABUSHKA_H

#include "BlueBabushka.h"

class DarkBlueBabushka : public BlueBabushka{
public:
    DarkBlueBabushka(const unsigned char* id, unsigned int amount);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_DARKBLUEBABUSHKA_H
