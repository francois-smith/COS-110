#ifndef PRAC5_LOCOMOTIVE_H
#define PRAC5_LOCOMOTIVE_H

#include "component.h"

class locomotive : public component{
private:
    int powerGen;
public:
    locomotive(char type, double weight, double cost, int powerDrain, int powerGen);
    int getPowerGen();

    virtual ~locomotive();
    virtual double calculateEfficiency() override;
};

#endif //PRAC5_LOCOMOTIVE_H
