output: piece.o board.o solver.o main.o
	g++ piece.o board.o solver.o main.o output

piece.o: piece.cpp piece.h
	g++ -c piece.cpp

board.o: board.cpp board.h
	g++ -c board.cpp

solver.o: solver.cpp solver.h
	g++ -c solver.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output
