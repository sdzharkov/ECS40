simulator.out : city.o main.o plane.o vector.o  
	g++ -ansi -Wall -g -o simulator.out city.o main.o plane.o vector.o  

city.o : city.cpp city.h 
	g++ -ansi -Wall -g -c city.cpp

main.o : main.cpp vector.h plane.h 
	g++ -ansi -Wall -g -c main.cpp

plane.o : plane.cpp 
	g++ -ansi -Wall -g -c plane.cpp

vector.o : vector.cpp vector.h 
	g++ -ansi -Wall -g -c vector.cpp

clean : 
	rm -f simulator.out city.o  main.o  plane.o  vector.o   
