#ifndef ASSINGMENT3_GREENBABUSHKA_H
#define ASSINGMENT3_GREENBABUSHKA_H

#include "Babushka.h"

class GreenBabushka : public Babushka{
private:
    unsigned int displacement;
public:
    GreenBabushka(const unsigned char* id, unsigned int displacement);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_GREENBABUSHKA_H
