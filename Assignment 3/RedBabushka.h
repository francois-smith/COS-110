#ifndef ASSINGMENT3_REDBABUSHKA_H
#define ASSINGMENT3_REDBABUSHKA_H

#include "Babushka.h"

class RedBabushka : public Babushka{
private:
    unsigned int rotationAmount;
public:
    RedBabushka(const unsigned char* id, unsigned int rotationAmount);
    void decrypt(unsigned char *data, int size) override;
    void encrypt(unsigned char *data, int size) override;
};

#endif //ASSINGMENT3_REDBABUSHKA_H
