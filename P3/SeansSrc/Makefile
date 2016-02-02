simulator.out: city.o main.o vector.o
	g++ -Wall -g -ansi -o simulator.out city.o main.o vector.o 

city.o: city.cpp city.h 
	g++ -Wall -g -ansi -c city.cpp

main.o: main.cpp vector.h 
	g++ -Wall -g -ansi -c main.cpp

vector.o: vector.cpp vector.h city.h 
	g++ -Wall -g -ansi -c vector.cpp

clean:
	rm -f simulator.out city.o main.o vector.o 

