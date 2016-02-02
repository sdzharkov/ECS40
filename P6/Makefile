./simulator.out : airport.o city.o main.o plane.o
	g++ -ansi -Wall -g -o ./simulator.out airport.o city.o main.o plane.o  

airport.o : airport.cpp airport.h city.h list.h
	g++ -ansi -Wall -g -c airport.cpp

city.o : city.cpp city.h 
	g++ -ansi -Wall -g -c city.cpp 

main.o : main.cpp list.h airport.h plane.h 
	g++ -ansi -Wall -g -c main.cpp 

plane.o : plane.cpp plane.h 
	g++ -ansi -Wall -g -c plane.cpp 

clean : 
	rm -f ./simulator.out airport.o  city.o  main.o  plane.o   
