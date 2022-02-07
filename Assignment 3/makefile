ofiles = main.o Controller.o ControllerException.o DisplacementException.o OverflowException.o RotateException.o UnderflowException.o Babushka.o BlueBabushka.o DarkBlueBabushka.o LightBlueBabushka.o GoldBabushka.o GreenBabushka.o YellowBabushka.o RedBabushka.o
gpp_o = g++ -c -std=c++98 -static 

main: $(ofiles)
	g++ -std=c++98 -static $(ofiles) -o main

main.o: main.cpp Controller.h ControllerException.h
	$(gpp_o) main.cpp

Controller.o: Controller.cpp
	$(gpp_o) Controller.cpp

ControllerException.o: ControllerException.cpp
	$(gpp_o) ControllerException.cpp

DisplacementException.o: DisplacementException.cpp
			$(gpp_o) DisplacementException.cpp

OverflowException.o: OverflowException.cpp
			$(gpp_o) OverflowException.cpp

RotateException.o: RotateException.cpp
			$(gpp_o) RotateException.cpp

UnderflowException.o: UnderflowException.cpp
			$(gpp_o) UnderflowException.cpp

Babushka.o: Babushka.cpp
			$(gpp_o) Babushka.cpp

BlueBabushka.o: BlueBabushka.cpp
			$(gpp_o) BlueBabushka.cpp

DarkBlueBabushka.o: DarkBlueBabushka.cpp
			$(gpp_o) DarkBlueBabushka.cpp

LightBlueBabushka.o: LightBlueBabushka.cpp
			$(gpp_o) LightBlueBabushka.cpp

GoldBabushka.o: GoldBabushka.cpp
			$(gpp_o) GoldBabushka.cpp

GreenBabushka.o: GreenBabushka.cpp
			$(gpp_o) GreenBabushka.cpp

YellowBabushka.o: YellowBabushka.cpp
			$(gpp_o) YellowBabushka.cpp

RedBabushka.o: RedBabushka.cpp
			$(gpp_o) RedBabushka.cpp

run: main
	./main
	
clean:
	rm *.o main
