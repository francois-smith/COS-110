#ifndef PRAC5_TRAIN_H
#define PRAC5_TRAIN_H

#include "component.h"
#include "cargo.h"
#include "locomotive.h"
#include "passenger.h"
#include <iostream>
#include <sstream>

class train;
std::ostream& operator<<(std::ostream& output, const train& t);

class train {
private:
    component** design;
    int trainSize;
public:
    train(int size);
    ~train();
    friend std::ostream& operator<<(std::ostream& output, const train& t);
    int addComponent(std::string comp);
    int removeComponent();
};

#endif //PRAC5_TRAIN_H
