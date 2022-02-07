#ifndef ASSINGMENT3_YELLOWBABUSHKA_H
#define ASSINGMENT3_YELLOWBABUSHKA_H

#include "Babushka.h"

class YellowBabushka : public Babushka{
public:
    YellowBabushka(const unsigned char* id);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_YELLOWBABUSHKA_H
