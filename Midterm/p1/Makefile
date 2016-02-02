mid.out: main.o booklist.o
	g++ -Wall -ansi -o mid.out main.o booklist.o

booklist.o: booklist.cpp booklist.h
	g++ -Wall -ansi -c -g booklist.cpp




main.o: main.cpp  
	g++ -Wall -ansi -c -g main.cpp




clean:
	rm -f mid.out main.o booklist.o
