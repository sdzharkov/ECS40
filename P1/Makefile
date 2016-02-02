simulator.out: main.o city.o vector.o
	g++ -ansi -Wall -g -o simulator.out main.o city.o vector.o
	
main.o: city.h vector.h main.cpp
	g++ -ansi -Wall -g -c -o main.o main.cpp

city.o: city.h vector.h city.cpp
	g++ -ansi -Wall -g -c -o city.o city.cpp
	
vector.o: city.h vector.h vector.cpp
	g++ -ansi -Wall -g -c -o vector.o vector.cpp

clean:
	rm *.o *.out
