#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>

class NeuralNetwork
{
private:
    InputLayer* inputLayer;
    int numHiddenLayers;
    HiddenLayer** hiddenLayers;
    OutputLayer* outputLayer;
public:
    NeuralNetwork(string filePath);
    ~NeuralNetwork();
    double forward(double* input);
    void printNetwork();
    void clearNetwork();
};
#endif
