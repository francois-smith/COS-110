#include "HiddenNeuron.h"
#include "HiddenLayer.h"
using namespace std;

HiddenNeuron::HiddenNeuron(int numWeights, double* weights)
{
    this->value = 0;
    this->numWeights = numWeights;
    this->weights = weights;
}

HiddenNeuron::~HiddenNeuron()
{
    this->value = 0;
    this->numWeights = 0;
    delete[] this->weights;
    this->weights = NULL;
}

double HiddenNeuron::getValue()
{
  return this->value;
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;
}



void HiddenNeuron::forward(InputLayer* inputLayer)
{
    double num = 0;
    for (int i = 0; i < inputLayer->getNumInputs(); ++i)
    {
        num += inputLayer->getInputs()[i]*this->weights[i];
    }

    this->value = num;
}

void HiddenNeuron::activateReLU()
{
    this->value = fmax(0, this->value);
}

void HiddenNeuron::activateSigmoid()
{
    this->value = 1/(1+exp(-(this->value)));
}

void HiddenNeuron::forward(HiddenLayer *prevLayer)
{
    this->value = 0;
    for (int i = 0; i < prevLayer->getNumNeurons(); ++i)
    {
        this->value += prevLayer->getNeurons()[i]->getValue()*this->weights[i];
    }
}
