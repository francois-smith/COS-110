output: HiddenLayer.o HiddenNeuron.o InputLayer.o OutputLayer.o NeuralNetwork.o main.o
	-std=c++98 g++ HiddenLayer.o HiddenNeuron.o InputLayer.o OutputLayer.o NeuralNetwork.o main.o -o output

HiddenLayer.o: HiddenLayer.cpp HiddenLayer.h
	-std=c++98 g++ -c HiddenLayer.cpp

HiddenNeuron.o: HiddenNeuron.cpp HiddenNeuron.h
	-std=c++98 g++ -c HiddenNeuron.cpp

InputLayer.o: InputLayer.cpp InputLayer.h
	-std=c++98 g++ -c InputLayer.cpp

OutputLayer.o: OutputLayer.cpp OutputLayer.h
	-std=c++98 g++ -c OutputLayer.cpp

NeuralNetwork.o: NeuralNetwork.cpp NeuralNetwork.h
	-std=c++98 g++ -c NeuralNetwork.cpp

main.o: main.cpp
	-std=c++98 g++ -c main.cpp

run:
	./output

clean:
	rm *.o output
