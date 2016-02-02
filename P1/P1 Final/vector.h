#ifndef VECTOR_H
#define	VECTOR_H
// Author Sean Davis

#include "city.h"
using namespace std;

class Vector
{
  City *cityArray;
  int size;
  int count;
void resize();
public:
//initialize();
//void deallocate();
Vector();
~Vector();
void cleanCities();
int findAirport(const char *airport) const;//does this have a const?
void readAirports();
void readCities();
void calcDistance(int index1, int index2) const;
};
#endif	// VECTOR_H 

