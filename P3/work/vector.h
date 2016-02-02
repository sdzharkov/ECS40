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
public:
void resize();
Vector();
~Vector();
void cleanCities();
int findAirport(const char *airport) const;
void readAirports();
void readCities();
void calcDistance(int index1, int index2) const;
void calcAirportTraffic(int index) const;
}; //
#endif	// VECTOR_H 

