#ifndef VECTOR_H
#define	VECTOR_H
// Author Sean Davis

#include "city.h"

typedef struct
{
  City *cityArray;
  int size;
  int count;
} Vector;

void initialize(Vector *cities);
void deallocate(Vector *cities);
void calcDistance(const Vector *cities, int index1, int index2);
void cleanCities(Vector *cities);
int findAirport(const Vector *cities, const char *airport);
void readAirports(Vector *cities);
void readCities(Vector *cities);
void resize(Vector *cities);

#endif	// VECTOR_H 

