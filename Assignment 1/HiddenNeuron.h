#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H

#include <cmath>
#include "InputLayer.h"
class HiddenLayer;

class HiddenNeuron
{
    private:
        double value;
        int numWeights;
        double* weights;
    public:
        HiddenNeuron(int numWeights, double* weights);
        ~HiddenNeuron();
        double getValue();
        void setValue(double value);
        void forward(HiddenLayer* prevLayer);
        void forward(InputLayer* inputLayer);
        void activateReLU();
        void activateSigmoid();
};
#endif
