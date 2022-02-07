#include "HiddenLayer.h"
using namespace std;

HiddenLayer::HiddenLayer(int numNeurons, HiddenNeuron** neurons, string activation)
{
    this->numNeurons = numNeurons;
    this->neurons = neurons;
    this->activation = activation;
}

HiddenLayer::~HiddenLayer()
{
    for (int i = 0; i < this->numNeurons; ++i)
    {
        delete this->neurons[i];
        this->neurons[i] = NULL;
    }
    delete[] this->neurons;
    this->neurons = NULL;
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return this->neurons;
}

void HiddenLayer::setNeurons(HiddenNeuron** neurons)
{
    if(this->neurons == NULL)
    {
        this->neurons = neurons;
    }
    else
    {
        for (int i = 0; i < this->numNeurons; ++i)
        {
            delete this->neurons[i];
        }
        delete[] this->neurons;
        this->neurons = neurons;
    }
}

int HiddenLayer::getNumNeurons()
{
  return this->numNeurons;
}

void HiddenLayer::setNumNeurons(int numNeurons)
{
    this->numNeurons = numNeurons;
}

void HiddenLayer::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < this->numNeurons; ++i)
    {
        this->neurons[i]->forward(prevLayer);

        if(this->activation == "relu")
        {
            this->neurons[i]->activateReLU();
        }

        if(this->activation == "sigmoid")
        {
            this->neurons[i]->activateSigmoid();
        }
    }
}

void HiddenLayer::forward(InputLayer* inputLayer)
{
    for (int i = 0; i < this->numNeurons; ++i)
    {
        this->neurons[i]->forward(inputLayer);

        if(this->activation == "relu")
        {
            this->neurons[i]->activateReLU();
        }

        if(this->activation == "sigmoid")
        {
            this->neurons[i]->activateSigmoid();
        }
    }
}

void HiddenLayer::printLayer()
{
    ostringstream num;
    num << this->numNeurons;
    cout << "h:" + num.str() << ":" << this->activation << endl;
}

void HiddenLayer::clearLayer()
{
    if(this->neurons != NULL)
    {
        for(int i = 0; i < this->numNeurons; i++)
        {
            this->neurons[i]->setValue(0);
        }
    }
}
