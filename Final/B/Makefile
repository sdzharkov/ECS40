a.out : main.o result.o trial.o 
	g++ -ansi -Wall -g -o a.out main.o result.o trial.o 

main.o : main.cpp 
	g++ -ansi -Wall -g -c main.cpp 

result.o : result.cpp 
	g++ -ansi -Wall -g -c result.cpp 

trial.o : trial.cpp 
	g++ -ansi -Wall -g -c trial.cpp 

clean : 
	rm -f a.out main.o  result.o  trial.o  
