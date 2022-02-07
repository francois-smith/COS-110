#include "trainCar.h"

trainCar::trainCar(int c)
{
    this->next = NULL;
    this->cost = c;
}

trainCar::~trainCar()
{
    std::cout << cost << " removed" << std::endl;
}

int trainCar::getCost()
{
    return this->cost;
}
