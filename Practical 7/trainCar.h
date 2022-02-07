#ifndef PRAC_8_TRAINCAR_H
#define PRAC_8_TRAINCAR_H

#include <cstdlib>
#include <string>
#include <iostream>

class trainCar {
private:
    int cost;
public:
    trainCar* next;
    trainCar(int c);
    ~trainCar();
    int getCost();
};

#endif //PRAC_8_TRAINCAR_H
