#include "locomotive.h"

locomotive::locomotive(char type, double weight, double cost, int powerDrain, int powerGen)
: component(type, weight, cost, powerDrain)
{
    this->powerGen = powerGen;
}

int locomotive::getPowerGen()
{
    return this->powerGen;
}

locomotive::~locomotive()
{

}

double locomotive::calculateEfficiency()
{
    double efficiency;
    efficiency = (getPowerGen()/getPowerDrain())/getCost();
    return efficiency;
}
