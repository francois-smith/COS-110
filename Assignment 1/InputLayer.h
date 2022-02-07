#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include <sstream>

class InputLayer
{
      private:
            int numInputs;
            double* inputs;
      public:
            InputLayer(int numInputs);
            ~InputLayer();
            double* getInputs();
            int getNumInputs();
            void setInputs(double* inputs);
            void setNumInputs(int numInputs);
            void printLayer();
            void clearLayer();
};
#endif
