output: main.o cauldron.o ingredient.o
	g++ main.o drone.o factory.o -o output

main.o: main.cpp
	g++ -c main.cpp

cauldron.o: cauldron.cpp cauldron.h
	g++ -c cauldron.cpp

ingredient.o: ingredient.cpp ingredient.h
	g++ -c factory.cpp

run:
	./output

clean:
	rm *.o output
