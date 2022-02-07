#ifndef ASSINGMENT3_UNDERFLOWEXCEPTION_H
#define ASSINGMENT3_UNDERFLOWEXCEPTION_H
#define override

#include "BabushkaException.h"

class UnderflowException : public BabushkaException{
public:
    void printMessage() override;
};

#endif //ASSINGMENT3_UNDERFLOWEXCEPTION_H
