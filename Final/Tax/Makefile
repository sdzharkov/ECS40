a.out: main.o TaxPayers.o TaxForm.o TaxFormD.o
	g++ -Wall -ansi -g -lm -o a.out main.o TaxPayers.o TaxForm.o TaxFormD.o

main.o: main.cpp
	g++ -Wall -ansi -g -c main.cpp

TaxPayers.o: TaxPayers.cpp TaxPayers.h
	g++ -Wall -ansi -g -c TaxPayers.cpp

TaxForm.o: TaxForm.cpp TaxForm.h
	g++ -Wall -ansi -g -c TaxForm.cpp

TaxFormD.o: TaxFormD.cpp TaxFormD.h
	g++ -Wall -ansi -g -c TaxFormD.cpp

clean:
	rm -f a.out *.o
