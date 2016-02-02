#ifndef CITY_H
#define	CITY_H
// Author: Sean Davis
#include <iostream>
using namespace std;

class City
{
//public:
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
void readAirport(char *line, char *stat);
void readCity(ifstream& fp);
void setAirport(const char *airport);
char* getName() {return name; };
char* getState() {return state; };
char* getAirport() {return airport; };
int getLong() {return longitude; };
int getLat() {return latitude; };
int getPop() {return population; };
}; //
#endif	// CITY_H 

