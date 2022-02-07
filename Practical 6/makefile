output:  trolley.o main.o
	g++ main.o trolley.o -o output

trolley.o: trolley.cpp trolley.h
	g++ -c trolley.cpp

main.o: main.cpp train.cpp train.h manager.cpp manager.h
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output
