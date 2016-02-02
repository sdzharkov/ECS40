simulator.out : itemList.o item.o main.o 
	g++ -ansi -Wall -g -o simulator.out itemList.o item.o main.o 

itemList.o : itemList.cpp itemList.h 
	g++ -ansi -Wall -g -c itemList.cpp 
	
item.o : item.cpp item.h 
	g++ -ansi -Wall -g -c item.cpp

main.o : main.cpp 
	g++ -ansi -Wall -g -c main.cpp 

clean : 
	rm -f simulator.out itemList.o item.o main.o  
