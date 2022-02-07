output: main.o drone.o factory.o
	g++ main.o drone.o factory.o -o output

main.o: main.cpp
	g++ -c main.cpp

drone.o: drone.cpp drone.h
	g++ -c drone.cpp

factory.o: factory.cpp factory.h
	g++ -c factory.cpp

run:
	./output

clean:
	rm *.o output
