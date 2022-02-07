#include "trolley.h"

trolley::trolley()
{

}

trolley::~trolley()
{

}

trolley::trolley(std::string name)
{
    this->name = name;
    this->speed = 0;
}

int trolley::getSpeed()
{
    return this->speed;
}

void trolley::increaseSpeed(int s)
{
    this->speed += s;
}
