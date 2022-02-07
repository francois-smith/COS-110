#ifndef ASSINGMENT3_CONTROLLER_H
#define ASSINGMENT3_CONTROLLER_H

#include "ControllerException.h"
#include "BabushkaException.h"
#include "Babushka.h"
#include "GoldBabushka.h"
#include "YellowBabushka.h"
#include "GreenBabushka.h"
#include "RedBabushka.h"
#include "LightBlueBabushka.h"
#include "DarkBlueBabushka.h"
#include "ReturnStruct.h"

#include <iostream>
#include <fstream>
#include <sstream>

class Controller {
private:
    Babushka** babushkaArr;
    int numBabushkas;
    ReturnStruct expandArray(unsigned char* array, int currentSize, const unsigned char* id, int idSize);
    ReturnStruct reduceArray(unsigned char* array, int currentSize, const unsigned char* expectedId, int idSize);
public:
    Controller(std::string filePath);
    ~Controller();
    ReturnStruct decrypt(const unsigned char* array, int size);
    ReturnStruct encrypt(const unsigned char* array, int size);
    void printArray(unsigned char* array, int size);
};

#endif //ASSINGMENT3_CONTROLLER_H
