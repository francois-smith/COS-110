#ifndef ASSINGMENT3_BABUSHKA_H
#define ASSINGMENT3_BABUSHKA_H
#define override

#include "OverflowException.h"
#include "RotateException.h"
#include "UnderflowException.h"
#include "DisplacementException.h"

class Babushka {
protected:
    const unsigned char* id;
    static const int ID_LENGTH = 10;
    static const unsigned char MAX_VALUE_INCLUSIVE = 126;
    static const unsigned char MIN_VALUE_INCLUSIVE = 32;
public:
    Babushka(const unsigned char* id);
    virtual ~Babushka();
    const int getIdLength();
    const unsigned char* getId();
    virtual void decrypt(unsigned char* data, int size)=0;
    virtual void encrypt(unsigned char* data, int size)=0;
};

#endif //ASSINGMENT3_BABUSHKA_H
