#ifndef PRAC6_MANAGER_H
#define PRAC6_MANAGER_H

#include <string>
#include "train.h"
#include <fstream>
#include <sstream>

template <class T>
class manager {
private:
    train<T>** trains;
    int numTrains;
public:
    manager(std::string input);
    ~manager();
    void summarise();
    void loadTrain(int i, T load);
};

#include "manager.cpp"

#endif //PRAC6_MANAGER_H
