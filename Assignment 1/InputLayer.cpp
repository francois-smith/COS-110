#include "InputLayer.h"
#include <iostream>
#include <string>
using namespace std;

InputLayer::InputLayer(int numInputs)
{
    this->numInputs = numInputs;
    this->inputs = new double[numInputs];
    for (int i = 0; i < numInputs; ++i)
    {
        this->inputs[i] = 0;
    }
}

InputLayer::~InputLayer()
{
    if(this->inputs != NULL)
    {
        delete[] this->inputs;
        this-> inputs = NULL;
    }
}

double* InputLayer::getInputs()
{
    return this->inputs;
}

int InputLayer::getNumInputs()
{
    return this->numInputs;
}

void InputLayer::setInputs(double* inputs)
{
    if(this->inputs == NULL)
    {
        this->inputs = inputs;
    }
    else
    {
        delete[] this->inputs;
        this->inputs = inputs;
    }
}

void InputLayer::setNumInputs(int numInputs)
{
    this->numInputs = numInputs;
}

void InputLayer::printLayer()
{
    ostringstream num;
    num << this->numInputs;
    cout << "i:" + num.str() << endl;
}

void InputLayer::clearLayer()
{
    if(this->inputs != NULL)
    {
        for(int i = 0; i < this->numInputs; i++)
        {
            this->inputs[i] = 0;
        }
    }
}
