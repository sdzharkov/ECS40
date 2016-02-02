#ifndef CITY_H
#define	CITY_H
// Author: Sean Davis
#include <iostream>
using namespace std;

class City
{
  double longitude;
  double latitude;
  char *name;
  char *state;
  char airport[4];
  int population;

public:
City();
~City();
City & operator = (const City &rhs);
void deallocate();
void calcDistance(const City *city1, const City *city2) const;
void copyLocation(const City *srcCity);
bool hasAirport();
bool isEqual(const City *city2) const;
void readAirport(char *line);
void readCity(ifstream& fp);
void setAirport(const char *airport);
};
#endif	// CITY_H 

