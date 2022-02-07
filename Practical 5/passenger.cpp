#include "passenger.h"

passenger::passenger(char type, double weight, double cost, int powerDrain, int passengerCapacity)
: component(type, weight, cost, powerDrain)
{
    this->passengerCapacity = passengerCapacity;
}

int passenger::getPassengerCapacity()
{
    return this->passengerCapacity;
}

passenger::~passenger()
{

}

double passenger::calculateEfficiency()
{
    double efficiency;
    efficiency = ((getWeight()*passengerCapacity)/getPowerDrain())/getCost();
    return efficiency;
}
