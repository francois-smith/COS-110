#ifndef ASSINGMENT3_OVERFLOWEXCEPTION_H
#define ASSINGMENT3_OVERFLOWEXCEPTION_H
#define override

#include "BabushkaException.h"

class OverflowException : public BabushkaException{
public:
    void printMessage() override;
};

#endif //ASSINGMENT3_OVERFLOWEXCEPTION_H
