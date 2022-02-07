#ifndef ASSINGMENT3_GOLDBABUSHKA_H
#define ASSINGMENT3_GOLDBABUSHKA_H

#include "Babushka.h"

class GoldBabushka : public Babushka{
private:
    unsigned char xorValue;
public:
    GoldBabushka(const unsigned char* id, unsigned char xorValue);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_GOLDBABUSHKA_H
