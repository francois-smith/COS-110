#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include <iostream>
#include "HiddenLayer.h"

class OutputLayer
{
private:
    double outputValue;
    int numWeights;
    double* weights;
public:
    OutputLayer(int numWeights, double* weights);
    ~OutputLayer();
    double getOutputValue();
    void setOutputValue(double outputValue);
    void forward(HiddenLayer* lastHiddenLayer);
    void printLayer();
    void clearLayer();
};
#endif
