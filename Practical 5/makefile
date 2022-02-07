output:  component.o locomotive.o main.o passenger.o train.o
	g++ component.o locomotive.o main.o passenger.o train.o output

component.o: component.cpp component.h
	g++ -c component.cpp

locomotive.o: locomotive.cpp locomotive.h
	g++ -c locomotive.cpp

passenger.o: passenger.cpp passenger.h
	g++ -c passenger.cpp

train.o: train.cpp train.h
	g++ -c train.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output