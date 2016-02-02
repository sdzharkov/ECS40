#ifndef CITY_H
  #define CITY_H

typedef struct city
{
  bool valid;
  double longitude;
  double latitude;
  char* name;
  char* state;
  char airport[3 + 1];
  int population;
} //
City;

void initialize(City *cityPtr);
void deallocate(City *city);
void readCityfile(City *cityPtr, char* strPtr);
void readAirport(City *cityPtr, char* myFile);
bool isEqual(const City *cityPtr, const City *citytemp);
void copyLocation(City *cityArray, const City *citytemp);
bool hasAirport(City *cityArray);
void setAirport(City *newTemp, const char *city1);
void calcDistance(const City *city, const City *city2);
double deg2rads(double num);
#endif
