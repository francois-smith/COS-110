#ifndef ASSINGMENT3_ROTATEEXCEPTION_H
#define ASSINGMENT3_ROTATEEXCEPTION_H
#define override

#include "BabushkaException.h"

class RotateException : public BabushkaException{
public:
    void printMessage() override;
};

#endif //ASSINGMENT3_ROTATEEXCEPTION_H
