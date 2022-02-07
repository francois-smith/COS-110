output:  tome.o main.o
	g++ tome.o main.o output

tome.o: tome.cpp tome.h
	g++ -c tome.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output