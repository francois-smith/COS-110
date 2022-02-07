#ifndef ASSINGMENT3_DISPLACEMENTEXCEPTION_H
#define ASSINGMENT3_DISPLACEMENTEXCEPTION_H
#define override

#include "BabushkaException.h"

class DisplacementException : public BabushkaException{
public:
    void printMessage() override;
};

#endif //ASSINGMENT3_DISPLACEMENTEXCEPTION_H
