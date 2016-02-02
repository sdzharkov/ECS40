a.out : main.o results.o normal.o multiple.o 
	 g++ -ansi -Wall -g -o a.out main.o results.o normal.o multiple.o 

main.o : main.cpp results.h
	 g++ -ansi -Wall -g -c main.cpp

results.o : results.cpp ListNode.h results.h normal.h multiple.h
	 g++ -ansi -Wall -g -c results.cpp

normal.o : normal.cpp normal.h trial.h
	 g++ -ansi -Wall -g -c normal.cpp

multiple.o : multiple.cpp multiple.h trial.h
	 g++ -ansi -Wall -g -c multiple.cpp

clean :
	rm -f a.out main.o results.o normal.o multiple.o 
