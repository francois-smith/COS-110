#ifndef PRAC_8_TRAIN_H
#define PRAC_8_TRAIN_H

#include <sstream>
#include "trainCar.h"

class train {
private:
    trainCar* head;
    int size;
public:
    train(std::string config);
    ~train();
    int calcTotalCost();
    void addCar(int newCost);
};

#endif //PRAC_8_TRAIN_H
