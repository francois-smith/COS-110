#include "OutputLayer.h"
using namespace std;

OutputLayer::OutputLayer(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = weights;
    this->outputValue = 0;
}

OutputLayer::~OutputLayer()
{
    delete[] weights;
    weights = NULL;
}

double OutputLayer::getOutputValue()
{
    return this->outputValue;
}

void OutputLayer::setOutputValue(double outputValue)
{
    this->outputValue = outputValue;
}

void OutputLayer::forward(HiddenLayer* lastHiddenLayer)
{
    double num = 0;
    for (int i = 0; i < lastHiddenLayer->getNumNeurons(); ++i)
    {
        num += lastHiddenLayer->getNeurons()[i]->getValue()*weights[i];
    }

    this->outputValue = num;
}

void OutputLayer::printLayer()
{
    cout << "o:1" << endl;
}

void OutputLayer::clearLayer()
{
    this->outputValue = 0;
}
