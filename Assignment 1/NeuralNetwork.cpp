#include "NeuralNetwork.h"
using namespace std;

NeuralNetwork::NeuralNetwork(string filePath)
{
    string line, temp, tempActivation;
    int inputLayerSize, numNeuronsInLayer = 0, numNeuronsInPrevLayer = 0, OutputLayerNum = 0;
    double* hiddenLayerWeights;

    this->numHiddenLayers = 0;

    ifstream inFile(filePath.c_str());
    if(inFile)
    {
        //Get Input Layer Size
        getline(inFile, line);
        temp = line.substr(line.find(':') + 1);
        istringstream inputSize(temp);
        inputSize >> inputLayerSize;
        this->inputLayer = new InputLayer(inputLayerSize);

        //Get Number of hidden Layers
        getline(inFile, line);
        temp = line.substr(line.find(':') + 1);
        istringstream hiddenSize(temp);
        hiddenSize >> this->numHiddenLayers;
        this->hiddenLayers = new HiddenLayer*[numHiddenLayers];

        //Get activation and number of neurons for first hidden layer
        getline(inFile, line);
        temp = line.substr(line.find(':') + 1);
        tempActivation = temp.substr(temp.find(':') + 1);
        size_t index = temp.find(':');
        stringstream activationNum(temp.substr(0, index));
        activationNum >> numNeuronsInLayer;

        HiddenNeuron** initialHiddenNeurons = new HiddenNeuron*[numNeuronsInLayer];
        for (int i = 0; i < numNeuronsInLayer; ++i)
        {
            double* inputWeight = new double[inputLayerSize];
            getline(inFile, line);
            for (int j = 0; j < inputLayerSize - 1; ++j)
            {
                index = line.find(' ');
                temp = line.substr(0, index);
                stringstream ss(temp);
                ss >> inputWeight[j];
                line.erase(0, index+1);
            }
            stringstream ss(line);
            ss >> inputWeight[inputLayerSize-1];
            initialHiddenNeurons[i] = new HiddenNeuron(inputLayerSize, inputWeight);
        }

        this->hiddenLayers[0] = new HiddenLayer(numNeuronsInLayer, initialHiddenNeurons, tempActivation);
        numNeuronsInPrevLayer = numNeuronsInLayer;

        for (int i = 1; i < numHiddenLayers; ++i)
        {
            //Get activation and number of neurons
            getline(inFile, line);
            temp = line.substr(line.find(':') + 1);
            tempActivation = temp.substr(temp.find(':') + 1);
            index = temp.find(':');
            stringstream hiddenLayerNum(temp.substr(0, index));
            hiddenLayerNum >> numNeuronsInLayer;

            HiddenNeuron** hiddenNeurons = new HiddenNeuron*[numNeuronsInLayer];
            for (int j = 0; j < numNeuronsInLayer; ++j)
            {
                double* hiddenWeights = new double[numNeuronsInPrevLayer];
                getline(inFile, line);
                for (int k = 0; k < numNeuronsInPrevLayer-1; ++k)
                {
                    index = line.find(' ');
                    temp = line.substr(0, index);
                    stringstream ss(temp);
                    ss >> hiddenWeights[k];
                    line.erase(0, index+1);
                }
                stringstream ss(line);
                ss >> hiddenWeights[numNeuronsInPrevLayer-1];

                hiddenNeurons[j] = new HiddenNeuron(numNeuronsInPrevLayer, hiddenWeights);
            }
            this->hiddenLayers[i] = new HiddenLayer(numNeuronsInLayer, hiddenNeurons, tempActivation);
            numNeuronsInPrevLayer = numNeuronsInLayer;
        }

        getline(inFile, line);

        double* outputWeights = new double[numNeuronsInPrevLayer];
        getline(inFile, line);
        for (int j = 0; j < numNeuronsInPrevLayer-1; ++j)
        {
                index = line.find(' ');
                temp = line.substr(0, index);
                stringstream ss(temp);
                ss >> outputWeights[j];
                line.erase(0, index+1);
        }
        stringstream ss(line);
        ss >> outputWeights[numNeuronsInPrevLayer-1];

        this->outputLayer = new OutputLayer(numNeuronsInPrevLayer, outputWeights);
    }
}

NeuralNetwork::~NeuralNetwork()
{
    delete this->inputLayer;
    inputLayer = NULL;

    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        delete this->hiddenLayers[i];
        this->hiddenLayers[i] = NULL;
    }
    delete[] hiddenLayers;
    this->hiddenLayers = NULL;

    delete this->outputLayer;
    this-> outputLayer = NULL;
}

double NeuralNetwork::forward(double* input)
{
    inputLayer->setInputs(input);
    hiddenLayers[0]->forward(inputLayer);

    for (int i = 1; i < numHiddenLayers; ++i)
    {
        hiddenLayers[i]->forward(hiddenLayers[i-1]);
    }

    outputLayer->forward(hiddenLayers[numHiddenLayers-1]);
    return outputLayer->getOutputValue();
}

void NeuralNetwork::printNetwork()
{
    this->inputLayer->printLayer();
    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        this->hiddenLayers[i]->printLayer();
    }
    this->outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    this->inputLayer->clearLayer();
    for (int i = 0; i < this->numHiddenLayers; ++i)
    {
        this->hiddenLayers[i]->clearLayer();
    }
    this->outputLayer->clearLayer();
}
