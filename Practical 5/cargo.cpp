#include "cargo.h"

cargo::cargo(char type, double weight, double cost, int powerDrain, int cargoCapacity)
: component(type, weight, cost, powerDrain)
{
    this->cargoCapacity = cargoCapacity;
}

int cargo::getCargoCapacity()
{
    return this->cargoCapacity;
}

cargo::~cargo()
{

}

double cargo::calculateEfficiency()
{
    double efficiency = 0;
    efficiency = ((getWeight()+getCargoCapacity())/getPowerDrain())/getCost();
    return efficiency;
}
