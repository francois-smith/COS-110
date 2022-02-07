output = main.o dispatch.o dList.o trainCar.o train.o
gpp_o = g++ -c -std=c++98 -static

main: $(output)
			g++ -std=c++98 -static $(output) -o main

main.o: main.cpp dispatch.cpp dispatch.h dList.cpp dList.h train.cpp train.h trainCar.cpp trainCar.h
			$(gpp_o) main.cpp

dispatch.o: dispatch.cpp dispatch.h
			$(gpp_o) dispatch.cpp

dList.o: dList.cpp dList.h
			$(gpp_o) dList.cpp

trainCar.o: trainCar.cpp trainCar.h
			$(gpp_o) trainCar.cpp

train.o: train.cpp train.h
			$(gpp_o) train.cpp

run: main
			./main

clean:
			rm *.o main