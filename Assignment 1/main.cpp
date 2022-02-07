#include "NeuralNetwork.h"

int main()
{
    NeuralNetwork* neuralNetwork = new NeuralNetwork("mean.txt");

    double* input = new double[5];
    input[0] = 5.0;
    input[1] = 10.0;
    input[2] = 15.0;
    input[3] = 20.0;
    input[4] = 25.0;
    cout << setprecision(15) << neuralNetwork->forward(input) << endl;

    delete neuralNetwork;
    return 0;
}