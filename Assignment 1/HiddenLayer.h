#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include "InputLayer.h"
#include "HiddenNeuron.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class HiddenLayer
{
      private:
            int numNeurons;
            HiddenNeuron** neurons;
            string activation;
      public:
            HiddenLayer(int numNeurons, HiddenNeuron** neurons, string activation);
            ~HiddenLayer();
            HiddenNeuron** getNeurons();
            void setNeurons(HiddenNeuron** neurons);
            int getNumNeurons();
            void setNumNeurons(int numNeurons);
            void forward(HiddenLayer* prevLayer);
            void forward(InputLayer* inputLayer);
            void printLayer();
            void clearLayer();
};
#endif
