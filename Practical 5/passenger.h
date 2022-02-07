#ifndef PRAC5_PASSENGER_H
#define PRAC5_PASSENGER_H

#include "component.h"

class passenger : public component{
private:
    int passengerCapacity;
public:
    passenger(char type, double weight, double cost, int powerDrain, int passengerCapacity);
    int getPassengerCapacity();
    virtual ~passenger();
    virtual double calculateEfficiency() override;
};

#endif //PRAC5_PASSENGER_H
