#ifndef PRAC5_CARGO_H
#define PRAC5_CARGO_H

#include "component.h"
#include <iostream>

class cargo : public component{
private:
    int cargoCapacity;
public:
    cargo(char type, double weight, double cost, int powerDrain, int cargoCapacity);
    int getCargoCapacity();
    virtual ~cargo();
    virtual double calculateEfficiency() override;
};

#endif //PRAC5_CARGO_H
