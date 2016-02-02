simulator.out: city.o main.o citylist.o plane.o
	g++ -Wall -ansi -o simulator.out city.o main.o citylist.o plane.o 

city.o: city.cpp city.h 
	g++ -Wall -ansi -c city.cpp

main.o: main.cpp citylist.h 
	g++ -Wall -ansi -c main.cpp

citylist.o: citylist.cpp citylist.h city.h 
	g++ -Wall -ansi -c citylist.cpp

plane.o: plane.cpp plane.h
	g++ -Wall -ansi -c plane.cpp

clean:
	rm -f simulator.out city.o main.o citylist.o plane.o 
